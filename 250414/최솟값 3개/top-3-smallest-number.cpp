#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<long long> pq;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        pq.push(-x);

        if (pq.size() < 3) {
            cout << -1 << "\n";
        } else {
            long long a = -pq.top(); pq.pop();
            long long b = -pq.top(); pq.pop();
            long long c = -pq.top(); pq.pop();

            long long product = a * b * c;
            cout << product << '\n';

            pq.push(-a);
            pq.push(-b);
            pq.push(-c);
        }
    }

    return 0;
}
