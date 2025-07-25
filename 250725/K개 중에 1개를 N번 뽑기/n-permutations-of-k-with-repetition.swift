import Foundation

let input = readLine()!.split(separator: " ").map { Int($0)! }
let k = input[0]
let n = input[1]

var arr: [Int] = []

func back() {
    if arr.count == n {
        print(arr.map { String($0) }.joined(separator: " "))
        return
    }

    for i in 1..<k+1 {
        arr.append(i)
        back() 
        arr.removeLast()
    }
}

back()
