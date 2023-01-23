def hothike():
    days = int(input())
    line2 = input().split(" ")
    t = [int(i) for i in line2]
    x = 41
    x1,x2 = 41,41
    for i in range(0,days - 2):
        if t[i] > x or t[i+2] > x or t[i] == t[i+2] == x:
            continue
        if t[i] == x == x1:
            if t[i+2] >= x2:
                continue
            else:
                x2 = t[i+2]
                d = i+1
                continue
        if t[i+2] == x == x2:
            if t[i] >= x1:
                continue
            else:
                x1 = t[i]
                d = i+1
                continue
        if t[i] == x == x2:
            if t[i+2] >= x1:
                continue
            else:
                x1 = t[i+2]
                d = i+1
                continue
        if t[i+2] == x == x1:
            if t[i] >= x2:
                continue
            else:
                x2 = t[i]
                d = i+1
                continue
        if t[i] < x and t[i+2] < x:
            x1 = t[i]
            x = x2 = t[i+2]
            if t[i] >= t[i+2]:
                x = t[i]
            d = i + 1
    print(d,x,sep=' ')
      
