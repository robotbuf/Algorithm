import Foundation

let n = Int(readLine()!)!
// Please write your code here.


var dp: [Int] = Array(repeating: -1, count: 1001)
func climb(_ n: Int) -> Int {
    if n < 0 {
        return 0
    }
    if n == 0 {
        return 1
    }

    if dp[n] != -1 {
        return dp[n]
    }

    dp[n] = climb(n - 2) + climb(n - 3)
    return dp[n]
}

print(climb(n))