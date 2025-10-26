import Foundation

let n = Int64(readLine()!.trimmingCharacters(in: .whitespacesAndNewlines))!

// 1..15에서 "숫자(3·5의 배수 아님)"로 남는 값들 — 15마다 반복
let residues: [Int64] = [1, 2, 4, 7, 8, 11, 13, 14] // 8개

let block = (n - 1) / 8          // 0-based 블록 인덱스
let idx   = Int((n - 1) % 8)     // 블록 내 위치
let ans   = block * 15 + residues[idx]

print(ans)