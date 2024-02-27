queue=[]
while True:
    try:
        text = input()
        if text.startswith("PUSH"):
            value=text.split()
            queue.append(int(value[1]))
        elif text == 'POP':
            if queue:
                pop_value=queue.pop(0)
                print(pop_value)
            else:
                print("NULL")
        elif text == "#":
            break
    except EOFError:
        break
