#include<iostream>
using namespace std;

// 1712�� : [����] ���ͺб���

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int fixed;	// ���� ���
	int variable;	// ���� ���
	int price;	// �ǸŰ�

	cin >> fixed >> variable >> price;
	int res = 0;

	if (price - variable <= 0) res = -1;
	else res = (fixed / (price - variable)) + 1;	// ���ͺб���

	cout << res << endl;
	
	return 0;
}