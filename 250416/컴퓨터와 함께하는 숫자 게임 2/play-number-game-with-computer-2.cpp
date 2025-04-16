#include <iostream>
#include <algorithm>
using namespace std;

int m, a, b;

int bin_search(int target) {
    int left = 1;
    int right = m;
    int cnt = 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // 내림 보장
        if (mid == target) {
            break;
        } else if (mid < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
        cnt++;
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> a >> b;

    int minTurn = 1e9;
    int maxTurn = 0;

    for (int i = a; i <= b; ++i) {
        int cnt = bin_search(i);
        minTurn = min(minTurn, cnt);
        maxTurn = max(maxTurn, cnt);
    }

    cout << minTurn << ' ' << maxTurn << '\n';
}
