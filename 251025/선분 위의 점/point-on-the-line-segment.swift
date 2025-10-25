import Foundation

let firstLine = readLine()!.split(separator: " ").map { Int(String($0))! }
let n = firstLine[0]
let m = firstLine[1]

let points = readLine()!.split(separator: " ").map { Int(String($0))! }

var queries: [(Int, Int)] = []
for _ in 0..<m {
    let queryLine = readLine()!.split(separator: " ").map { Int(String($0))! }
    queries.append((queryLine[0], queryLine[1]))
}

// Please write your code here.
    for query in queries {
        var cnt = 0

        for target in points {
            var left = query.0 
            var right = query.1 
            if left > target || right < target {
            continue 
            }
        
            while left <= right {
                let mid = (left + right) / 2 
            
                if mid == target {
                    cnt += 1 
                 break
                 } else if mid < target {
                    left = mid+1 
                } else {
                right = mid-1
                }
        }
        }
         print(cnt)
    }