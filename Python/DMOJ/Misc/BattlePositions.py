I = int(input())
N = int(input())
J = int(input())
a = [0]*(I+1)
for i in range(J):
    l,r,k = map(int, input().split())
    a[l-1] += k
    a[r]-=k
tally = 0
out = 0
for i in range(I):
    tally += a[i]
    if tally < N:
        out += 1
print(out)        