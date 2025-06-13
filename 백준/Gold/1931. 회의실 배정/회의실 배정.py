import sys
import heapq
input = sys.stdin.readline

def main():
    n = int(input().strip())
    room = []
    for _ in range(n):
        a, b = map(int, input().split())
        heapq.heappush(room, (b, a))

    count = 0
    last_end = 0

    while room:
        end, start = heapq.heappop(room)
        if start >= last_end:
            count += 1
            last_end = end

    print(count)

if __name__ == "__main__":
    main()
