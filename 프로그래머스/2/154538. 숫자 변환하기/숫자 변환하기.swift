import Foundation

func solution(_ x:Int, _ y:Int, _ n:Int) -> Int {
    var visited = [Bool](repeating: false, count: y+1)
    var q: [(node: Int, cnt: Int)] = []
    var head = 0

    q.append((x, 0))
    visited[x] = true

    while head < q.count {
        let (node, cnt) = q[head]
        head += 1

        if node == y { 
            return cnt 
        }

        let candidates = [node + n, node * 2, node * 3]
        for newNode in candidates {
            if newNode <= y && !visited[newNode] {
                visited[newNode] = true
                q.append((newNode, cnt + 1))
            }
        }
    }

    return -1
}