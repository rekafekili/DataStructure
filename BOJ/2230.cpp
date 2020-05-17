#include<iostream>
#include<algorithm>
using namespace std;

int N;
unsigned long M;
int seq[100001];
unsigned long res = 2000000000;

// 2230�� : �� ����

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

	// �� ���� ���� M�� ������ �ּҿ� �����Ƿ� �ٷ� ��� ���
	// �� ���� ���� M ���� ������ �ι�° ���� �������Ѽ� ������ ������.
	// �� ���� ���� M ���� Ŀ���� ù��° ���� �������Ѽ� �ּ� ���̰��� ã�Ƴ���.
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