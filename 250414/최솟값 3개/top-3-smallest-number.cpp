#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> q;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(-x);

        if (q.size() < 3) {
            cout << -1 << "\n";
        } else {
            vector<int> temp;
            int product = 1;

            for (int j = 0; j < 3; j++) {
                int val = -q.top(); q.pop();
                product *= val;
                temp.push_back(-val);
            }

            for (int val : temp) q.push(val);
            cout << product << "\n";
        }
    }

    return 0;
}
