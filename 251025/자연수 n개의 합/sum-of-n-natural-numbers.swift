import Foundation

let s = Int(readLine()!)!

// 누적합 배열 초기화
var sum = [0]
for i in 1...s {
    sum.append(sum[i-1] + i)
}

// 이진 탐색
var left = 0
var right = s
var ans = 0

while left <= right {
    let mid = (left + right) / 2
    if sum[mid] <= s {
        ans = mid
        left = mid + 1
    } else {
        right = mid - 1
    }
}

print(ans)
