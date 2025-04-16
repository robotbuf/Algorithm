#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int m;
int a,b;

int min_n = INT_MAX;
int max_n = 0;

int bin_search(int target) {
    int left = 1;
    int right = m;
    
    int cnt = 0;
    
    while(left <= right) {
        ++cnt;
        int mid = (left + right) / 2;
        
        if(mid == target) {
            return cnt;
        } else if(mid < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return cnt;
}


int main() {
    
    cin>>m;
    cin>>a>>b;
    
    for(int i=a; i<=b; i++) {
        int cnt = bin_search(i);
        min_n = min(cnt, min_n);
        max_n = max(cnt, max_n);
    }
    
    
    cout<<min_n<<" "<<max_n;

    
    
    
    
}
