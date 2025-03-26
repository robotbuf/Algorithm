#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

char arr[5][5];
int ans = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
set<vector<pair<int, int>>> visited_combinations;

// 현재 조합이 서로 인접한지 확인 (BFS)
bool isConnected(vector<pair<int, int>>& group) {
    queue<pair<int, int>> q;
    bool visited[5][5] = {false};
    q.push(group[0]);
    visited[group[0].first][group[0].second] = true;

    int count = 1;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;
            if (visited[nx][ny]) continue;

            for (auto& p : group) {
                if (p.first == nx && p.second == ny) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                    count++;
                    break;
                }
            }
        }
    }

    return count == 7;
}

void dfs(vector<pair<int, int>>& group, int scount) {
    if (group.size() == 7) {
        if (scount >= 4 && isConnected(group)) {
            // 정렬하여 중복 제거
            auto tmp = group;
            sort(tmp.begin(), tmp.end());
            if (visited_combinations.find(tmp) == visited_combinations.end()) {
                visited_combinations.insert(tmp);
                ans++;
            }
        }
        return;
    }

    for (auto [x, y] : group) {
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 || ny < 0 || nx >= 5 || ny >= 5) continue;

            pair<int, int> next = {nx, ny};
            if (find(group.begin(), group.end(), next) != group.end()) continue;

            group.push_back(next);
            dfs(group, scount + (arr[nx][ny] == 'S' ? 1 : 0));
            group.pop_back();
        }
    }
}

int main() {
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> arr[i][j];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            vector<pair<int, int>> group = {{i, j}};
            dfs(group, arr[i][j] == 'S' ? 1 : 0);
        }
    }

    cout << ans << endl;
    return 0;
}
