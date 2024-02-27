class Node:
    root = None
    values = []

    def __init__(self, value = None) -> None:
        self.value = value
        self.left = None
        self.right = None

def solve():
    while True:
        cmd = input()
        if "#" in cmd:
            pre_Order(Node.root)
            exit()
        else:
            value = int(cmd.split()[1])
            if value not in Node.values:
                node = Node(value)
                Node.values.append(value)
                Node.root = insert(Node.root,node)

def insert(root, node):
    if root == None:
        return node
    else:
        if root.value > node.value:
            root.left = insert(root.left, node)
        else:
            root.right = insert(root.right, node)
        return root

def pre_Order(root):
    if root:
        print(root.value, end=" ")
        pre_Order(root.left)
        pre_Order(root.right)

solve()
