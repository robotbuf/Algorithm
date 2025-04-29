#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n;
int arr[21][21];

vector<int> rs;
int ans = 1e9;

void split() {
    vector<int> start = rs;
    vector<int> link;

    for (int i = 0; i < n; i++) {
        if (find(start.begin(), start.end(), i) == start.end()) {
            link.push_back(i);
        }
    }

    int startSum = 0, linkSum = 0;

    for (int i = 0; i < start.size(); i++) {
        for (int j = 0; j < start.size(); j++) {
            if (i == j) continue;
            startSum += arr[start[i]][start[j]];
        }
    }

    for (int i = 0; i < link.size(); i++) {
        for (int j = 0; j < link.size(); j++) {
            if (i == j) continue;
            linkSum += arr[link[i]][link[j]];
        }
    }

    ans = min(ans, abs(startSum - linkSum));
}

void back(int k) {
    if (rs.size() == n / 2) {
        split();
        return;
    }

    for (int i = k; i < n; i++) {
        rs.push_back(i);
        back(i + 1);
        rs.pop_back();
    }
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    back(0);
    
    cout << ans;
}
