#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int a,b;


int bfs() {
    queue<pair<long long, int>> q;
    q.push({a, 1});
    
    while (!q.empty()) {
        auto [num, cnt] = q.front();
        q.pop();
        
        if (num == b) return cnt;
        if (num * 2 <= b) q.push({num * 2, cnt + 1});
        if (num * 10 + 1 <= b) q.push({num * 10 + 1, cnt + 1});
    }
    
    return -1;
}


int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin>>a>>b;
    
    int ans = bfs();
    
    cout<<ans;
    
    
    
}
