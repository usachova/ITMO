#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <utility>

using namespace std;

struct tree {
    struct Node {
    	int k;
        Node *l , *r;
        
        Node(int x) {
        	k = x;
            l = nullptr;
            r = nullptr;
        }
    };
 
    Node *root = nullptr;

	void add(int x) {
		if (root == nullptr) {
			root = new Node(x);
			return;
		}
		Node *cur = root;
		while (cur) {
			if (x < cur->k) {
				if (cur->l == nullptr) {
					cur->l = new Node(x);
					return;
				}
				else cur = cur->l;
			}
			else if (x > cur->k) {
				if (cur->r == nullptr) {
					cur->r = new Node(x);
					return;
				}
				else cur = cur->r;
			}
			else return;
		}
		return;
	}

	bool exists(int x) {
		Node *cur = root;
		while (cur) {
			if (x < cur->k) cur = cur->l;
			else if (x > cur->k) cur = cur->r;
			else return true;
		}
		return false;
	}
	
	void del(int x) {
		Node *cur = root, *par = nullptr;
		bool flag = false;
		while (cur) {
			if (x < cur->k) {
				par = cur;
				cur = cur->l;
				flag = true;
			}
			else if (x > cur->k) {
				par = cur;
				cur = cur->r;
				flag = false;
			}
			else break;
		}
		if (cur == nullptr) return;
		if (cur->k != x) return;
		if (cur->l != nullptr) {
			Node* tmp = cur->l;
			while(tmp->r != nullptr) tmp = tmp->r;
			tmp->r = cur->r;
			cur = cur->l;
		}
		else cur = cur->r;
		if (par != nullptr) {
            if (flag) par->l = cur;
            else par->r = cur;
        } 
		else root = cur;
	}
	
	void go(Node* node) {
		if (node == nullptr) return;
		go(node->l);
		cout << node->k << " ";
		go(node->r);
	}

	int next(int x) {
		Node *cur = root;
		int ans = 1000000001;
		while (cur) {
			if (x < cur->k) {
				ans = cur->k;
				if (cur->l == nullptr) return ans;
				cur = cur->l;
			}
			else {
				if (cur->r == nullptr) return ans;
				cur = cur->r; 
			}
		}
		return ans;
	}	

	int prev(int x) {
		Node *cur = root;
		int ans = 1000000001;
		while (cur) {
			if (x <= cur->k) {
				if (cur->l == nullptr) return ans;
				cur = cur->l;
			}
			else {
				ans = cur->k;
				if (cur->r == nullptr) return ans;
				cur = cur->r; 
			}
		}
		return ans;
	}
	
};

int main() {
	freopen("bstsimple.in", "r", stdin);
	freopen("bstsimple.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	string str;
	tree tr;
	while (cin >> str) {
		int key;
		cin >> key;
		if (str == "insert") tr.add(key);
		if (str == "delete") tr.del(key);
		if (str == "exists") {
			if (tr.exists(key)) cout << "true" << endl;
			else cout << "false" << endl;
		}
		if (str == "next") {
			int ans = tr.next(key);
			if (ans == 1000000001) cout << "none" << endl;
			else cout << ans << endl;
		}
		if (str == "prev") {
			int ans = tr.prev(key);
			if (ans == 1000000001) cout << "none" << endl;
			else cout << ans << endl;
		}
	}
	return 0;
}
