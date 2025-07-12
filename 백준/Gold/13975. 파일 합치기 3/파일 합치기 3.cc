#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int K;
        cin >> K;
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (int i = 0; i < K; i++) {
            long long sz;
            cin >> sz;
            pq.push(sz);
        }

        long long cost = 0;
        
        while (pq.size() > 1) {
            long long a = pq.top(); pq.pop();
            long long b = pq.top(); pq.pop();
            cost += a + b;
            pq.push(a + b);
        }

        cout << cost << '\n';
    }
    return 0;
}
