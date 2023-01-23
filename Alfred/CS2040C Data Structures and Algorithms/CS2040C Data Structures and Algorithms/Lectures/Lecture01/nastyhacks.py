# there is one character bug in this code, submitting it verbatim will give you Wrong Answer
# and I (think) will know that you did that

# please use these sample AC code for your reference only and recode using your own coding style+understanding
# then you will get the knowledge

n = int(input())
for i in range(n):
    r,e,c = map(int, input().split())
    if e-c >= r:
        print("advertise")
    elif e-c == r:
        print("does not matter")
    else:
        print("do not advertise")
