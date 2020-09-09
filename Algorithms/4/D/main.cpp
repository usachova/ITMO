#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream in("postfix.in");
    ofstream out("postfix.out");
    vector<int> arr;
    string str;
    getline(in, str);
    int i = 0;
    while (i < str.length()) {
    	char ch = str[i];
    	if (ch == '+') {
    		int x = arr[arr.size() - 1];
    		arr.pop_back();
    		int y = arr[arr.size() - 1];
    		arr.pop_back();
    		arr.push_back(x + y);
		}
		else if (ch == '-') {
    		int x = arr[arr.size() - 1];
    		arr.pop_back();
    		int y = arr[arr.size() - 1];
    		arr.pop_back();
    		arr.push_back(y - x);
		}
		else if (ch == '*') {
    		int x = arr[arr.size() - 1];
    		arr.pop_back();
    		int y = arr[arr.size() - 1];
    		arr.pop_back();
    		arr.push_back(x * y);
		}
		else {
			arr.push_back(ch - 48);
		}
		i += 2;
	}
	out << arr[0];
	in.close();
    out.close();
	return 0;
}
