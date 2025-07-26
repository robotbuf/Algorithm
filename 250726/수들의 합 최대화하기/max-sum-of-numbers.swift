import Foundation

let n = Int(readLine()!)!
var grid = [[Int]]()
for _ in 0..<n {
    let row = readLine()!.split(separator: " ").map { Int($0)! }
    grid.append(row)
}

// Please write your code here.

var res: [Int] = [] 
var visited: [Bool] = Array(repeating: false, count: n+1)



var ans = 0

func backtrack() {
    
    
    if res.count == n {
        var sum = 0
        for i in 0..<n {
            sum += grid[i][res[i]]
        }
        ans = max(ans,sum)
        return
    }
    for i in 0..<n {
        if !visited[i] {
            res.append(i)
            visited[i] = true 
            backtrack() 
            res.removeLast() 
            visited[i] = false 
        }
    }
}
backtrack()
print(ans)