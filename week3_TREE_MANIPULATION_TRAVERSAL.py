class Node:
    root = None
    leaves = []
    def __init__(self, id):
        self.id = id
        self.children = []

    def __str__(self):
        return str(self.id)

def makeRoot(u):
    root = Node(u)
    Node.leaves.append(root)
    Node.root = root

def insert(u, v):
    node = Node(u)
    if node not in Node.leaves:
        for i in Node.leaves:
            if i.id == v:
                i.children.append(node)
                Node.leaves.append(node)
                return
        return

def preOrder(node):
    if node:
        print(node.id, end=" ")
        for child in node.children:
            preOrder(child)

def inOrder(node):
    if node:
        if len(node.children) > 0:
            inOrder(node.children[0])
        print(node.id, end=" ")
        for child in node.children[1:]:
            inOrder(child)

def postOrder(node):
    if node:
        if len(node.children) > 0:
            for child in node.children:
                postOrder(child)
        print(node.id, end=" ")



while True:
    text = input()
    if text == "*":
        break
    elif "PreOrder" in text:
        preOrder(Node.root)
        print()
    elif "InOrder" in text:
        inOrder(Node.root)
        print()
    elif "PostOrder" in text:
        postOrder(Node.root)
        print()
    elif "MakeRoot" in text:
        makeRoot(text.split()[1])
    elif "Insert" in text:
        insert(text.split()[1], text.split()[2])
