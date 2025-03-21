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
    bool visited[1000001] {false} ;
    visited[n] = true;
    
    
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
                if(!visited[new_n]) {
                    q.push({new_n, cnt+1});
                    visited[new_n] = true;
                }
                
            } else if(i==1) {
                int new_n = num + 1;
                if(!visited[new_n]) {
                    q.push({new_n, cnt+1});
                    visited[new_n] = true;
                }
            } else if(i==2) {
                if(num % 2 == 0) {
                    int new_n = num / 2;
                    if(!visited[new_n]) {
                        q.push({new_n, cnt+1});
                        visited[new_n] = true;
                    }
                }
            } else {
                if(num % 3 == 0) {
                    int new_n = num / 3;
                    if(!visited[new_n]) {
                        q.push({new_n, cnt+1});
                        visited[new_n] = true;
                    }
                }
            }
        }
    }
    
    return -1;

}

int main() {
    cin >> N;

    // Please write your code here.
    
    cout<<bfs(N);
    return 0;
}
