N = int(input())
arr = [0]*(N+1)
sum = 0
for i in range(N):
    sum += int(input())
    arr[i+1] = sum
Q = int(input())
for i in range(Q):
    l,r = map(int, input().split())
    print(arr[r+1] - arr[l])