import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }

let n = input[0]
let m = input[1]


var dict: [String: Bool] = [:]

for _ in 0..<n {
    let name = readLine()!
    
    dict[name,default: false] = true
}

var ans = 0

for _ in 0..<m {
    let name = readLine()!
    if dict[name,default: false] {
        ans += 1
    }
}

print(ans)
