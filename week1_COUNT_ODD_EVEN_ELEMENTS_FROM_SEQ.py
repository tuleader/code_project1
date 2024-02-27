n = int(input())
chuoi=input()
day=chuoi.split()
odd=even=0
for i in day:
    if int(i)%2==1:
        odd+=1
    else:
        even+=1
print(f'{odd} {even}')
