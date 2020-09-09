#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main() {
	ifstream in("brackets.in");
	ofstream out("brackets.out");
	string str;
	while (getline(in, str)) {
		//in >> str;
		vector<int> arr;
		if (str[0] == ')') arr.push_back(1);
		if (str[0] == '(') arr.push_back(-1);
		if (str[0] == ']') arr.push_back(2);
		if (str[0] == '[') arr.push_back(-2);
		for (int j = 1; j < str.length(); j++) {
			if (str[j] == ')') {
				if (arr[arr.size() - 1]== -1) arr.pop_back();
				else arr.push_back(1);
			}
			if (str[j] == '(') arr.push_back(-1);
			if (str[j] == ']') {
				if (arr[arr.size() - 1] == -2) arr.pop_back();
				else arr.push_back(2);
			} 
			if (str[j] == '[') arr.push_back(-2);
		}
		if (arr.size() == 0) out << "YES" << endl;
		else out << "NO" << endl;
	}
	in.close();
	out.close();
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
