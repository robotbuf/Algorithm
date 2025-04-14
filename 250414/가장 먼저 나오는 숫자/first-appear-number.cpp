#include <iostream>

using namespace std;

int n, m;
int arr[100000];
int query[100000];

int bin_search(int target) {
    int left = 0, right = n - 1;
    int res = -1;

    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            if (arr[mid] == target) res = mid;
            right = mid - 1;
        }
    }

    return (res == -1) ? -1 : res + 1;
}

int main() {
    cin.tie(NULL);
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
