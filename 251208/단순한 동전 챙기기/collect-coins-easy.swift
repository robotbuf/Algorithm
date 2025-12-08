import Foundation

let n = Int(readLine()!)!
var grid = [[Character]]()
for _ in 0..<n {
    grid.append(Array(readLine()!))
}

// 숫자 좌표 + 값, S, E 수집
var nums: [(val: Int, x: Int, y: Int)] = []
var start = (-1, -1)
var end   = (-1, -1)

for i in 0..<n {
    for j in 0..<n {
        let ch = grid[i][j]
        if ("0"..."9").contains(ch) {
            let v = Int(String(ch))!
            nums.append((v, i, j))
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

guard start.0 != -1, end.0 != -1, nums.count >= 3 else {
    print(-1)
    exit(0)
}

// 숫자값 오름차순으로 정렬 후, 가장 작은 3개만 사용
nums.sort { $0.val < $1.val }
let path = [(start.0, start.1),
            (nums[0].x, nums[0].y),
            (nums[1].x, nums[1].y),
            (nums[2].x, nums[2].y),
            (end.0, end.1)]

// S -> v1 -> v2 -> v3 -> E 누적 맨해튼 거리
var answer = 0
for i in 0..<(path.count - 1) {
    answer += dist(path[i], path[i + 1])
}
print(answer)
