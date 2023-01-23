def abc():
    line1 = input().split(" ")
    line2 = input()
    numbers = list(map(int,line1))
    numbers_sorted = []
    while numbers:
        smallest = numbers[0]
        for i in numbers:
            if i < smallest:
                smallest = i
        numbers.remove(smallest)
        numbers_sorted.append(smallest)
    numbers_final = []
    for i in range(len(line2)):
        if line2[i] == 'A':
            numbers_final.append(numbers_sorted[0])
        elif line2[i] == 'B':
            numbers_final.append(numbers_sorted[1])
        else:
            numbers_final.append(numbers_sorted[2])
    for x in numbers_final:
        print(x," ",end="")
    #or: print(*numbers_final)
