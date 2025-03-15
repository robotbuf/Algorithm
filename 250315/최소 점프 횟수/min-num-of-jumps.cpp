#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int n;
int num[10];
int ans = INT_MAX;


void back(int position, int cnt) {
    
    if(position == n) {
        //cout<<"도착"<<cnt;
        ans = min(cnt, ans);
        return;
    }
    
    for(int i=1; i<=num[position]; i++) {
        back(position+i, cnt+1);
    }
}



int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    
    back(0,0);
    
    
    if(ans == INT_MAX) {
        cout << -1;
    } else {
        cout << ans-1;
    }

    

    return 0;
}
