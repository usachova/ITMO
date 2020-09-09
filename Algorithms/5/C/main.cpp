#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <utility>
#include <fstream>

#define int long long

using namespace std;

const int p = 89, m = 1994567;

struct strinthashmap {
	vector<pair<string, int> > arr[m];
	
	strinthashmap() {
		for (int i = 0; i < m; i++) arr[i] = {};
	}
	
	int gethash(string key) {
		long long step = p;
		long long sum = 0;
		for (int i = 0; i < key.length(); i++) {
			sum += ((key[i] - 'a' + 1) * step) % m;
			sum %= m;
			step *= p;
			step %= m;
		}
		sum = abs(sum);
		sum %= m;
		return sum;
	}
	
	void put(string key, int ps) {
		int y = gethash(key);
        for(int i = 0; i < arr[y].size(); i++) {
            if(arr[y][i].first == key) {
                arr[y][i].second = ps;
                return;
            }
    	}
        arr[y].push_back(make_pair(key, ps));
	}
	
	int get(string key) {
		int y = gethash(key);
        for (int i = 0; i < arr[y].size(); i++) if(arr[y][i].first == key) return arr[y][i].second;
        return -1;
	}
};

vector<string> keys;
strinthashmap* pos;

struct hashmap {
	vector<pair<string, string> > arr[m];
	
	hashmap() {
		for (int i = 0; i < m; i++) arr[i] = {};
	}
	
	int gethash(string key) {
		long long step = p;
		long long sum = 0;
		for (int i = 0; i < key.length(); i++) {
			sum += ((key[i] - 'a' + 1) * step) % m;
			sum %= m;
			step *= p;
			step %= m;
		}
		sum = abs(sum);
		sum %= m;
		return sum;
	}
	
	void put(string key, string val) {
        int y = gethash(key);
        if(pos->get(key) == -1) {
            pos->put(key, keys.size());
            keys.push_back(key);
        }
        for(int i = 0; i < arr[y].size(); i++) {
        	if (arr[y][i].first == key) {
        		arr[y][i].second = val;
        		return;
			}
		}
        arr[y].push_back(make_pair(key, val));
    }
    
    int fndflag(string key) {
    	int y = gethash(key);
		for (int i = 0; i < arr[y].size(); i++) if (arr[y][i].first == key) return i;
		return -1;
	}
	
	string get(string key) {
		if (fndflag(key) == -1) return "none";
		int y = gethash(key);
		for (int i = 0; i < arr[y].size(); i++) if(arr[y][i].first == key) return arr[y][i].second;
        return "none";
	}
	
	void del(string key) {
		if (fndflag(key) == -1) return;
		int y = gethash(key);
		if (arr[y].size() <= 0) return;
		int flag = -1;
		for (int i = 0; i < arr[y].size(); i++) if(arr[y][i].first == key) flag = i;
		swap(arr[y][flag], arr[y][arr[y].size() - 1]);
		arr[y].pop_back();
		keys[pos->get(key)] = "";
        pos->put(key, -1);
	}
};

hashmap* hm;

int32_t main() {
	ifstream fin ("linkedmap.in");
    ofstream fout ("linkedmap.out");
    ios_base::sync_with_stdio(0);
	string str, key, val;
	hm = new hashmap();
    pos = new strinthashmap();
	while (fin >> str) {
		fin >> key;
		if (str == "put") {
			fin >> val;
			hm->put(key, val);
		}
		if (str == "delete") {
			hm->del(key);
		}
		if (str == "get") {
			fout << hm->get(key) << "\n";
		}
		if (str == "prev") {
			if (hm->fndflag(key) == -1) fout << "none" << "\n";
			else {
				int mypos = pos->get(key);
				if (mypos == 0) fout << "none" << "\n";
				else {
					int cnt = 1;
					while (mypos - cnt >= 0 && keys[mypos - cnt] == "") cnt++;
					if (mypos - cnt < 0) fout << "none" << "\n";
					else fout << hm->get(keys[mypos - cnt]) << "\n";
				}
			}
		}
		if (str == "next") {
			if (hm->fndflag(key) == -1) fout << "none" << "\n";
			else {
				int mypos = pos->get(key);
				if (mypos == keys.size() - 1) fout << "none" << "\n";
				else {
					int cnt = 1;
					while (mypos + cnt < keys.size() && keys[mypos + cnt] == "") cnt++;
					if (mypos + cnt >= keys.size()) fout << "none" << "\n";
					else fout << hm->get(keys[mypos + cnt]) << "\n";
				}
			}
		}
	}
	return 0;
}
