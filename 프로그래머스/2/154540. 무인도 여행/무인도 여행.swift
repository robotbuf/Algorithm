import Foundation

func solution(_ maps: [String]) -> [Int] {
    let n = maps.count
    let m = maps[0].count
    var grid = maps.map { Array($0) }
    var visited = Array(
        repeating: Array(repeating: false, count: m),
        count: n
    )
    let directions = [(-1,0),(1,0),(0,-1),(0,1)]
    var result: [Int] = []
    
    for i in 0..<n {
        for j in 0..<m {
           
            guard !visited[i][j], grid[i][j] != "X" else { continue }
            
            visited[i][j] = true
            var queue: [(Int,Int)] = [(i,j)]
            var head = 0
            var sum = Int(String(grid[i][j]))!
            
            while head < queue.count {
                let (x,y) = queue[head]
                head += 1
                
                for (dx, dy) in directions {
                    let nx = x + dx, ny = y + dy
                    if nx >= 0, nx < n, ny >= 0, ny < m,
                       !visited[nx][ny], grid[nx][ny] != "X" {
                        
                        visited[nx][ny] = true
                        sum += Int(String(grid[nx][ny]))!
                        queue.append((nx, ny))
                    }
                }
            }
            
            result.append(sum)
        }
    }
    
    return result.isEmpty ? [-1] : result.sorted()
}
