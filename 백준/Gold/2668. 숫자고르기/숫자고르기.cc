#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int arr[101];
bool visited[101];
bool finished[101];
vector<int> result;

void dfs(int x, vector<int>& temp) {
    visited[x] = true;
    temp.push_back(x);
    int next = arr[x];

    if (!visited[next]) {
        dfs(next, temp);
    } else {
        // 이미 방문했는데 아직 사이클이 종료되지 않았다면 -> 사이클 존재
        if (!finished[next]) {
            // 사이클의 시작점부터 끝까지 결과에 포함
            for (int i = 0; i < temp.size(); i++) {
                if (temp[i] == next) {
                    for (int j = i; j < temp.size(); j++) {
                        result.push_back(temp[j]);
                    }
                    break;
                }
            }
        }
    }

    finished[x] = true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            vector<int> temp;
            dfs(i, temp);
        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for (int x : result) {
        cout << x << "\n";
    }
}
