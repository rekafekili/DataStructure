#include<iostream>
#include<queue>
using namespace std;

class Point {
public:
	int x;
	int y;
	Point(int a, int b) {
		x = a;
		y = b;
	}
};

int res = 0;
int M, N; // M : 가로, N : 세로

queue<Point> q;
int bfsCount;
int nextCount;
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void ripeTomato(int** tomato, Point p) {
	for (int i = 0; i < 4; i++) {
		int nextX = p.x + dx[i];
		int nextY = p.y + dy[i];

		if (nextX < 0 || nextX >= N || nextY < 0 || nextY >= M)
			continue;

		if (tomato[nextX][nextY] == 0) {
			tomato[nextX][nextY] = 1;
			nextCount++;
			q.push(Point(nextX, nextY));
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	

	cin >> M >> N;

	int** tomato = new int* [N];

	for (int i = 0; i < N; i++) {
		tomato[i] = new int[M];
		for (int j = 0; j < M; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				//cout << "Debug : " << i << " : " << j << endl;
				q.push(Point(i, j));
			}
		}
	}

	bfsCount = q.size();
	nextCount = 0;
	while (q.size()) {
		ripeTomato(tomato, q.front());
		bfsCount--;

		if (bfsCount == 0) {
			bfsCount = nextCount;
			nextCount = 0;
			res++;
			//cout << "Debug : " << res << endl;
		}
		q.pop();
	}

	res--;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[i][j] == 0)
				res = -1;
		}
	}

	cout << res << endl;

	return 0;
}