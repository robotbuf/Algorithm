import Foundation
let s = Int64(readLine()!)!


var left: Int64 = 0
var right: Int64 = s
var ans: Int64 = 0

while left <= right {
    let mid = (left + right) / 2
    let sum = mid * (mid + 1) / 2  // O(1) 계산

    if sum <= s {
        ans = mid
        left = mid + 1
    } else {
        right = mid - 1
    }
}

print(ans)