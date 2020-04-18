floor = []
def flood_fill(x, y):
    if x<0 or y<0 or x>=len(floor) or y>=len(floor[0]):
        return 0
    if floor[x][y] == 'I':
        return 0
    floor[x][y] = 'I'
    out = 1 + flood_fill(x+1,y) + flood_fill(x-1,y) + flood_fill(x,y+1) + flood_fill(x,y-1)
    return out

max = int(input())
rows = int(input())
cols = int(input())

sizes = []
for i in range(0,rows):
    floor.append(input())
for i in range(0,rows):
    for j in range(0,cols):
        if floor[i][j] == '.':
            sizes.append(flood_fill(i,j))
sizes.sort(reverse = 1)
used = 0
tally = 0
for i in range(0,len(sizes)):
    used = used + sizes[i]
    if used > max:
        used = used - sizes[i]
        break
    tally = tally+1
print(tally + (" rooms, " if tally > 1 else " room, ") + (max - used) +" square metre(s) left over" )