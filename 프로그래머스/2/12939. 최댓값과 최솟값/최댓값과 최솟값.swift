func solution(_ s: String) -> String {
    let nums = s.split(separator: " ").compactMap { Int($0) }

    guard var minNum = nums.first, var maxNum = nums.first else {
        return ""
    }

    for num in nums {
        if num < minNum { minNum = num }
        if num > maxNum { maxNum = num }
    }

    return "\(minNum) \(maxNum)"
}
