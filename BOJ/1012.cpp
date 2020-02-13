#include<iostream>
#include<queue>
using namespace std;

// 1012번 : 유기농 배추

int M, N;	// M : 가로길이, N : 세로 길이
int cabbage;	// 배추 개수
pair<int, int> cabbagePosition; // 가로, 세로
int ground[51][51] = { 0 };
int dH[4] = { 0, 1, 0, -1 };
int dV[4] = { -1, 0, 1, 0 };

queue<pair<int, int>> que;

void searchNear(int H, int V) {
	ground[H][V] = -1;	// visited
	for (int i = 0; i < 4; i++) {
		int nextH = H + dH[i];
		int nextV = V + dV[i];

		if (nextH < 0 || nextH >= M || nextV < 0 || nextV >= N) 
			continue;

		if (ground[nextH][nextV] == 1) {
			searchNear(nextH, nextV);
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		int res = 0;
		for (int a = 0; a < 51; a++) {
			for (int b = 0; b < 51; b++) {
				ground[a][b] = 0;
			}
		}
		cin >> M >> N >> cabbage;

		for (int j = 0; j < cabbage; j++) {
			cin >> cabbagePosition.first >> cabbagePosition.second;
			ground[cabbagePosition.first][cabbagePosition.second] = 1;
			que.push({ cabbagePosition.first, cabbagePosition.second });
		}

		//cout << "==================================" << endl;
		//for (int a = 0; a < N; a++) {
		//	for (int b = 0; b < M; b++) {
		//		cout << ground[a][b] << " ";
		//	}
		//	cout << endl;
		//}
		//cout << "==================================" << endl;
		
		while (que.size()) {
			// NOT Visited
			if (ground[que.front().first][que.front().second] != -1) {
				searchNear(que.front().first, que.front().second);
				res++;
			}
			que.pop();
		}

		//cout << "==================================" << endl;
		//for (int a = 0; a < N; a++) {
		//	for (int b = 0; b < M; b++) {
		//		cout << ground[a][b] << " ";
		//	}
		//	cout << endl;
		//}
		//cout << "==================================" << endl;
		
		cout << res << endl;
	}

	return 0;
}