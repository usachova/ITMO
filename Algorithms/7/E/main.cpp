#include <iostream>
#include <cstdio>
#include <fstream>
#include <cmath>
#include <vector>
#include <map>

using namespace std;

struct node {
	int key;
	int h;
	node* l;
	node* r;
	node(int k) {
		key = k;
		l = r = nullptr;
		h = 1;
	}
};

int height(node* t) {
	return t ? t->h : 0;
}

int bal(node* t) {
	return height(t->r) - height(t->l);
}

node* rotateright(node* t) {
	node* q = t->l;
	t->l = q->r;
	q->r = t;
	t->h = (height(t->r) > height(t->l) ? height(t->r) : height(t->l)) + 1;
	q->h = (height(q->r) > height(q->l) ? height(q->r) : height(q->l)) + 1;
	return q;
}

node* rotateleft(node* t) {
	node* q = t->r;
	t->r = q->l;
	q->l = t;
	t->h = (height(t->r) > height(t->l) ? height(t->r) : height(t->l)) + 1;
	q->h = (height(q->r) > height(q->l) ? height(q->r) : height(q->l)) + 1;
	return q;
}

node* balance(node* t) {
	t->h = (height(t->r) > height(t->l) ? height(t->r) : height(t->l)) + 1;
	if (bal(t) == 2) {
		if (bal(t->r) < 0) t->r = rotateright(t->r);
		return rotateleft(t);
	}
	if (bal(t) == -2) {
		if (bal(t->l) > 0) t->l = rotateleft(t->l);
		return rotateright(t);
	}
	return t;
}

node* insert(node* t, int x) {
	if (!t) return new node(x);
	if (x < t->key) t->l = insert(t->l, x);
	else if (x > t->key) t->r = insert(t->r, x);
	return balance(t);
}

node* findmax(node* t) {
	return t->r ? findmax(t->r) : t;
}

node* removemax(node* t) {
	if (!t->r) return t->l;
	t->r = removemax(t->r);
	return balance(t);
}

node* remove(node* t, int k) {
	if (!t) return 0;
	if (k < t->key) t->l = remove(t->l, k);
	else if (k > t->key) t->r = remove(t->r, k);
	else {
		node* lt = t->l;
		node* rt = t->r;
		delete t;
		if (!lt) return rt;
		node* m = findmax(lt);
		m->l = removemax(lt);
		m->r = rt;
		return balance(m);
	}
	return balance(t);
}

bool find(node* t, int x) {
	if (!t) return false;
	if (t->key == x) return true;
	if (x < t->key) return find(t->l, x);
	else return find(t->r, x);
}

int main() {
    freopen("avlset.in", "r", stdin);
    freopen("avlset.out", "w", stdout);
    //ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	node* root = nullptr;
	for (int i = 0; i < n; i++) {
		char ch; 
		cin >> ch;
		int k;
		cin >> k;
		if (ch == 'A') {
			root = insert(root, k);
			cout << bal(root) << endl;
		}
		if (ch == 'D') {
			root = remove(root, k);
			if (root) cout << bal(root) << endl;
			else cout << "0" << endl;
		}
		if (ch == 'C') {
			if (root && find(root, k)) cout << "Y" << endl;
			else cout << "N" << endl;
		}
	}
	return 0;
}
