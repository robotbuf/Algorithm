import Foundation

let firstLine = readLine()!.split(separator: " ").map { Int($0)! }
let n = firstLine[0]
let k = firstLine[1]
var grid = [[Int]]()
for _ in 0..<n {
    let row = readLine()!.split(separator: " ").map { Int($0)! }
    grid.append(row)
}

// Please write your code here.

var prefixSum = Array(repeating: Array(repeating: 0, count: 4), count: 4)

for i in 1...n {
    for j in 1...n {
        prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1]
                        - prefixSum[i - 1][j - 1] + grid[i - 1][j - 1]
    }
}

var maxSum = Int.min

for i in k...n {
    for j in k...n {
        let x1 = i - k + 1, y1 = j - k + 1
        let x2 = i, y2 = j
        let total = prefixSum[x2][y2]
                   - prefixSum[x1 - 1][y2]
                   - prefixSum[x2][y1 - 1]
                   + prefixSum[x1 - 1][y1 - 1]
        maxSum = max(maxSum, total)
    }
}

print(maxSum)