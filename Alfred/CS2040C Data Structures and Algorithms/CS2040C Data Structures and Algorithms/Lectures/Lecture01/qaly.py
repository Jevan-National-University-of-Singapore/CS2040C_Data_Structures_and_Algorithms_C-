# there is one character bug in this code, submitting it verbatim will give you Wrong Answer
# and I (think) will know that you did that

# please use these sample AC code for your reference only and recode using your own coding style+understanding
# then you will get the knowledge

N = int(input())
ans = 0
for i in range(0, N+1):
    q,y = map(float, input().split())
    ans = ans+q*y
print(ans)
