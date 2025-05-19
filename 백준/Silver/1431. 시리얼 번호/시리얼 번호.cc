#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


int sumOfDigits(const string& s) {
    int sum = 0;
    for (char c : s) {
        if (isdigit(c)) {
            sum += c - '0';
        }
    }
    return sum;
}


bool compare(const string& a, const string& b) {
    if (a.length() != b.length()) return a.length() < b.length();

    int sumA = sumOfDigits(a);
    int sumB = sumOfDigits(b);
    if (sumA != sumB) return sumA < sumB;

    return a < b;
}

int main() {
    int n;
    cin >> n;

    vector<string> serials(n);
    for (int i = 0; i < n; ++i) {
        cin >> serials[i];
    }

    sort(serials.begin(), serials.end(), compare);

    for (const string& s : serials) {
        cout << s << '\n';
    }

    return 0;
}
