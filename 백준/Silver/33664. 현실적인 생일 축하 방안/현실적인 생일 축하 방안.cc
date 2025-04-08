#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long b;
    int n, m;
    cin >> b >> n >> m;

    map<string, long long> a;
    for (int i = 0; i < n; ++i) {
        string name;
        long long price;
        cin >> name >> price;
        a[name] = price;
    }

    for (int i = 0; i < m; ++i) {
        string item;
        cin >> item;
        b -= a[item]; // 존재한다고 가정
    }

    cout << (b >= 0 ? "acceptable" : "unacceptable") << '\n';
    return 0;
}