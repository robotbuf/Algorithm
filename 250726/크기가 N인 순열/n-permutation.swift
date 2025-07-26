import Foundation

let n = Int(readLine()!)!

var res: [Int] = []
var visited = Array(repeating: false, count: n + 1) // index 1 ~ n

func back() {
    if res.count == n {
        print(res.map { String($0) }.joined(separator: " "))
        return
    }

    for i in 1...n {
        if !visited[i] {
            visited[i] = true
            res.append(i)
            back()
            res.removeLast()
            visited[i] = false
        }
    }
}

back()
