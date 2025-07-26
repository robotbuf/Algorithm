import Foundation

let n = Int(readLine()!)!

var res: [Int] = []
var visited: [Bool] = Array(repeating: false, count: n + 1) // 1-based 인덱스

func back() {
    if res.count == n {
        print(res.map { String($0) }.joined(separator: " "))
        return
    }
    
    for i in (1...n).reversed() {
        if !visited[i] {
            visited[i] = true
            res.append(i)
            
            back()
            
            visited[i] = false
            res.removeLast()
        }
    }
}

back()
