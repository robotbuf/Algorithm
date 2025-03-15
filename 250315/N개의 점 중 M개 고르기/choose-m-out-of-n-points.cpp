#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int n, m;
int x[20], y[20];

vector<int> coor;
bool visited[20] = {false};
int ans = INT_MAX;

int getDistance(int x1, int y1, int x2, int y2) {
   
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int calculate(vector<int> coor) {
    int res = 0;

    for (int i = 0; i < coor.size(); i++) {
        int x1 = x[coor[i]];
        int y1 = y[coor[i]];

        for (int j = i + 1; j < coor.size(); j++) {
            int x2 = x[coor[j]];
            int y2 = y[coor[j]];

            int distance = getDistance(x1, y1, x2, y2);
            res = max(res, distance);
        }
    }
    
    return res;
}

void find(int num) {
    if (coor.size() == m) {
        ans = min(ans, calculate(coor));
        return;
    }

    for (int i = num; i < n; i++) {
        if (!visited[i]) {
            coor.push_back(i);
            visited[i] = true;
            find(i + 1);
            coor.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    find(0);
    
    cout << ans << endl;

    return 0;
}
