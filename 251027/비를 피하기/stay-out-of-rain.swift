import Foundation

let firstLine = readLine()!
let params = firstLine.split(separator: " ").map { Int(String($0))! }
let n = params[0]
let h = params[1]   // 문제에서 안 쓰면 그대로 둠
let m = params[2]   // 문제에서 안 쓰면 그대로 둠

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


let dx = [-1, 1, 0, 0]
let dy = [ 0, 0,-1, 1]

var dist = Array(repeating: Array(repeating: -1, count: n), count: n)

var qx = [Int](), qy = [Int]()
qx.reserveCapacity(n*n); qy.reserveCapacity(n*n)
var head = 0

for (sx, sy) in shelterPositions {
    dist[sx][sy] = 0
    qx.append(sx); qy.append(sy)
}

// 멀티 소스 BFS 한 번만 수행
while head < qx.count {
    let x = qx[head], y = qy[head]; head += 1
    let d = dist[x][y]
    for k in 0..<4 {
        let nx = x + dx[k], ny = y + dy[k]
        if nx < 0 || nx >= n || ny < 0 || ny >= n { continue }
        if grid[nx][ny] == 1 { continue }      
        if dist[nx][ny] != -1 { continue }     
        dist[nx][ny] = d + 1
        qx.append(nx); qy.append(ny)
    }
}


var ans = Array(repeating: Array(repeating: 0, count: n), count: n)


for i in 0..<n {
    for j in 0..<n {
        if grid[i][j] == 2 {
            ans[i][j] = dist[i][j]   
        } else {
            ans[i][j] = 0             
        }
    }
}
var out = ""
out.reserveCapacity(n * n * 2)
for row in ans {
    out += row.map(String.init).joined(separator: " ") + "\n"
}
print(out, terminator: "")