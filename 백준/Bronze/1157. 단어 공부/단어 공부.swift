import Foundation


let input = readLine()!

var visited: [String: Int] = [:]

var maxchar = String()
var maxcnt = 0
for ch in input {
    visited[ch.uppercased(), default: 0] += 1
    
    if maxcnt < visited[ch.uppercased()] ?? 0 {
        maxchar = ch.uppercased()
        maxcnt = visited[ch.uppercased()] ?? 0
    }
}

var cmp = 0

for v in visited {
    if v.value == maxcnt {
        cmp += 1
    }
}


print(cmp > 1 ? "?" : maxchar)
