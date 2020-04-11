#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int N;
string strArr[1000];
char charArr[50];

int sumDigit(string str) {
	int sum = 0;
	int size = str.size();
	strcpy(charArr, str.c_str());
	for (int i = 0; i < size; i++) {
		int num = charArr[i] - 48;
		if (num > -1 && num < 10) {
			sum += num;
		}
	}

	return sum;
}

bool compare(const string& str1, const string& str2) {
	if (str1.size() != str2.size()) {
		return str1.size() < str2.size();
	}
	else if (str1.size() == str1.size()) {
		int str1Num = sumDigit(str1);
		int str2Num = sumDigit(str2);

		if(str1Num != str2Num)
			return str1Num < str2Num;
	}
	return str1 < str2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> strArr[i];
	}

	sort(strArr, strArr + N, compare);

	for (int i = 0; i < N; i++) {
		cout << strArr[i] << '\n';
	}

	return 0;
}