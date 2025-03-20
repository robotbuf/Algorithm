#include <iostream>



using namespace std;

int n;
int grid[100][100];
bool visited[100][100];

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

bool isIn(int x, int y) {
    return (0<=x && 0<=y && x<n && y<n);
}




int dfs(int x, int y, int num) {
    
    int cnt = 1;
    visited[x][y] = true;

    for(int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(isIn(nx,ny)) {
            if(grid[nx][ny] == num && !visited[nx][ny]) {

                cnt+=dfs(nx,ny,num);
                
            }
        }
    }
    
    return cnt;
    
}


int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.
    int block_cnt = 0;
    int max_block_size = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j]) {
                int res = dfs(i,j,grid[i][j]);
                
                
                if(res >= 4) {
                    block_cnt++;
                }
                max_block_size = max(max_block_size,res);
                
            }
        }
    }
    
    cout<<block_cnt<<" "<<max_block_size;

    return 0;
}
