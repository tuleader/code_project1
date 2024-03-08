n = int(input())
for i in range(2**n):
    binary = format(i,f'0{n}b')
    print(binary)
