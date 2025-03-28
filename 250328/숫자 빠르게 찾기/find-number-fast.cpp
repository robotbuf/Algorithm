#include <iostream>

using namespace std;

int n, m;
int arr[100000];

int bin_search(int target) {
    int left = 0;
    int right = n-1;
    
    while(left <= right) {
        int mid = (left + right) / 2;

        if(arr[mid] == target) {
            return mid+1;
        }

        if(arr[mid] < target) {
            left = mid+1;
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
        int x;
        cin >> x;
        cout<<bin_search(x)<<"\n";
    }


    return 0;
}
