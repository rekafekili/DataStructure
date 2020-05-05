#include<iostream>
#include<algorithm>
using namespace std;

// 11055번 : 가장 큰 증가 부분 수열
int N;
int arr[1001];
int sum[1001];

int getBigSum() {
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && sum[j] + arr[i] > sum[i]) {
				sum[i] = sum[j] + arr[i];
			}
		}
	}

	return *max_element(sum, sum + N + 1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	cout << getBigSum() << '\n';

	return 0;
}