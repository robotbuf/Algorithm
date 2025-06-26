#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int n;
    
    
    int e;
    
    cin>>n;
    cin>>e;
    
    vector<vector<int>> graph(n+1);
    
    for(int i=0; i<e; i++) {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    bool visited[101] = {false};
    
    queue<int> q;
    q.push(1);
    visited[1] = true;
    
    int ans = 0;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        
        
        for(int i=0; i<graph[node].size(); i++) {
            int new_node = graph[node][i];
            
            if(!visited[new_node]) {
                q.push(new_node);
                visited[new_node] = true;
                ans += 1;
            }
        }
        
    }
    
    cout<<ans;
    
    
}
