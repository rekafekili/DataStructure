#include <iostream>
#include <queue>
using namespace std;

// 7569번 : 토마토

int M, N, H; // M: 가로

struct Point {
	int x;
	int y;
	int z;

	Point(int a, int b, int c) {
		x = a;
		y = b;
		z = c;
	}
};
int xrange[6] = { -1, 0, 1, 0, 0, 0 };
int yrange[6] = { 0, 1, 0, -1, 0, 0 };
int zrange[6] = { 0, 0, 0, 0, -1, 1 };
queue<Point> que;
int height[100][100][100];
int res = 0;

void goOne(int x, int y, int z) {
	for (int i = 0; i < 6; i++) {
		int nextX = x + xrange[i];
		int nextY = y + yrange[i];
		int nextZ = z + zrange[i];

		if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < M && nextZ >= 0 && nextZ < H) {
			if (height[nextX][nextY][nextZ] == 0) {
				height[nextX][nextY][nextZ] = 1;
				que.push(Point(nextX, nextY, nextZ));
			}
		}
	}
}

bool checkHeight() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (height[j][k][i] == 0)
					return false;
			}
		}
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M >> N >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> height[j][k][i];
				if (height[j][k][i] == 1)
					que.push(Point(j, k, i));
			}
		}
	}

	while (que.empty() == 0) {
		int count = que.size();

		for (int i = 0; i < count; i++) {
			int x = que.front().x;
			int y = que.front().y;
			int z = que.front().z;
			que.pop();

			goOne(x, y, z);
		}

		if (que.size() == 0) {
			if (checkHeight()) {
				cout << res << endl;
				return 0;
			}
			else {
				cout << -1 << endl;
				return 0;
			}
		}
		res++;
	}
}