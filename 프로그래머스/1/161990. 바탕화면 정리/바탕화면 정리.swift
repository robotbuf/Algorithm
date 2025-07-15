import Foundation

func solution(_ wallpaper: [String]) -> [Int] {
    let h = wallpaper.count
    let w = wallpaper.first?.count ?? 0

    var minRow = Int.max
    var minCol = Int.max
    var maxRow = Int.min
    var maxCol = Int.min

    for i in 0..<h {
        for (j, ch) in wallpaper[i].enumerated() {
            if ch == "#" {
                minRow = min(minRow, i)
                minCol = min(minCol, j)
                maxRow = max(maxRow, i)
                maxCol = max(maxCol, j)
            }
        }
    }

  
    guard minRow <= maxRow, minCol <= maxCol else {
        return []
    }


    return [minRow, minCol, maxRow + 1, maxCol + 1]
}
