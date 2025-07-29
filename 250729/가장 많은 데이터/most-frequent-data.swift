import Foundation

let n = Int(readLine()!)!
var words: [String] = []

var dict: [String: Int] = [:]
var ans = 0 

for _ in 0..<n {
    let word = readLine()!
    dict[word, default: 0] += 1
    ans = max(ans, dict[word, default: 0])
}


print(ans)




