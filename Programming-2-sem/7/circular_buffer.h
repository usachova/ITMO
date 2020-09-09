#pragma once
#include <iostream>
#include <iterator>

template<typename Buff,typename Tp, typename Distance = ptrdiff_t, typename Pointer = Tp*, typename Reference = Tp&>
class iterator : public std::iterator<std::random_access_iterator_tag, Tp> {
private:
    Buff* buff;
    int index_;

public:
    typedef typename std::iterator<std::random_access_iterator_tag, Tp, Distance, Pointer, Reference> base_iterator;

    typedef typename std::random_access_iterator_tag    iterator_category;
    typedef typename base_iterator::value_type          value_type;
    typedef typename base_iterator::difference_type     difference_type;
    typedef typename base_iterator::pointer             pointer;
    typedef typename base_iterator::reference           reference;

    iterator(const iterator&) = default;
    ~iterator() = default;
    iterator(Buff& buff, int index) : buff(&buff), index_(index) {}

    iterator& operator=(const iterator& it) {
        buff = it.buff;
        index_ = it.index_;
        return *this;
    }

    Tp& operator*() {
        return (*buff)[index_];
    }

    Tp* operator->() {
        return &(*buff)[index_];
    }


    friend bool operator==(const iterator& it1, const iterator& it2) {
        return it1.index_ == it2.index_;
    }

    friend bool operator!=(const iterator& it1, const iterator& it2) {
        return it1.index_ != it2.index_;
    }

    friend bool operator>=(const iterator& it1, const iterator& it2) {
        return it1.index_ >= it2.index_;
    }

    friend bool operator>(const iterator& it1, const iterator& it2) {
        return it1.index_ > it2.index_;
    }

    friend bool operator<=(const iterator& it1, const iterator& it2) {
        return it1.index_ <= it2.index_;
    }

    friend bool operator<(const iterator& it1, const iterator& it2) {
        return it1.index_ < it2.index_;
    }


    iterator operator++() {
        return iterator(*buff, ++index_);
    }

    iterator operator++(int) {
        return iterator(*buff, index_++);
    }

    iterator operator--() {
        return iterator(*buff, --index_);
    }

    iterator operator--(int) {
        return iterator(*buff, index_--);
    }


    friend iterator operator+(const iterator& it, const int n) {
        return iterator(*it.buff, it.index_ + n);
    }

    friend iterator operator+(const int n, const iterator& it) {
        return it + n;
    }

    friend int operator+(const iterator& it1, const iterator& it2) {
        return it1.index_ + it2.index_;
    }

    friend iterator operator-(const iterator& it, const int n) {
        return it + (-n);
    }

    friend int operator-(const iterator& it1, const iterator& it2) {
        return it1.index_ - it2.index_;
    }
    iterator operator+=(const int n) {
        return iterator(*this->buff, this->index_ + n);
    }

    iterator operator-=(const int n) {
        return iterator(*this->buff, this->index_ - n);
    }
};

template <typename T>
class circularBuffer {
private:
    int capacity_;
    int size_;
    T* begin_;
    int num_;

public:
    circularBuffer() {
        capacity_ = 0;
        size_ = 0;
        begin_ = nullptr;
        num_ = 0;
    }

    circularBuffer(int n) {
        capacity_ = n;
        size_ = 0;
        begin_ = new T[capacity_];
        num_ = 0;
    }

    ~circularBuffer() {
        delete [] begin_;
    }

    typedef iterator< circularBuffer<T>, T> iterator;

    T &operator[](int index) {
        return *(begin_ + (num_ + index) % capacity_);
    }

    iterator begin() {
        return iterator(*this, 0);
    }

    iterator end() {
        return iterator(*this, size_);
    }


    void insertBegin(T element) {
        if (size_ == capacity_) std::cout << "buffer is full" << std::endl;
        else {
            num_ = (num_ - 1 + capacity_) % capacity_;
            begin_[num_] = element;
            size_++;
        }
    }

    void deleteBegin() {
        if (size_ == 0) std::cout << "buffer is empty" << std::endl;
        else {
            size_--;
            num_ = (num_ + 1 + capacity_) % capacity_;
        }
    }

    void insertEnd(T element) {
        if (size_ == capacity_) std::cout << "buffer is full" << std::endl;
        else {
            int new_num = (num_ + size_ + capacity_) % capacity_;
            begin_[new_num] = element;
            size_++;
        }
    }

    void deleteEnd() {
        if (size_ == 0) std::cout << "buffer is empty" << std::endl;
        else {
            size_--;
        }
    }

    void insertIt(iterator&& it, T element) {
        if (it > end()) std::cout << "insert after end!" << std::endl;
        else {
            insertEnd(*(end() - 1));
            iterator&& temp = end() - 2;
            while (temp != it) {
                *temp = *(temp - 1);
                temp = temp - 1;
            }
            *it = element;
        }
    }

    void deleteIt(iterator&& it) {
        if (it >= end()) std::cout << "delete after end!" << std::endl;
        else {
            while (it != end() - 1) {
                *it = *(it + 1);
                it = it + 1;
            }
            deleteEnd();
        }
    }


    void changeCap(int value) {
        if (value < size_) std::cout << "too little space!" << std::endl;
        else {
            T* new_begin = new T[value];
            int i = num_, j = 0;
            for (; i < capacity_ && j < size_; i++, j++) {
                new_begin[j]= begin_[i];
            }
            for (i = 0; i < (num_ + size_ - 1 + capacity_ ) % capacity_ && j < size_; i++, j++) {
                new_begin[j] = begin_[i];
            }
            num_ = 0;
            capacity_ = value;
            begin_ = new_begin;
        }
    }

};