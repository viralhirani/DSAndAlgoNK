def fectorial(n):
    if n==1:
        return 1
    else:
        return n*fectorial(n-1)

print(fectorial(4))