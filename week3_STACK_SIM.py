stack = []
while True:
    try:
        text = input()
        if text.startswith("PUSH"):
            _,value=text.split()
            stack.append(int(value))
        elif text == "POP":
            if stack:
                pop_value=stack.pop()
                print(pop_value)
            else:
                print("NULL")
        elif text == "#":
            break
    except EOFError:
        break
