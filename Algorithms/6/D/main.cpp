#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <map>

using namespace std;

struct q_node {
	int val;
	q_node * next = nullptr;
};

struct queue {
	q_node * first = nullptr;
	q_node * last = nullptr;
	int size = 0;
};

int limit = 65535;

int queue_get(queue * q) {
	int val;
	if (q->size == 1) {
		val = q->first->val;
		delete q->first;
		q->first = nullptr;
		q->last = nullptr;
		q->size = 0;
		return val & limit;
	}
	val = q->first->val;
	q_node * change = q->first->next;
	delete q->first;
	q->first = change;
	if (q->size == 2) q->last = change;
	q->size--;
	return val & limit;
}
void queue_put(queue * q, int val) {
	val = val & limit;
	if (q->size == 0) {
		q->first = new q_node;
		q->first->val = val;
		q->last = q->first;
		q->size = 1;
		return;
	}
	q_node * last = q->last;
	last->next = new q_node;
	last->next->val = val;
	q->last = last->next;
	q->size++;
}

int main() {
	freopen("quack.in", "r", stdin);
	freopen("quack.out", "w", stdout);
	queue que;
	map<string, int> label_list;
	map<char, int> reg_list;
	for (char name = 'a'; name <= 'z'; name++) reg_list[name] = 0;
	int pos = 0, f_size = 0;
	string arr[1000000];
	while (cin >> arr[f_size]) f_size++;
	string str;
	while (pos <= f_size) {
		str = arr[pos++];
		if (str[0] == ':') {
			string name = str.substr(1, str.length() - 1);
			label_list[name] = pos;
		}
	} 
	pos = 0;
	while (pos <= f_size) {
		int val, val1, val2, x, y, numb;
		str = arr[pos++];
		switch (str[0]) {
			case '+':
				numb = queue_get(&que) + queue_get(&que);
				queue_put(&que, numb);
				break;
			case '-':
				numb = queue_get(&que) - queue_get(&que);
				queue_put(&que, numb);
				break;
			case '*':
				numb = queue_get(&que) * queue_get(&que);
				queue_put(&que, numb);
				break;	
			case '/':
				x = queue_get(&que);
				y = queue_get(&que);
				if (y == 0) numb = 0;
				else numb = x / y;
				queue_put(&que, numb);
				break;
			case '%':
				x = queue_get(&que);
				y = queue_get(&que);
				if (y == 0) numb = 0;
				else numb = x % y;
				queue_put(&que, numb);
				break;
			case '>':
				val = queue_get(&que);
				val = val & limit;
				reg_list[str[1]] = val;
				break;
			case '<':
				val = reg_list[str[1]] & limit;
				queue_put(&que, val);
				break;					
			case 'P':
				if (str.length() > 1) {
					val = reg_list[str[1]] & limit;
					cout << val << endl;
				}
				else {
					cout << queue_get(&que) << endl;
				}
				break;
			case 'C':
				if (str.length() > 1) {
					val = reg_list[str[1]] & limit;
					cout << (char)(val % 256);
				}
				else {
					cout << (char)(queue_get(&que) % 256);
				}
				break;
			case ':':
				break;
			case 'J':
				pos = label_list[str.substr(1, str.length() - 1)];
				break;
			case 'Z':
				val = reg_list[str[1]] & limit;
				if (val == 0) {
					pos = label_list[str.substr(2, str.length() - 2)];
				}
				break;
			case 'E':
				val1 = reg_list[str[1]] & limit;
				val2 = reg_list[str[2]] & limit;
				if (val1 == val2) {
					pos = label_list[str.substr(3, str.length() - 3)];
				}
				break;
			case 'G':
				val1 = reg_list[str[1]] & limit;
				val2 = reg_list[str[2]] & limit;
				if (val1 > val2) {
					pos = label_list[str.substr(3, str.length() - 3)];
				}
				break;
			case 'Q':
				break;
			default:
				numb = atoi(str.c_str());
				queue_put(&que, numb);
		}
	} 
	return 0;
} 
