import Foundation

let firstLine = readLine()!
let firstParts = firstLine.split(separator: " ").map { Int(String($0))! }
let n = firstParts[0]
let k = firstParts[1]

let secondLine = readLine()!
let arr = secondLine.split(separator: " ").map { Int(String($0))! }

var prefixSum: [Int] = Array(repeating: 0, count: n + 1)

for i in 1...n {
    prefixSum[i] = prefixSum[i - 1] + arr[i - 1]
}

var ans = 0


for i in 0..<n {
    for j in i..<n {
        let sum = prefixSum[j + 1] - prefixSum[i]
        if sum == k {
            ans += 1
        }
    }
}

print(ans)
