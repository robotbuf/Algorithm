import Foundation

let nk = readLine()!.split(separator: " ").compactMap { Int($0) }
let n = nk[0], k = nk[1]
let dolls = readLine()!.split(separator: " ").compactMap { Int($0) }


var lions = [Int]()
for i in 0..<n where dolls[i] == 1 {
    lions.append(i)
}

guard lions.count >= k else {
    print(-1)
    exit(0)
}

var result = n + 1
for start in 0...(lions.count - k) {
    let end = start + k - 1
    let length = lions[end] - lions[start] + 1
    result = min(result, length)
}

print(result)
