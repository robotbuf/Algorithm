#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> rs;
int arr[8];

void back() {
    if (rs.size() == M) {
        for (int num : rs) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    int prev = -1;
    for (int i = 0; i < N; i++) {
        if (arr[i] != prev) {
            rs.push_back(arr[i]);
            prev = arr[i];
            back();
            rs.pop_back();
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr + N);

    back();

    return 0;
}
