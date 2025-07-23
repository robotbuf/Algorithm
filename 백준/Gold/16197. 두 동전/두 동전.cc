#include <iostream>
#include <queue>
#include <tuple>
#include <array>
#include <vector>
using namespace std;
using State = tuple<int,int,int,int,int>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> board(n);
    vector<pair<int,int>> coins;
    for (int i = 0; i < n; i++) {
        cin >> board[i];
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'o')
                coins.emplace_back(i, j);
        }
    }

    static bool visited[21][21][21][21] = {};
    const array<int,4> dx{ -1, 1, 0, 0 }, dy{ 0, 0, -1, 1 };
    auto inside = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m;
    };

    queue<State> q;
    auto [x1, y1] = coins[0];
    auto [x2, y2] = coins[1];
    visited[x1][y1][x2][y2] = true;
    q.emplace(x1, y1, x2, y2, 0);

    while (!q.empty()) {
        auto [cx1, cy1, cx2, cy2, moves] = q.front(); q.pop();
        if (moves >= 10) continue;

        for (int d = 0; d < 4; d++) {
            int nx1 = cx1 + dx[d], ny1 = cy1 + dy[d];
            int nx2 = cx2 + dx[d], ny2 = cy2 + dy[d];
            bool out1 = !inside(nx1, ny1);
            bool out2 = !inside(nx2, ny2);

            if (out1 && out2)
                continue;
            if (out1 ^ out2) {
                cout << moves + 1;
                return 0;
            }

            if (board[nx1][ny1] == '#') { nx1 = cx1; ny1 = cy1; }
            if (board[nx2][ny2] == '#') { nx2 = cx2; ny2 = cy2; }

            if (!visited[nx1][ny1][nx2][ny2]) {
                visited[nx1][ny1][nx2][ny2] = true;
                q.emplace(nx1, ny1, nx2, ny2, moves + 1);
            }
        }
    }

    cout << -1;
    return 0;
}
