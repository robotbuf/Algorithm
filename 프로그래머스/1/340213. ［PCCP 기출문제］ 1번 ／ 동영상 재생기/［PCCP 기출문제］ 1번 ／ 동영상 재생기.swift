import Foundation

func solution(
    _ video_len: String,
    _ pos: String,
    _ op_start: String,
    _ op_end: String,
    _ commands: [String]
) -> String {
    
    func toSeconds(_ time: String) -> Int {
        let parts = time.split(separator: ":")
        let m = Int(parts[0]) ?? 0
        let s = Int(parts[1]) ?? 0
        return m * 60 + s
    }
    
    func toTimeString(_ sec: Int) -> String {
        let m = sec / 60
        let s = sec % 60
        // 두 자릿수 보장
        return String(format: "%02d:%02d", m, s)
    }
    
    let videoLenSec = toSeconds(video_len)
    var current = toSeconds(pos)
    let opStartSec = toSeconds(op_start)
    let opEndSec   = toSeconds(op_end)
    
    if opStartSec <= current && current <= opEndSec {
        current = opEndSec
    }

    
    for cmd in commands {
        switch cmd {
        case "prev":
            current = max(0, current - 10)
        case "next":
            current = min(videoLenSec, current + 10)
        default:
            break
        }
        if opStartSec <= current && current <= opEndSec {
            current = opEndSec
        }
    }
    
    return toTimeString(current)
}
