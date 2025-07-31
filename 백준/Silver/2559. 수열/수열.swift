import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }
let n = input[0], m = input[1]
let arr = readLine()!.split(separator: " ").map { Int($0)! }


var windowSum = arr[0..<m].reduce(0, +)
var ans = windowSum


for i in m..<n {
    windowSum += arr[i]
    windowSum -= arr[i - m]  
    ans = max(ans, windowSum)
}

print(ans)
