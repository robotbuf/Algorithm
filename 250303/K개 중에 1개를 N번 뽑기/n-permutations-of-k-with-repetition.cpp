#include <iostream>
#include <vector>

using namespace std;

int K, N;
vector<int> v; 

void dfs(int n) { 
    if (n == N) { 
        // 벡터 출력
        for (int num : v) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 1; i <= K; i++) {
        v.push_back(i);
        dfs(n + 1);     
        v.pop_back();    
    } 
}

int main() {
    cin >> K >> N;
    
    dfs(0); 

    return 0;
}
