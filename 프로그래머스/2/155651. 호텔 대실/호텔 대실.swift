import Foundation

struct MinHeap<T: Comparable> {
    private var data = [T]()
    private let order: (T, T) -> Bool

    init(order: @escaping (T, T) -> Bool) {
        self.order = order
    }

    var isEmpty: Bool { data.isEmpty }
    var count: Int { data.count }
    func peek() -> T? { data.first }

    mutating func push(_ value: T) {
        data.append(value)
        siftUp(from: data.count - 1)
    }

    @discardableResult
    mutating func pop() -> T? {
        guard !data.isEmpty else { return nil }
        data.swapAt(0, data.count - 1)
        let val = data.removeLast()
        siftDown(from: 0)
        return val
    }

    private mutating func siftUp(from index: Int) {
        var child = index
        var parent = (child - 1) / 2
        while child > 0 && order(data[child], data[parent]) {
            data.swapAt(child, parent)
            child = parent
            parent = (child - 1) / 2
        }
    }

    private mutating func siftDown(from index: Int) {
        let n = data.count
        var parent = index
        while true {
            let left = 2 * parent + 1
            let right = left + 1
            var candidate = parent

            if left < n && order(data[left], data[candidate]) {
                candidate = left
            }
            if right < n && order(data[right], data[candidate]) {
                candidate = right
            }
            guard candidate != parent else { break }
            data.swapAt(parent, candidate)
            parent = candidate
        }
    }
}

private func toMinutes(_ s: String) -> Int {
    let parts = s.split(separator: ":").compactMap { Int($0) }
    return (parts.first ?? 0) * 60 + (parts.last ?? 0)
}

func solution(_ book_time: [[String]]) -> Int {
    
    let intervals = book_time
        .map { (toMinutes($0[0]), toMinutes($0[1]) + 10) }
        .sorted { $0.0 < $1.0 }

    var heap = MinHeap<Int>(order: <)
    var maxRooms = 0

    for (start, endWithClean) in intervals {
        
        if let earliestEnd = heap.peek(), start >= earliestEnd {
            heap.pop()
        }
        heap.push(endWithClean)
        maxRooms = max(maxRooms, heap.count)
    }

    return maxRooms
}
