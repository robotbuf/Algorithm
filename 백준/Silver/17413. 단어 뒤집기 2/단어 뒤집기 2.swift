import Foundation


func reverseWordsPreservingTags(_ input: String) -> String {
    var result = ""
    var word = ""
    var inTag = false

    for char in input {
        switch char {
        case "<":
            result += word.reversed()
            word = ""
            inTag = true
            result.append(char)

        case ">":
            inTag = false
            result.append(char)

        case " " where !inTag:
            result += word.reversed() + " "
            word = ""

        default:
            if inTag {
                result.append(char)
            } else {
                word.append(char)
            }
        }
    }
    result += word.reversed()
    return result
}


let input = readLine()!
print(reverseWordsPreservingTags(input))
