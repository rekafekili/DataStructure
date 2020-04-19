#include <iostream>
#include <string>
using namespace std;

// 2661번 : 좋은 수열
string res;
int N;

void addNum(char ch, int count) {
	if (count - 1 == N) {
		cout << res << '\n';
		exit(0);
	}

	res += ch;
	//cout << "res : " << res << '\n';
	//cout << "count : " << count << '\n';

	for (int i = 1; i <= count/2; i++) {
		string str1 = res.substr(count - i, i);
		//cout << "str1 : " << str1 << '\n';
		string str2 = res.substr(count -i * 2, i);
		//cout << "str2 : " << str2 << '\n';

		if (str1 == str2) {
			res.erase(count - 1);
			return;
		}
	}

	for (int i = 1; i <= 3; i++) {
		addNum(i + '0', count + 1);
	}

	res.erase(count - 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	// 12131231
	for (int i = 1; i <= 3; i++) {
		addNum(i + '0', 1);
	}
}