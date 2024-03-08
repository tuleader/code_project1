family_tree = {}
while True:
    line = input().strip()
    if line == '***':
        break
    child, parent = line.split()
    family_tree[child] = parent
def haudue(person):
    count_hd = 0
    for child, parent in family_tree.items():
        if parent == person:
            count_hd += 1
            count_hd += haudue(child)
    return count_hd
def count_thehe(person):
    count_th = 0
    for child, parent in family_tree.items():
        if parent == person:
            count_th = max(count_th, 1 + count_thehe(child))
    return count_th

while True:
    line = input().strip()
    if line == '***':
        break
    hd, th = line.split()
    if hd == 'descendants':
        print(haudue(th))
    elif hd == 'generation':
        print(count_thehe(th))
