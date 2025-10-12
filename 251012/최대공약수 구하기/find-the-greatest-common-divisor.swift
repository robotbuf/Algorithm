import Foundation

let input = readLine()!
let numbers = input.split(separator: " ").map { Int(String($0))! }
let n = numbers[0]
let m = numbers[1]

// Please write your code here.

func gcd(_ a: Int, _ b: Int) -> Int {
    while(b != 0) {
        var r = a % b
        a = b 
        b = r 
    }

    return a 
}

print(gcd(n,m))