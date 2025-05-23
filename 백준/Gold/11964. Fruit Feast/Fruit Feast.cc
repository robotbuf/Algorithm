
#include <iostream>
#include <string>
#include <queue>
using namespace std;

int t, a, b;
int ans = 0;

void bfs() {
    queue<pair<int, int>> q;
    bool visited[5000001] = {false};
    q.push({0, 1});
    visited[0] = true;

    while (!q.empty()) {
        auto [state, water] = q.front();
        q.pop();

        ans = max(ans, state);

        if (state + a <= t && !visited[state + a]) {
            q.push({state + a, water});
            visited[state + a] = true;
        } else if (water > 0) {
            int new_state = state / 2;
            if (new_state + a <= t && !visited[new_state + a]) {
                q.push({new_state + a, 0});
                visited[new_state + a] = true;
            }
        }

        if (state + b <= t && !visited[state + b]) {
            q.push({state + b, water});
            visited[state + b] = true;
        } else if (water > 0) {
            int new_state = state / 2;
            if (new_state + b <= t && !visited[new_state + b]) {
                q.push({new_state + b, 0});
                visited[new_state + b] = true;
            }
        }
    }
}

int main() {
    cin >> t >> a >> b;
    bfs();
    cout << ans;
}
