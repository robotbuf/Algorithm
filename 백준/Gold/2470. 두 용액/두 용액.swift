import Foundation

let n = Int(readLine()!)!
let arr = readLine()!.split(separator: " ").map { Int($0)! }.sorted()

var left = 0
var right = n - 1

var ans = (arr[left], arr[right])
var minAbsSum = abs(arr[left] + arr[right])

while left < right {
    let sum = arr[left] + arr[right]

    if abs(sum) < minAbsSum {
        minAbsSum = abs(sum)
        ans = (arr[left], arr[right])
    }

    if sum < 0 {
        left += 1
    } else if sum > 0 {
        right -= 1
    } else {
        ans = (arr[left], arr[right])
        break
    }
}

print("\(ans.0) \(ans.1)")
