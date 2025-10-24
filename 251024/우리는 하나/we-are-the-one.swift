import Foundation

// 입력
let first = readLine()!.split(separator: " ").map { Int($0)! }
let n = first[0], k = first[1], u = first[2], d = first[3]

var a = Array(repeating: Array(repeating: 0, count: n), count: n)
for i in 0..<n {
    let row = readLine()!.split(separator: " ").map { Int($0)! }
    for j in 0..<n { a[i][j] = row[j] }
}

// 방향
let dr = [1, -1, 0, 0]
let dc = [0, 0, 1, -1]

var answer = 0
var picked: [Int] = [] 

func evaluateCurrentPick() {
    var visited = Array(repeating: Array(repeating: false, count: n), count: n)
    var q: [Int] = []
    q.reserveCapacity(n * n)
    var head = 0

    for idx in picked {
        let r = idx / n, c = idx % n
        if !visited[r][c] {
            visited[r][c] = true
            q.append(idx)
        }
    }

    var cnt = 0
    while head < q.count {
        let v = q[head]; head += 1
        let r = v / n, c = v % n
        cnt += 1
        let curr = a[r][c]

        for t in 0..<4 {
            let nr = r + dr[t], nc = c + dc[t]
            if nr < 0 || nr >= n || nc < 0 || nc >= n { continue }
            if visited[nr][nc] { continue }
            let diff = abs(a[nr][nc] - curr)
            if diff < u || diff > d { continue }
            visited[nr][nc] = true
            q.append(nr * n + nc)
        }
    }
    if cnt > answer { answer = cnt }
}

func dfs(_ start: Int, _ left: Int) {
    if left == 0 {
        evaluateCurrentPick()
        return
    }
    let limit = n * n
    var i = start
    while i <= limit - left {
        picked.append(i)
        dfs(i + 1, left - 1)
        picked.removeLast()
        i += 1
    }
}

dfs(0, k)
print(answer)
