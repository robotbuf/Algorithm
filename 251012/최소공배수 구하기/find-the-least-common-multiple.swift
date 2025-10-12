import Foundation

let input = readLine()!.components(separatedBy: " ")
let n = Int(input[0])!
let m = Int(input[1])!

// Please write your code here.

func gcd(_ a: Int, _ b: Int) -> Int {
     var x = a 
     var y = b 
     
     while(y != 0) {
        var r = x % y 
        x = y
        y = r 
     }

     return x
}

print(n*m/gcd(n,m))