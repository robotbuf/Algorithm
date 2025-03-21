#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int n,m;

int arr[51][51];

vector<pair<int,int>> chicken;
vector<pair<int,int>> home;

vector<int> rs;

int ans = INT_MAX;

int getDistance(int x1, int y1, int x2, int y2) {
    return abs(x1-x2) + abs(y1-y2);
}


int findDistance(vector<int> rs) {
    
    int distance = 0;
    
    for(int i=0; i<home.size(); i++) {
        int x = home[i].first;
        int y = home[i].second;
        
        int cmp = INT_MAX;
        for(int j=0; j<rs.size(); j++) {
            int chicken_x = chicken[rs[j]].first;
            int chicken_y = chicken[rs[j]].second;
            
            int dist = getDistance(x, y, chicken_x, chicken_y);
            cmp = min(dist,cmp);
        }
        distance += cmp;
    }
    return distance;
}
void backtraking(int n) {
    if(rs.size() == m) {
        ans = min(ans, findDistance(rs));
        return;
    }
    
    for(int i=n; i<chicken.size(); i++) {
        rs.push_back(i);
        backtraking(i+1);
        rs.pop_back();
    }
}



int main() {
    cin>>n>>m;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin>>arr[i][j];
        }
    }
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(arr[i][j] == 2) {
                chicken.push_back({i,j});
            } else if(arr[i][j] == 1) {
                home.push_back({i,j});
            }
        }
    }
    
    backtraking(0);
    
    cout<<ans;
    
    
    
}
