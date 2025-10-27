import Foundation

let firstLine = readLine()!
let params = firstLine.split(separator: " ").map { Int(String($0))! }
let n = params[0]
let h = params[1]
let m = params[2]

var grid = [[Int]]()
var shelterPositions = [(Int, Int)]()

for i in 0..<n {
    let rowInput = readLine()!
    let row = rowInput.split(separator: " ").map { Int(String($0))! }
    grid.append(row)
    for j in 0..<n {
        if row[j] == 3 {
            shelterPositions.append((i, j))
        }
    }
}

// Please write your code here.
let dx = [-1,1,0,0]
let dy = [0,0,-1,1]

var ans = Array(repeating: Array(repeating: Int.max, count: m), count: n)

func bfs(_ a: Int, _ b: Int) {
    var q: [(Int,Int,Int)] = []
    var visited = Array(repeating: Array(repeating: false, count: m), count: n)

    q.append((a,b,0))
    visited[a][b] = true

    while !q.isEmpty {
        let node = q.removeFirst() 
        let x = node.0 
        let y = node.1
        let cnt = node.2 

        if grid[x][y] == 2 {
            ans[x][y] = min(ans[x][y], cnt)
        }
        
        for i in 0..<4 {
            let nx = x + dx[i]
            let ny = y + dy[i]

            if 0<=nx && nx<n && 0<=ny && ny<m && !visited[nx][ny] {
                if grid[nx][ny] != 1 {
                    q.append((nx,ny,cnt+1))
                    visited[nx][ny] = true 
                }
            }
        }

    }
}

for i in 0..<n {
    for j in 0..<m {
        if grid[i][j] == 3 {
            bfs(i,j)
        }
    }
}

print(ans)