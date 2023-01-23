def climb():
    line = input().split(" ")
    numbers = [int(i) for i in line]
    a,b,h = numbers[0],numbers[1],numbers[2]
    def calculate(a,b,c):
        if a >= c:
            return 1
        else:
            c = c-a+b
            return 1 + calculate(a,b,c)
    print(calculate(a,b,h))
    
