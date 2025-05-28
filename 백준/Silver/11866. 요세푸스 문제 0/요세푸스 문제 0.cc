#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    vector<int> res;

    while (!q.empty()) {
        for (int i = 0; i < k - 1; i++) {
            q.push(q.front());
            q.pop();
        }
        res.push_back(q.front());
        q.pop();
    }

    cout << "<";
    for (int i = 0; i < res.size(); i++) {
        if (i < res.size() - 1) {
            cout << res[i] << ", ";
        } else {
            cout << res[i];
        }
    }
    cout << ">";
}
