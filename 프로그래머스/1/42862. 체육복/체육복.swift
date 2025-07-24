import Foundation

func solution(_ n:Int, _ lost:[Int], _ reserve:[Int]) -> Int {
    var remain = n - lost.count
    let reserveSorted = reserve.sorted()
    let lostSorted    = lost.sorted()
    
    // lost 처리 여부와 reserve 사용 여부
    var visitedLost    = Array(repeating: false, count: n + 2)
    var usedReserve    = Array(repeating: false, count: n + 2)
    
    // 1) 자기 자신에게 체육복 쓰기
    for r in reserveSorted {
        for l in lostSorted where !visitedLost[l] {
            if r == l {
                remain += 1
                visitedLost[l] = true
                usedReserve[r] = true   // r번 reserve 사용 처리
                break
            }
        }
    }
    
    // 2) 옆 친구에게 빌려주기 (단, 이미 사용한 reserve 스킵)
    for r in reserveSorted where !usedReserve[r] {
        for l in lostSorted where !visitedLost[l] {
            if abs(r - l) == 1 {
                remain += 1
                visitedLost[l] = true
                usedReserve[r] = true
                break
            }
        }
    }
    
    return remain
}

