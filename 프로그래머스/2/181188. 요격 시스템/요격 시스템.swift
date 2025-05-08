import Foundation

func solution(_ targets:[[Int]]) -> Int {
    
    
    let sortedTargets = targets.sorted { $0[1] < $1[1] }
    
    var cnt = 0 
    var lastIndex = -1 
    
    for target in sortedTargets {
        let start = target[0]
        let end = target[1]
        
        if lastIndex >= start {
            continue 
        }
        
        cnt += 1
        lastIndex = end - 1 
    }
    
    return cnt
}