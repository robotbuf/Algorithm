import Foundation

let MOD = 1_000_000_007
let n = Int(readLine()!)!

// n이 작을 때 바로 반환
if n == 0 { print(1); exit(0) }
if n == 1 { print(2); exit(0) }

// dp 배열
var dp = Array(repeating: 0, count: n + 1)
dp[0] = 1
dp[1] = 2
dp[2] = 7  // 미리 채워두고 시작

if n >= 3 {
    for i in 3...n {
        // 3*dp[i-1] + dp[i-2] - dp[i-3] (mod 처리 주의)
        let v = (3 * dp[i-1] + dp[i-2] - dp[i-3]) % MOD
        dp[i] = (v + MOD) % MOD
    }
}

print(dp[n])
