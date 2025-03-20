#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, k, m;
int grid[100][100];
int r[10], c[10];

vector<pair<int, int>> rock;
vector<int> rs;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool isIn(int x, int y) {
    return (0 <= x && 0 <= y && x < n && y < n);
}

int bfs(vector<int> li) {
    queue<pair<int, int>> q;
    bool visited[100][100] = {false};
    int copyed[100][100];
    memcpy(copyed, grid, sizeof(grid));

    int cnt = 0;

    for (int i = 0; i < li.size(); i++) {
        int x = rock[li[i]].first;
        int y = rock[li[i]].second;
        copyed[x][y] = 0;
    }

    for (int i = 0; i < k; i++) {
        q.push({r[i], c[i]});
        visited[r[i]][c[i]] = true;
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        cnt++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (isIn(nx, ny) && !visited[nx][ny] && copyed[nx][ny] == 0) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }

    return cnt;
}

int ans = 0;
void backtrack(int start) {
    if (rs.size() == m) {
        ans = max(ans, bfs(rs));
        return;
    }

    for (int i = start; i < rock.size(); i++) {
        rs.push_back(i);
        backtrack(i + 1);
        rs.pop_back();
    }
}

int main() {
    cin.tie(NULL);
    cin >> n >> k >> m;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> grid[i][j];


    for (int i = 0; i < k; i++) {
        cin >> r[i] >> c[i];
        r[i]--;
        c[i]--;
    }
    
  
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                rock.push_back({i, j});
            }
        }
    }


    backtrack(0);

    cout << ans;

    return 0;
}
