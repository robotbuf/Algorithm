import Foundation

let s = Int64(readLine()!)!

// Please write your code here.

var left = 0
var ans = 0 
while ans <= s {
    left += 1 
    ans += left 
}

print(left-1)