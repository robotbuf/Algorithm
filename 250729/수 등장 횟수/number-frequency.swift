let firstLine = readLine()!
let firstNumbers = firstLine.split(separator: " ").map { Int($0)! }
let n = firstNumbers[0]
let m = firstNumbers[1]

let numberList = readLine()!.split(separator: " ").map { Int($0)! }
let queryList = readLine()!.split(separator: " ").map { Int($0)! }

var count: [Int: Int] = [:]

for num in numberList {
    count[num, default: 0] += 1
}

var ans: [Int] = []

for query in queryList {
    ans.append(count[query, default: 0])
}

print(ans.map { String($0) }.joined(separator: " "))
