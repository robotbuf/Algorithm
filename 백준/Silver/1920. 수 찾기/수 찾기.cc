#include <iostream>
#include <algorithm>

using namespace std;


int N,M;
int arr[100001];


int bin_search(int target) {
    
    int left = 0;
    int right = N-1;
    
    while(left <= right) {
        int mid = (left + right) / 2;
        
        if(arr[mid] == target) {
            return 1;
        }
        
        if(arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    
    
    return 0;
}




int main() {
    cin>>N;
    
    for(int i=0; i<N; i++) {
        cin >> arr[i];
    }
    
    sort(arr, arr+N);
    
    cin>>M;
    
    int targets[M];
    
    for(int i=0; i<M; i++) {
        cin >> targets[i];
    }
    
    for(int i=0; i<M; i++) {
        cout<<bin_search(targets[i])<<"\n";
    }
    
    

    
}
