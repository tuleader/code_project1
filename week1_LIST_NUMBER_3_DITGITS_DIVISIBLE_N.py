def b2():
    n =int(input())
    arr_b2 = ""
    for i in range(100,1000):
        if i%n==0:
            arr_b2 +=(str(i)+" ")
    print(arr_b2)
b2()
