#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long arr[2001];

bool isGood(long long target, int index) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        if (left == index) {
            left++;
            continue;
        }
        if (right == index) {
            right--;
            continue;
        }

        long long sum = arr[left] + arr[right];

        if (sum == target) {
            return true;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }

    return false;
}

int main() {
    cin>>n;
    
    int cnt = 0;
    
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    
    for(int i=0; i<n; i++) {
        if(isGood(arr[i],i)) {
            //cout<<arr[i]<<"\n";
            cnt++;
        }
    }
    
    cout<<cnt;
}
