def giaHienTai(n):
    if n<= 50:
        return n*1728
    elif 50<n and n <= 100:
        return 50*1728+(n-50)*1786
    elif 100<n and n<=200:
        return 50*1728+50*1786+(n-100)*2074
    elif 200<n and n<=300:
        return 50*1728+50*1786+100*2074+(n-200)*2612
    elif 300<n and n<=400:
        return 50*1728+50*1786+100*2074+100*2612+(n-300)*2919
    else:
        return 50*1728+50*1786+100*2074+100*2612+100*2919+(n-400)*3015
def giaDuKien(n):
    if n<= 100:
        return n*1728
    elif 100<n and n <= 200:
        return 100*1728+(n-100)*2074
    elif 200<n and n<=400:
        return 100*1728+100*2074+(n-200)*2612
    elif 400<n and n<=700:
        return 100*1728+100*2074+200*2612+(n-400)*3111
    else:
        return 100*1728+100*2074+200*2612+300*3111+(n-700)*3457
n=int(input())
a=giaHienTai(n)
b=giaDuKien(n)
chenhLech=(b-a)*1.1
print(f'{chenhLech:.2f}')
