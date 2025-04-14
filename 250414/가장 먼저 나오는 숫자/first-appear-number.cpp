#include <iostream>

using namespace std;

int n, m;
int arr[100000];
int query[100000];

int bin_search(int target) {
    int left = 0;
    int right = n-1;
    
    while(left <= right) {
        int mid = (left + right) / 2;
        
        if(arr[mid] == target) {
            while(1) {
                mid -= 1;
                if(arr[mid] != target) {
                    mid += 1;
                    break;
                }
            }
            return mid+1;
        }
        
        if(arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> query[i];
    }
    
    for(int i=0; i<m; i++) {
        cout<<bin_search(query[i])<<"\n";
    }
    
    return 0;
}
