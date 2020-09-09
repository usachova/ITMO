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
	//node* p;
	node(int k) {
		key = k;
		//l = r = p = nullptr;
		l = r = 0;
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

/*void insert(node* root, int x) {
	if (root == nullptr) {
		root = new node(x);
		return;
	}
	node* cur = root;
	while (cur) {
		if (x < cur->key) {
			if (cur->l == nullptr) {
				cur->l = new node(x);
				cur->l->p = cur;
				return;
			}
			else cur = cur->l;
		}
		else if (x > cur->key) {
			if (cur->r == nullptr) {
				cur->r = new node(x);
				cur->r->p = cur;
				return;
			}
			else cur = cur->r;
		}
		else return;
	}
	return;
}*/

node* insert(node* t, int x) {
	if (!t) return new node(x);
	if (x < t->key) t->l = insert(t->l, x);
	else t->r = insert(t->r, x);
	return balance(t);
}

node* insertwb(node* t, int x) {
	if (!t) return new node(x);
	if (x < t->key) t->l = insertwb(t->l, x);
	else t->r = insertwb(t->r, x);
	t->h = (height(t->r) > height(t->l) ? height(t->r) : height(t->l)) + 1;
	return t;
}

vector<int> arr;
map<int, int> lf, rg;
void go(node* t) {
	if (!t) return;
	arr.push_back(t->key);
	if (t->l) {
		lf[t->key] = arr.size() + 1;
	}
	else lf[t->key] = 0;
	go(t->l);
	if (t->r) {
		rg[t->key] = arr.size() + 1;
	}
	else rg[t->key] = 0;
	go(t->r);
}

int main() {
    freopen("addition.in", "r", stdin);
    freopen("addition.out", "w", stdout);
    //ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int l, r, k;
	int mas[n + 1], le[n + 1], ri[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> k >> l >> r;
		mas[i] = k;
		le[i] = l;
		ri[i] = r;
	}
	node* root;
	if (n > 0) root = new node(mas[1]);
	for (int i = 1; i <= n; i++) {
		//if (le[i] != 0) root = insert(root, mas[le[i]]);
		//if (ri[i] != 0) root = insert(root, mas[ri[i]]);
		if (le[i] != 0) root = insertwb(root, mas[le[i]]);
		if (ri[i] != 0) root = insertwb(root, mas[ri[i]]);
		/*if (le[i] == 0 && ri[i] == 0) {
			node* cur = root;
			while (cur) {
				if (mas[i] < cur->key) cur = cur->l;
				else if (mas[i] > cur->key) cur = cur->r;
				else break;
			}
			while (cur != nullptr && cur->p != nullptr) {
				if (cur->p->h <= cur->h) cur->p->h = cur->h + 1;
				cur = cur->p;
			}
		}*/
	}
	cin >> k;
	n++;
	if (n == 1) root = new node(k);
	else root = insert(root, k);
	/*else insert(root, k);
	node* cur = root;
	while (cur) {
		if (k < cur->key) cur = cur->l;
		else if (k > cur->key) cur = cur->r;
		else break;
	}
	node* temp = cur;
	while (cur != nullptr && cur->p != nullptr) {
		if (cur->p->h <= cur->h) cur->p->h = cur->h + 1;
		cur = cur->p;
	}
	cur = temp;
	while (cur != nullptr && cur->p != nullptr) {
		cur = balance(cur);
	}
	root = balance(root);*/
	go(root);
	cout << arr.size() << endl;
	for (int i = 1; i <= n; i++) {
		cout << arr[i - 1] << " " << lf[arr[i - 1]] << " " << rg[arr[i - 1]] << endl;
	}
	return 0;
}
