#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;


int N;

int bfs(int n) {
    queue<pair<int,int>> q;
    q.push({n,0});
    int ans = INT_MAX;
    
    
    while(!q.empty()) {
        int num = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(num == 1) {
            return cnt;
        }
        
        for(int i=0; i<4; i++) {
            if(i==0) {
                int new_n = num - 1;
                q.push({new_n, cnt+1});
                
            } else if(i==1) {
                int new_n = num + 1;
                q.push({new_n, cnt+1});
            } else if(i==2) {
                if(num % 2 == 0) {
                    int new_n = num / 2;
                    q.push({new_n, cnt+1});
                }
            } else {
                if(num % 3 == 0) {
                    int new_n = num / 3;
                    q.push({new_n, cnt+1});
                }
            }
        }
    }
    
    return ans;
    
    
    
}

int main() {
    cin >> N;

    // Please write your code here.
    
    cout<<bfs(N);
    return 0;
}
