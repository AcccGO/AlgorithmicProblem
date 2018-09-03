//Consecutive Factors

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

int getLen(int n, int x) {
	int len;
	for (len = 0; n % (x + len) == 0; n /= (x + len++));
	return len;
}

int main() {
	int n;
	cin >> n;
	int len = 0;
	int start = 0;
	for (int i = 2; n / i >= i; ++i) {
		int may = getLen(n, i);
		if (may > len) {
			start = i;
			len = may;
		}
	}
	if (len == 0) {
		start = n;
		len = 1;
	}
	cout << len <<endl;
	for (int i = 0; i < len; ++i) {
		if (i) {
			cout<<"*";
		}
		cout<<start + i;
	}
	cout<<endl;
	return 0;
}
