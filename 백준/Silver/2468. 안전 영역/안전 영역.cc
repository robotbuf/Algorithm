#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[101][101];
bool area[101][101] = { false };
bool visited[101][101] = { false };
int height = 0;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void sink(int height) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j] <= height) {
                area[i][j] = true;
            }
        }
    }
    
}
void count_safe_area(int r, int c) {
    queue<pair<int,int>> q;
    q.push({r,c});
    visited[r][c] = true;
    
    while(!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(0<=nx && nx<n && 0<=ny && ny<n) {
                if(!area[nx][ny] && !visited[nx][ny]) {
                    q.push({nx,ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}



int main() {
    cin>>n;
    
    int max_height = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>arr[i][j];
            max_height = max(max_height,arr[i][j]);
        }
    }
    
    int ans = 0;
    
    
    
    for(int h=0; h<=max_height; h++) {
        sink(h);
        int areas = 0;
        
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                visited[i][j] = false;
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(!visited[i][j] && !area[i][j]) {
                    count_safe_area(i, j);
                    areas++;
                }
            }
        }
        ans = max(ans,areas);
    }
    
    cout<<ans;
    
    
    
    
    
}
