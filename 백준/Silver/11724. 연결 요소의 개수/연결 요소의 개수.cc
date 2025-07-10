#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;


int main() {
    int n,m;
    
    cin>>n>>m;
    
    vector<vector<int>> graph(n+1);
    bool visited[1001] = { false };
    
    for(int i=0; i<m; i++) {
        int x,y;
        cin>>x>>y;
        
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    queue<int> q;
    int ans = 0;
    
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            q.push(i);
            visited[i] = true;
            while(!q.empty()) {
                int node = q.front();
                q.pop();
               
                
                for(int e: graph[node]) {
                    if(!visited[e]) {
                        q.push(e);
                        visited[e] = true;
                    }
                }
            }
            ans++;
        }
    }
    
    cout<<ans;
    
    
    
    
}
