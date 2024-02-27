text = ''
while True:
    try:
        a = input()
    except EOFError:
        break
    text += (a.upper()+"\n")
print(text)
