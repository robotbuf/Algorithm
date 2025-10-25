import Foundation

let s = Int64(readLine()!)!   // 입력값 최대 10^18

var left: Int64 = 0
var right: Int64 = 2_000_000_000  // n이 약 1.4e9 수준이라 이 정도면 충분
var ans: Int64 = 0

while left <= right {
    let mid = (left + right) / 2
    
    // mid*(mid+1)/2 계산 시 오버플로우 방지
    // → 중간 연산은 Int128처럼 처리할 수 없으니 Double로 한 번 변환
    let sum = Double(mid) * Double(mid + 1) / 2.0
    
    if sum <= Double(s) {
        ans = mid
        left = mid + 1
    } else {
        right = mid - 1
    }
}

print(ans)