#include <iostream>
#include <queue>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        queue<pair<int, int>> q;
        priority_queue<int> pq; // 최대 힙 (우선순위 큰 값부터 꺼내기 위함)

        for (int i = 0; i < n; i++) {
            int priority;
            cin >> priority;
            q.push({i, priority}); // {문서의 위치, 우선순위}
            pq.push(priority);
        }

        int cnt = 0;
        while (!q.empty()) {
            int idx = q.front().first;
            int priority = q.front().second;
            q.pop();

            if (priority == pq.top()) {
                cnt++;
                pq.pop();
                if (idx == m) {
                    cout << cnt << '\n';
                    break;
                }
            } else {
                q.push({idx, priority}); // 우선순위가 높지 않으면 다시 큐 뒤로
            }
        }
    }
    return 0;
}
