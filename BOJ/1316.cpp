#include<iostream>
#include <vector>
using namespace std;

// 1316번 : 그룹 단어 체커

char voca[100];

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int numberOfInputs;
	int minus = 0;	// 그룹 단어가 아닌 단어의 개수

	cin >> numberOfInputs;
	
	for (int i = 0; i < numberOfInputs; i++) {
		cin >> voca;

		char pre = '\0';
		int a[26] = { 0 };
		for (int j = 0; voca[j] != NULL; j++) {
			char ch = voca[j];
			int own = (int)ch - 97;
			if (j == 0) {
				pre = voca[j];
				a[own]++;
				continue;
			}
			else {
				if (pre != ch) {
					pre = ch;
					if (a[own] != 0) {
						minus++;
						break;
					}
					else {
						a[own]++;
					}
				}
			}
		}
	}

	cout << numberOfInputs - minus << endl;
	return 0;
}