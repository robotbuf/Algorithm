import Foundation

let firstLine = readLine()!
let nm = firstLine.split(separator: " ").map { Int(String($0))! }
let n = nm[0]
let m = nm[1]
var grid = [[Int]]()
for _ in 0..<n {
    let row = readLine()!.split(separator: " ").map { Int(String($0))! }
    grid.append(row)
}

// Please write your code here.
let dx = [1,0,-1,0]
let dy = [0,1,0,-1]


var ans = Int.max
var visited: [[Bool]] = Array(repeating: Array(repeating: false, count: m), count: n)
func bfs() {
    var q: [(Int,Int,Int)] = [] 
    q.append((0,0,0))
    visited[0][0] = true 
    
    while !q.isEmpty {
        var node = q.removeFirst()
        var x = node.0 
        var y = node.1 
        var cnt = node.2

        if x == n-1 && y == m-1 {
            ans = min(ans,cnt)
        }
        
        for i in 0..<4 {
            var nx = x + dx[i]
            var ny = y + dy[i]
            
            if(0<=nx && nx<n && 0<=ny && ny<m) {
                if !visited[nx][ny] && grid[nx][ny] == 1 {
                    visited[nx][ny] = true 
                    q.append((nx,ny,cnt+1))
                }
            }
        }
    }
    
}
bfs()

if ans == Int.max {
    print(-1)
} else {
    print(ans)
}