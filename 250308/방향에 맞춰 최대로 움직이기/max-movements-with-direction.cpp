#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int num[4][4];
int move_dir[4][4];
int r, c;


int direction[9][2] = {
    {0,0},
    {-1,0},
    {-1,1},
    {0,1},
    {1,1},
    {1,0},
    {1,-1},
    {0,-1},
    {-1,-1},
};

vector<int> rs;
int ans = 0;

void back(int r, int c, int cnt) {
    
    int nr = r;
    int nc = c;
    while(1) {
        int idx = 1;
        
        int d = move_dir[r][c];
        nr += direction[d][0];
        nc += direction[d][1];
        
        if(0<=nr && nr<n && 0<=nc && nc<n) {
            if(num[nr][nc] > num[r][c]) {
                back(nr,nc,cnt+1);
            }
        }
        else {
            ans = max(ans,cnt);
            return;
        }
        
        idx++;
        
    }
    
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> num[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> move_dir[i][j];

    cin >> r >> c;

    // Please write your code here
    back(r-1, c-1, 0);
    
    cout<<ans;

    return 0;
}
