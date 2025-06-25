#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> leftCount(N+1);
    for (int i = 1; i <= N; ++i) {
        cin >> leftCount[i];
    }
    vector<int> result;
    result.reserve(N);
    for (int i = N; i >= 1; --i) {
        int pos = leftCount[i];
        result.insert(result.begin() + pos, i);
    }
    for (int x : result) {
        cout << x << ' ';
    }
    return 0;
}

