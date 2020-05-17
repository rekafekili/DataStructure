#include<iostream>
#include<algorithm>
using namespace std;

int N;
unsigned long M;
int seq[100001];
unsigned long res = 2000000000;

// 2230번 : 수 고르기

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		cin >> seq[i];
	}

	sort(seq, seq + N);

	int first = 0, second = 1;

	// 두 수의 차가 M과 같으면 최소와 같으므로 바로 결과 출력
	// 두 수의 차가 M 보다 작으면 두번째 값을 증가시켜서 간격을 넓힌다.
	// 두 수의 차가 M 보다 커지면 첫번째 값을 증가시켜서 최소 차이값을 찾아낸다.
	while (first < N) {
		unsigned long diff = seq[second] - seq[first];
		if (diff < M) {
			second++;
		}
		else if (diff == M) {
			res = M;
			break;
		}
		else {
			res = min(diff, res);
			first++;
		}
	}

	cout << res << '\n';

	return 0;
}