import Foundation

func solution(_ k: Int, _ m: Int, _ score: [Int]) -> Int {
    var ans = 0
    var newScore = score
    
   
    newScore.sort(by: >)   
    
    
    var idx = 0
    var box: [Int] = []
    
   
    while idx <= newScore.count - m {
        for _ in 0..<m {
            box.append(newScore[idx])
            idx += 1
        }
    
        ans += box[m-1] * m
        box.removeAll()
    }

    return ans
}