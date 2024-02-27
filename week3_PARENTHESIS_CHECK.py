def check_text(s):
    stack=[]
    open = '{[('
    close = ')]}'
    pair = {')':'(',']':'[','}':'{'}
    for char in s:
        if char in open:
            stack.append(char)
        elif char in close:
            if not stack or stack.pop() != pair[char]:
                return 0
    return 1 if not stack else 0
text =input().strip()
result = check_text(text)
print(result)
