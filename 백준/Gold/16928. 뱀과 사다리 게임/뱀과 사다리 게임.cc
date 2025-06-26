#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int n,m;
vector<vector<int>> ladder(101);
vector<vector<int>> snake(101);
int position[101];
bool visited[101];


int ans = 0;

void play() {
    queue<pair<int,int>> q;
    q.push({1,0});
    visited[1] = true;
    
    while(!q.empty()) {
        auto [position,count] = q.front();
        q.pop();
        
        if(position == 100) {
            ans = count;
            return;
        }
        
        for(int i=1; i<=6; i++) {
            int new_position = position + i;
            
            if(!visited[new_position] && new_position < 101) {
                
                if(snake[new_position].size() == 1) {
                    q.push({snake[new_position][0], count+1});
                    visited[snake[new_position][0]] = true;
                    visited[new_position] = true;
                } else if(ladder[new_position].size() == 1) {
                    q.push({ladder[new_position][0], count+1});
                    visited[ladder[new_position][0]] = true;
                    visited[new_position] = true;
                } else {
                    q.push({new_position,count+1});
                    visited[new_position] = true;
                }
            }
        }
    }
    
}



int main() {
    
    cin>>n>>m;
    
    for(int i=0; i<n; i++) {
        int a,b;
        cin>>a>>b;
        ladder[a].push_back(b);
    }
    for(int i=0; i<m; i++) {
        int a,b;
        cin>>a>>b;
        snake[a].push_back(b);
    }
    
    play();
    
    
    cout<<ans;
    
    
    
}
