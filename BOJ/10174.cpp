#include <iostream>
#include <algorithm>
using namespace std;

// 10174¹ø: ÆÓ¸°µå·Ò
char input[1000];

string palindrome(string str) {
	string pre, post;
	int leng = str.size();
	pre = str.substr(0, leng / 2);
	if (str.size() % 2 != 0) {
		post = str.substr(leng / 2 + 1, leng);
	}
	else {
		post = str.substr(leng / 2, leng);
	}

	// Debug
	//cout << "pre : " << pre << endl;
	//cout << "post : " << post << endl;

	for (int i = 0; i < leng / 2; i++) {
		if (pre[i] != post[post.size() - 1 - i])
			return "No";
	}
		
	return "Yes";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;
	cin.ignore();

	for (int i = 0; i < testCase; i++) {
		cin.getline(input, 1000, '\n');
		string str(input);
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		cout << palindrome(str) << '\n';
	}
}