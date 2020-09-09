#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <sstream>
#include <utility>

using namespace std;

pair<int, int> mas[1000000];
int arr[1000000];

void siftup(int i) {
	while (true) {
		int j = (i - 1) / 2;
		if (!(j >= 0 && mas[i].first < mas[j].first)) break;
		swap(arr[mas[j].second], arr[mas[i].second]);
		swap(mas[i], mas[j]);
		i = j;
	}
}

void siftdown(int i, int n) {
	while (true) {
		int j = 2 * i + 1;
		if (j + 1 <= n - 1 && mas[j].first > mas[j + 1].first) j++;
		if (!(j <= n - 1 && mas[i].first > mas[j].first)) break;
		swap(arr[mas[j].second], arr[mas[i].second]);
		swap(mas[j], mas[i]);
		i = j;
	}
}

int delmin(int n) {
	int res = mas[0].first;
	swap(mas[0], mas[n]);
	swap(arr[mas[0].second], arr[mas[n].second]);
	siftdown(0, n);
	return res;
}

void d_key(int i, int x) {
	mas[arr[i]].first = x;
	siftup(arr[i]);
}

int main() {
    ifstream in("priorityqueue.in");
    ofstream out("priorityqueue.out"); 
    int cnt = 0, cnts = 0;
    string str;
    while (getline(in, str)) {
    	cnts++;
    	if (str[0] == 'p') {
    		istringstream iss(str);
    		string x, y;
    		iss >> x >> y;
    		cnt++;
    		mas[cnt - 1].first = stoi(y);
    		mas[cnt - 1].second = cnts - 1;
    		arr[cnts - 1] = cnt - 1;
    		siftup(cnt - 1);
		}
		if (str[0] == 'e') {
			if (cnt == 0) out << "*" << endl;
			else {
				cnt--;
				int min = delmin(cnt);
				out << min << endl;
			}
		}
		if (str[0] == 'd') {
			istringstream iss(str);
    		string x, y, z;
    		iss >> x >> y >> z;
    		d_key(stoi(y) - 1, stoi(z));
		}
	}
	in.close();
    out.close();
	return 0;
}
