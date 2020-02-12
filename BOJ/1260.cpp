#include<iostream>
#include<vector>
#include <algorithm>
#include <queue>
using namespace std;

void dfs(int start, vector<int> graph[], bool check[]) {
	if (start == 0) return;

	check[start] = true;	// 방문 표시
	cout << start << " ";

	for (int i = 0; i < graph[start].size(); i++) {
		int tmp = graph[start][i];
		if (!check[tmp]) {
			dfs(tmp, graph, check);
		}
	}
}

void bfs(int start, vector<int> graph[], bool check[]) {
	queue<int> q;

	check[start] = true;
	q.push(start);

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		cout << tmp << " ";

		for (int i = 0; i < graph[tmp].size(); i++) {
 			if (!check[graph[tmp][i]]) {
				q.push(graph[tmp][i]);
				check[graph[tmp][i]] = true;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N = 0, M = 0, V = 0; // 정점 개수, 간선 개수, 시작점

	cin >> N >> M >> V;

	vector<int>* graph = new vector<int>[N + 1];

	for (int i = 0; i < M; i++) {
		int n1, n2;

		cin >> n1 >> n2;

		graph[n1].push_back(n2);
		graph[n2].push_back(n1);
	}

	// 한 정점의 간선이 여러개일 경우 오름차순으로 방문하기 위해 정렬
	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}

	bool* check = new bool[N + 1];
	fill(check, check + N + 1, false);

	dfs(V, graph, check);
	cout << endl;

	fill(check, check + N + 1, false);
	bfs(V, graph, check);
	cout << endl;

	return 0;
}