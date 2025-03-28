#include <iostream>

using namespace std;

int n, m;
int arr[100000];

int bin_search(int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            // 양쪽으로 중복 개수 세기
            int count = 1;
            int i = mid - 1;
            while (i >= 0 && arr[i] == target) {
                count++;
                i--;
            }
            i = mid + 1;
            while (i < n && arr[i] == target) {
                count++;
                i++;
            }
            return count;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return 0;
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
