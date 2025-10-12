let input = readLine()!
let tokens = input.split(separator: " ").map { Int($0)! }
let a = tokens[0]
let b = tokens[1]
let c = tokens[2]
let d = tokens[3]
// Please write your code here.

print((60*c+d) - (60*a+b))