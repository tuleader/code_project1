class Tree:
    def __init__(self, arr):
        self.arr = arr
        self.tree = [0] * (4 * len(arr))
        self.build(0, 0, len(arr) - 1)

    def build(self, node, start, end):
        if start == end:
            self.tree[node] = self.arr[start]
        else:
            mid = (start + end) // 2
            left_child = 2 * node + 1
            right_child = 2 * node + 2
            self.build(left_child, start, mid)
            self.build(right_child, mid + 1, end)
            self.tree[node] = max(self.tree[left_child], self.tree[right_child])

    def query(self, node, start, end, left, right):
        if start > right or end < left:
            return float('-inf')
        elif left <= start and end <= right:
            return self.tree[node]
        else:
            mid = (start + end) // 2
            left_child = 2 * node + 1
            right_child = 2 * node + 2
            left_max = self.query(left_child, start, mid, left, right)
            right_max = self.query(right_child, mid + 1, end, left, right)
            return max(left_max, right_max)

    def find_max_segment(self, start, end):
        return self.query(0, 0, len(self.arr) - 1, start - 1, end - 1)


def b1_medium():
    n = int(input())
    arr = [int(i) for i in input().split()]
    tree = Tree(arr)

    while True:
        try:
            query = input()
            process(query, arr, tree)
        except EOFError:
            break


def process(query, arr, tree):
    if query == "find-max":
        print(max(arr))
    elif query == "find-min":
        print(min(arr))
    elif query == "sum":
        print(sum(arr))
    elif "find-max-segment" in query:
        params = query.split()
        start, end = int(params[1]), int(params[2])
        print(tree.find_max_segment(start, end))
b1_medium()
