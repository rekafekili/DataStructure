#include <iostream>
using namespace std;

// 1629번 : 곱셈 (분할 정복 알고리즘)

int dividePow(long long int A, long long int B, long long int C) {
	if (B == 1) return A % C;
	long long tmp = dividePow(A, B / 2, C);
	tmp = (tmp * tmp) % C;

	// 나머지가 1일 경우(홀수일 경우) 한 번더 곱해준다.
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