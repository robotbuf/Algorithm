import Foundation

func solution(_ s:String) -> [Int] {
    var str = s 
    var cnt = 0 
    var zeroCount = 0 
    while true {
        if str == "1" {
            break
        }
        var OCount = str.count 
        var newStr = str.filter { $0 == "1" }
        
        zeroCount += OCount - newStr.count
        
        str = String(newStr.count, radix: 2)
        cnt += 1 
    }
    
    
    
    return [cnt, zeroCount]
}