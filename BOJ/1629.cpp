#include <iostream>
using namespace std;

// 1629�� : ���� (���� ���� �˰���)

int dividePow(long long int A, long long int B, long long int C) {
	if (B == 1) return A % C;
	long long tmp = dividePow(A, B / 2, C);
	tmp = (tmp * tmp) % C;

	// �������� 1�� ���(Ȧ���� ���) �� ���� �����ش�.
	if (B % 2)
		tmp = (tmp * A) % C;

	return tmp;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long A, B, C;

	cin >> A >> B >> C;
	
	cout << dividePow(A, B, C) << endl;

	return 0;
}