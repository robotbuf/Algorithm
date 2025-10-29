import Foundation

let n = Int(readLine()!)!
var grid = [[Character]]()
for _ in 0..<n {
    grid.append(Array(readLine()!))
}

// 수집
var points: [(Int, Int)] = []     
var start = (-1, -1)
var end   = (-1, -1)

for i in 0..<n {
    for j in 0..<n {
        let ch = grid[i][j]
        if ("0"..."9").contains(ch) {
            points.append((i, j))
        } else if ch == "S" {
            start = (i, j)
        } else if ch == "E" {
            end = (i, j)
        }
    }
}

func dist(_ a: (Int,Int), _ b: (Int,Int)) -> Int {
    return abs(a.0 - b.0) + abs(a.1 - b.1)
}

guard points.count >= 3, start.0 != -1, end.0 != -1 else {
    print(-1)
    exit(0)
}

// 순열 길이 3 전수 + 가지치기
var used = Array(repeating: false, count: points.count)
var pickIdx: [Int] = []
var best = Int.max

func evaluate(_ p0: (Int,Int), _ p1: (Int,Int), _ p2: (Int,Int)) {
    var total = 0
    total += dist(start, p0)
    total += dist(p0, p1)
    total += dist(p1, p2)
    total += dist(p2, end)
    if total < best { best = total }
}

func dfs(_ depth: Int, _ curPos: (Int,Int), _ curCost: Int) {
    // 가지치기
    if curCost >= best { return }

    if depth == 3 {
        // 세 점 다 골랐을 때 E까지
        let last = points[pickIdx[2]]
        let total = curCost + dist(last, end)
        if total < best { best = total }
        return
    }

    for i in 0..<points.count {
        if used[i] { continue }
        used[i] = true
        pickIdx.append(i)

        let nextPos = points[i]
        // depth==0이면 S→p0, 그 외엔 이전 점→현재 점
        let add = dist(curPos, nextPos)
        dfs(depth + 1, nextPos, curCost + add)

        pickIdx.removeLast()
        used[i] = false
    }
}

// 시작: 아직 고른 점 없음 → 현재 위치는 S, 비용 0
dfs(0, start, 0)

print(best)