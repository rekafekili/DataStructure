#include<iostream>
#include<math.h>
using namespace std;

// 2839번 : 설탕 배달

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int total;
	cin >> total;

	int val5 = 0;		// 5킬로그램 봉투 개수
	int val3 = 0;		// 3킬로그램 봉투 개수
	int res = 0;	// 전체 봉투 개수

	if (total % 5 == 0)	// 5킬로그램 봉투로 모두 나눌 수 있으면 3킬로그램 봉투를 쓸 필요가 없다.
		res = total / 5;
	else {
		for (int i = (total / 5); i >= 0; i--) {
			val5 = i;
			if ((total - (5 * val5)) % 3 == 0) {	// 5킬로 봉투로 나눈 후 나머지가 3킬로 봉투로 나뉠 경우
				val3 = (total - (5 * val5)) / 3;
				res = val5 + val3;
				break;
			}
		}

		if (val5 == 0 && val3 == 0)
			res = -1;
	}

	cout << res << endl;

	return 0;
}