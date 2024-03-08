def check(binary):
    for i in range(len(binary) - 1):
        if binary[i:i+2] == '11':
            return True
    return False
n = int(input())
count = 0
for i in range(2**n):
    binary = format(i,f'0{n}b')
    if not check(binary):
        print(binary)
