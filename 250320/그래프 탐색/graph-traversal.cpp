#include <iostream>
#include <vector>

using namespace std;

int N, M; // 정점 개수, 간선 개수
vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    cin >> N >> M;

    graph.resize(N + 1);
    visited.resize(N + 1, false);

    // 간선 입력 (양방향 그래프)
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // 양방향 그래프이므로 추가
    }

    // 1번 정점에서 탐색 시작
    dfs(1);

    // 도달할 수 있는 정점 개수 계산
    int reachableNodes = 0;
    for (int i = 2; i <= N; i++) {
        if (visited[i]) {
            reachableNodes++;
        }
    }

    cout << reachableNodes << endl;
    return 0;
}
