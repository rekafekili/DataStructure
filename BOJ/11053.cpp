#include<iostream>
#include<algorithm>
using namespace std;

// 11053번 : 가장 긴 증가하는 부분 수열
int N;
int seq[1001];
int dp[1001];

int getLongSeq() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < i; j++) {
			if (seq[i] > seq[j] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	return *max_element(dp, dp + N + 1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> seq[i];
	}

	cout << getLongSeq() << '\n';

	return 0;
}