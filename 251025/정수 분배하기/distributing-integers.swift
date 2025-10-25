import Foundation

let firstLine = readLine()!.split(separator: " ").map { Int($0)! }
let n = firstLine[0]
let m = firstLine[1]
var nums = [Int]()
for _ in 0..<n {
    nums.append(Int(readLine()!)!)
}

nums.sort()

var start = 1
var end = nums[nums.count - 1]
var ans = 0

while start <= end {
    let mid = (start + end) / 2
    var cnt = 0
    for i in 0..<n {
        cnt += nums[i] / mid
    }

    if cnt >= m { 
        ans = mid 
        start = mid + 1 
    } else {
        end = mid - 1
    }
}

print(ans)
