#include <iostream>
#include <climits>
using namespace std;

// 1654번 : 랜선 자르기(이분 탐색)

int N, K;
int res = 0;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> N;
	
	unsigned int* lines = new unsigned int[K];
	unsigned int left = 0, right = UINT32_MAX;
	int max = 0;

	for (int i = 0; i < K; i++) {
		cin >> lines[i];
	}

	while (left <= right) {
		res = 0;
		unsigned int mid = (left + right) / 2;

		for (int i = 0; i < K; i++) {
			res += lines[i] / mid;
		}

		if (res >= N) {
			left = mid + 1;
			if (mid > max)
				max = mid;
		}
		else {
			right = mid - 1;
		}
	}

	cout << max << endl;

	return 0;
}