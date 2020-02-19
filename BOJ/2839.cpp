#include<iostream>
#include<math.h>
using namespace std;

// 2839�� : ���� ���

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int total;
	cin >> total;

	int val5 = 0;		// 5ų�α׷� ���� ����
	int val3 = 0;		// 3ų�α׷� ���� ����
	int res = 0;	// ��ü ���� ����

	if (total % 5 == 0)	// 5ų�α׷� ������ ��� ���� �� ������ 3ų�α׷� ������ �� �ʿ䰡 ����.
		res = total / 5;
	else {
		for (int i = (total / 5); i >= 0; i--) {
			val5 = i;
			if ((total - (5 * val5)) % 3 == 0) {	// 5ų�� ������ ���� �� �������� 3ų�� ������ ���� ���
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