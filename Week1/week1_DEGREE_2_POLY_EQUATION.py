import math
def denta(a,b,c):
    if a==0 and b==0 and c==0:
        print('NO SOLUTION')
    elif a==0 and b!=0:
        x=-c/b
        print(f'{x:.2f}')
    elif a==b and b==0 and c!=0:
        print('NO SOLUTION')
    else:
        delta = b*b-4*a*c
        if delta>0:
            x1=(-b - math.sqrt(delta))/(2*a)
            x2=(-b + math.sqrt(delta))/(2*a)
            print(f'{x1:.2f} {x2:.2f}')
        elif delta==0:
            x=-b/(2*a)
            print(f'{x:.2f}')
        else:
            print('NO SOLUTION')
input_str = input()
input_list = input_str.split()

if len(input_list) != 3:
    print("Error")
else:
    a = float(input_list[0])
    b = float(input_list[1])
    c = float(input_list[2])
    denta(a, b, c)
