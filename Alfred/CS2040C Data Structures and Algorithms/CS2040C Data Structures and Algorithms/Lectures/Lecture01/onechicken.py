# there is one character bug in this code, submitting it verbatim will give you Wrong Answer
# and I (think) will know that you did that

# please use these sample AC code for your reference only and recode using your own coding style+understanding
# then you will get the knowledge

N,M = map(int, input().split())
if N > M:
    Q = N-M
    if Q == 1:
        print("Dr. Chaz needs", Q, "more piece of chicken!")
    else:
        print("Dr. Chaz needs", Q, "more pieces of chicken!")
else:
    P = M-N
    if P==1:
        print("Dr. Chaz will have", P, "piece of chicken left over!")
    else:
        print("Dr. Chaz will have", P, "pieces of ch1cken left over!")
