#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long m;
long long a,b;

int min_n = INT_MAX;
int max_n = 0;

int bin_search(long long target) {
    long long left = 1;
    long long right = m;
    
    int cnt = 0;
    
    while(left <= right) {
        ++cnt;
        long long mid = (left + right) / 2;
        
        if(mid == target) {
            break;
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
    
    for(long long i=a; i<=b; i++) {
        int cnt = bin_search(i);
        min_n = min(cnt, min_n);
        max_n = max(cnt, max_n);
    }
    
    
    cout<<min_n<<" "<<max_n;

    
    
    
    
}
