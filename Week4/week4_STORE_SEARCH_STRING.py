def xuly():
    set_val = set()
    while True:
        key = input()
        if key == '*':
            while True:
                text = input().split()
                if text[0] == 'insert':
                    if text[1] in set_val:
                        print(0)
                    else:
                        set_val.add(text[1])
                        print(1)
                elif text[0] == 'find':
                    if text[1] in set_val:
                        print(1)
                    else:
                        print(0)
                else:
                    return
        elif key == '***':
            break
        else:
            if key not in set_val:
                set_val.add(key)
xuly()
