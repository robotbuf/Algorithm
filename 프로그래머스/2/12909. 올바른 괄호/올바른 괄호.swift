import Foundation

func solution(_ s: String) -> Bool {
    
    var st: [Character] = []

   
    for char in s {
        if char == "(" {
            st.append(char)
        } else if char == ")" {
            if !st.isEmpty {
                st.popLast()
            } else {
                return false
            }
        }
      
    }

   
    return st.isEmpty
}