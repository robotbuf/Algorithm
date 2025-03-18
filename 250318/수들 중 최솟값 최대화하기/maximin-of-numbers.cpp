#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int grid[10][10];

vector<pair<int,int>> rs;
bool visited_x[11] = { false };
bool visited_y[11] = { false };

int ans = 0;


void back(int x, int y) {
    
    if(rs.size() == n) {
        int cmp = INT_MAX;
        for(int i=0; i<n; i++) {
            cmp = min(cmp,grid[rs[i].first][rs[i].second]);
        }
        ans = max(ans,cmp);
        return;
    }
    
    for(int i=x; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!visited_x[i] && !visited_y[j]) {
                visited_x[i] = true;
                visited_y[j] = true;
                rs.push_back({i,j});
                back(i,j);
                rs.pop_back();
                visited_x[i] = false;
                visited_y[j] = false;
            }
        }
    }
    
}
int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    
    back(0,0);

    
    cout<<ans;
    

    return 0;
}
