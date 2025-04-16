#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[12];
int op[4];
vector<int> rs;

int max_ans = -1e9;
int min_ans = 1e9;

int calculate() {
    int result = arr[0];
    for (int i = 0; i < rs.size(); i++) {
        int opCode = rs[i];
        int num = arr[i + 1];
        switch(opCode) {
            case 0: result += num; break;
            case 1: result -= num; break;
            case 2: result *= num; break;
            case 3: result /= num; break;
        }
    }
    return result;
}

void back(int n) {
    if (rs.size() == n - 1) {
        int res = calculate();
        max_ans = max(max_ans, res);
        min_ans = min(min_ans, res);
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        if (op[i] > 0) {
            rs.push_back(i);
            op[i]--;
            back(n);
            rs.pop_back();
            op[i]++;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < 4; i++) cin >> op[i];
    
    back(n);
    cout << max_ans << "\n" << min_ans << "\n";
}
