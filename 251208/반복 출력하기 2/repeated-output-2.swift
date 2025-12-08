import Foundation

let n = Int(readLine()!)!

// Please write your code here.

func hello(_ k: Int) {
    if k == n {
        return
    }
    print("HelloWorld")
    hello(k+1)
}

hello(0)