import Foundation

let n = Int(readLine()!)!
var dict = [String: Bool]()

for _ in 0..<n {
    let parts = readLine()!.split(separator: " ").map(String.init)
    let name = parts[0], action = parts[1]
    if action == "enter" {
        dict[name] = true
    } else {
        dict[name] = false
    }
}

let result = dict
    .filter { $0.value }
    .map { $0.key }
    .sorted(by: >)

for name in result {
    print(name)
}
