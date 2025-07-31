import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }
let n = input[0], m = input[1]
let s = Array(readLine()!)
let required = readLine()!.split(separator: " ").map { Int($0)! }

let charIdx: [Character:Int] = ["A":0, "C":1, "G":2, "T":3]

var countArr = [Int](repeating: 0, count: 4)

for i in 0..<m {
    let idx = charIdx[s[i]]!
    countArr[idx] += 1
}


func isValid() -> Bool {
    for i in 0..<4 {
        if countArr[i] < required[i] {
            return false
        }
    }
    return true
}

var answer = 0
if isValid() {
    answer += 1
}

for i in m..<n {
    let addIdx = charIdx[s[i]]!
    countArr[addIdx] += 1
    
    let removeIdx = charIdx[s[i - m]]!
    countArr[removeIdx] -= 1
    
    if isValid() {
        answer += 1
    }
}

print(answer)
