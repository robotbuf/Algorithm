#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    map<string, int> wordCount;

    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;
        if (word.length() >= M) {
            wordCount[word]++;
        }
    }

    
    vector<pair<string, int>> words(wordCount.begin(), wordCount.end());

 
    sort(words.begin(), words.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second) return a.second > b.second; 
        if (a.first.length() != b.first.length()) return a.first.length() > b.first.length(); // 길이
        return a.first < b.first; 
    });

    for (const auto& word : words) {
        cout << word.first << '\n';
    }

    return 0;
}
