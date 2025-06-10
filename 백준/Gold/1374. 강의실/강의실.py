import sys 
import heapq
input = sys.stdin.readline


n = int(input())
pq = []

lectures = [] 

for _ in range(n):
    num,start,end = map(int, input().split())
    lectures.append((start,end))

lectures.sort()

ans = 0

for start,end in lectures:
    if pq and pq[0] <= start:
        heapq.heappop(pq)
    
    heapq.heappush(pq,end)

    if len(pq) > ans:
        ans = len(pq)



print(ans)
    