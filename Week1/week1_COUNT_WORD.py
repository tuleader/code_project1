count = 0
def count_text(list):
    words = list.split()
    return len(words)
while True:
    try:
        list = input()
        count += count_text(list)
    except EOFError:
        break
print(count)
