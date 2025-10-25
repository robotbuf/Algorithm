import Foundation

let firstLine = readLine()!.split(separator: " ").map { Int(String($0))! }
let n = firstLine[0]
let m = firstLine[1]

let points = readLine()!.split(separator: " ").map { Int(String($0))! }

var queries: [(Int, Int)] = []
for _ in 0..<m {
    let queryLine = readLine()!.split(separator: " ").map { Int(String($0))! }
    queries.append((queryLine[0], queryLine[1]))
}

for query in queries {
    var cnt = 0
    let l = query.0
    let r = query.1

    for target in points {
        if target >= l && target <= r {
            cnt += 1
        }
    }

    print(cnt)
}