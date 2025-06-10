import sys

input = sys.stdin.readline


x, y = map(int, input().split())

z = (y * 100) // x

if z >= 99:
    print(-1)
else:

    ans = -1
    left = 1  
    right = x 

    while left <= right:
        mid = (left + right) // 2  


        new_z = ((y + mid) * 100) // (x + mid)


        if new_z > z:
            ans = mid         
            right = mid - 1  
        
        else:
            left = mid + 1    

    print(ans)