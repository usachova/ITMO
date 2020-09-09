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
    freopen("deletion.in", "r", stdin);
    freopen("deletion.out", "w", stdout);
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
		if (le[i] != 0) root = insertwb(root, mas[le[i]]);
		if (ri[i] != 0) root = insertwb(root, mas[ri[i]]);
	}
	cin >> k;
	n--;
	root = remove(root, k);
	go(root);
	cout << arr.size() << endl;
	for (int i = 1; i <= n; i++) {
		cout << arr[i - 1] << " " << lf[arr[i - 1]] << " " << rg[arr[i - 1]] << endl;
	}
	return 0;
}
