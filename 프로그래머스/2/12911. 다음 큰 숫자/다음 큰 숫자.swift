import Foundation

func solution(_ n:Int) -> Int
{
    let bin = String(n, radix: 2)
    
    let len = Array(bin).filter { $0 == "1" }.count 
    
    var ans = 0 
    
    var num = n + 1 
    
    while true {
        let b = String(num, radix: 2)
        let cmp = Array(b).filter { $0 == "1" }.count 
        if cmp == len {
            ans = num 
            break 
        } else {
            num += 1 
        }
    }
    
    
    
    return ans
}