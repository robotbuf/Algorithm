import Foundation

func solution(_ n: Int, _ words: [String]) -> [Int] {
    var used = Set<String>()
    
    for (i, word) in words.enumerated() {
        if used.contains(word) {
            let person = (i % n) + 1
            let turn   = (i / n) + 1
            return [person, turn]
        }
        used.insert(word)
        
        
        if i > 0 {
            let prev = words[i - 1]
            guard let lastChar = prev.last,
                  let firstChar = word.first,
                  lastChar == firstChar else {
                let person = (i % n) + 1
                let turn   = (i / n) + 1
                return [person, turn]
            }
        }
    }
    
    
    return [0, 0]
}
