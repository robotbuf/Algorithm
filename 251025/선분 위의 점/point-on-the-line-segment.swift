let points = readLine()!.split(separator: " ").map { Int(String($0))! }.sorted()

func lowerBound(_ arr: [Int], _ target: Int) -> Int {
    var left = 0, right = arr.count
    while left < right {
        let mid = (left + right) / 2
        if arr[mid] < target {
            left = mid + 1
        } else {
            right = mid
        }
    }
    return left
}

func upperBound(_ arr: [Int], _ target: Int) -> Int {
    var left = 0, right = arr.count
    while left < right {
        let mid = (left + right) / 2
        if arr[mid] <= target {
            left = mid + 1
        } else {
            right = mid
        }
    }
    return left
}

for query in queries {
    let l = query.0
    let r = query.1
    let count = upperBound(points, r) - lowerBound(points, l)
    print(count)
}
