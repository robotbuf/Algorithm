import Foundation

guard let nLine = readLine(), let n = Int(nLine) else { fatalError() }
var grid = [[Int]]()

for _ in 0..<n {
    let row = readLine()!.split(separator: " ").map { Int($0)! }
    grid.append(row)
}
var ans = 0 

func check(_ x: Int, _ y: Int) -> Int {
    var cnt = 0 
    for i in x...x+2 {
        for j in y...y+2 {
            if grid[i][j] == 1 {
                cnt += 1 
            }
        }
    }
    return cnt 
}

for i in 0...n-3 {
    for j in 0...n-3 {
        ans = max(ans, check(i,j))
    }
}

print(ans)

