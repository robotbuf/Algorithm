import Foundation

func solution(_ s:String) -> [Int] {
    
    var str = s 
    var ansCount = 0
    var ans = 0
    
    while str != "1" {
        let origin = str.count 
        
        str = str.filter { $0 == "1" }
        ansCount += origin - str.count 
        
        str = String(str.count, radix: 2)
        ans += 1 
    }
    return [ans,ansCount]
}