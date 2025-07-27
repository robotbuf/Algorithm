import Foundation

let n = Int(readLine()!)!

// Please write your code here.
var dp: [Int] = Array(repeating: -1, count: 1001)


func gongsu(_ n: Int) -> Int {
    if n == 0 { return 1 }  
    if n == 1 { return 1 }  

    if dp[n] != -1 {
        return dp[n]
    }

    dp[n] = (gongsu(n - 1) + gongsu(n - 2)) % 10007
    return dp[n]
}

print(gongsu(n))