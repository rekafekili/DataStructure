#include <iostream>
using namespace std;

// 1991번 : 트리 순회

int N; // 이진 트리의 노드 개수
int tree[26][2];

void preOrder(int node) {
	if (node == -1)
		return;

	cout << (char)(node + 'A');
	preOrder(tree[node][0]);
	preOrder(tree[node][1]);
}

void inOrder(int node) {
	if (node == -1)
		return;

	inOrder(tree[node][0]);
	cout << (char)(node + 'A');
	inOrder(tree[node][1]);
}

void postOrder(int node) {
	if (node == -1)
		return;

	postOrder(tree[node][0]);
	postOrder(tree[node][1]);
	cout << (char)(node + 'A');
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		char root, left, right;
		cin >> root >> left >> right;

		if (left != '.')
			left -= 'A';
		else
			left = -1;

		if (right != '.')
			right -= 'A';
		else
			right = -1;

		tree[root - 'A'][0] = left;
		tree[root - 'A'][1] = right;
	}

	preOrder(0);
	cout << '\n';
	inOrder(0);
	cout << '\n';
	postOrder(0);
	cout << '\n';

	return 0;
}