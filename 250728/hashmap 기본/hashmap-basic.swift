import Foundation

let n = Int(readLine()!)!
var commands = [(type: String, key: Int, value: Int?)]()

for _ in 0..<n {
    let parts = readLine()!.split(separator: " ").map { String($0) }
    let type = parts[0]
    let key = Int(parts[1])!
    var value: Int? = nil
    if type == "add" {
        value = Int(parts[2])!
    }
    commands.append((type, key, value))
}

var dic: [Int: Int] = [:]  

for command in commands {
    let type = command.type
    let key = command.key
    let value = command.value

    switch type {
    case "add":
        dic[key] = value
    case "find":
        if let found = dic[key] {
            print(found)
        } else {
            print("None")  
        }
    case "remove":
        dic[key] = nil
    default:
        break
    }
    
}
