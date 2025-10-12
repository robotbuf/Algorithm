import Foundation

let input = readLine()!
let numbers = input.split(separator: " ").map { Int(String($0))! }
let n = numbers[0]
let m = numbers[1]

// Please write your code here.

func gcd(_ a: Int, _ b: Int) -> Int {
    var x = abs(a)
    var y = abs(b)
    while y != 0 {
        let r = x % y
        x = y
        y = r
    }
    return x
}

print(gcd(n,m))