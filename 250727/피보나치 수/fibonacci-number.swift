import Foundation

let n = Int(readLine()!)!

// Please write your code here.

var dp: [Int] = Array(repeating: -1, count: 46)


func fibo(_ n: Int) -> Int {
    if dp[n] != -1 {
        return dp[n]
    }
    if n <= 2 {
        dp[n] = 1
    } else {
        dp[n] = fibo(n-1) + fibo(n-2)
    }

    return dp[n]
}


print(fibo(n))