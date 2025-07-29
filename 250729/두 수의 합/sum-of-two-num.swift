import Foundation

let firstLine = readLine()!.split(separator: " ").map { Int(String($0))! }
let n = firstLine[0]
let k = firstLine[1]
let arr = readLine()!.split(separator: " ").map { Int(String($0))! }

var freq = [Int: Int]()   // 값 → 등장 횟수
var count = 0

for x in arr {
    let need = k - x
    if let c = freq[need] {
        
        count += c
    }
    
    freq[x, default: 0] += 1
}

print(count)
