#include<iostream>
using namespace std;

// 1712번 : [수학] 손익분기점

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int fixed;	// 고정 비용
	int variable;	// 가변 비용
	int price;	// 판매가

	cin >> fixed >> variable >> price;
	int res = 0;

	if (price - variable <= 0) res = -1;
	else res = (fixed / (price - variable)) + 1;	// 손익분기점

	cout << res << endl;
	
	return 0;
}