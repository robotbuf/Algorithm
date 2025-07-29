import Foundation

let nm = readLine()!.split(separator: " ").map { Int(String($0))! }
let n = nm[0]
let m = nm[1]

var words = [String]()
for _ in 0..<n {
    words.append(readLine()!)
}

var queries = [String]()
for _ in 0..<m {
    queries.append(readLine()!)
}

var dict: [String: Int] = [:]
for (i, word) in words.enumerated() {
    dict[word] = i + 1
}

for query in queries {
    if let num = Int(query) {
        
        if num >= 1 && num <= n {
            print(words[num - 1])
        } else {
            print("Invalid number")
        }
    } else {
     
        if let idx = dict[query] {
            print(idx)
        } else {
            print("Not found")
        }
    }
}
