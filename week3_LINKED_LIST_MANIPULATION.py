class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class Linked_List:
    def __init__(self):
        self.head = None

    def insert_last(self, val):
        if self.search(val) is None:
            temp = Node(val)
            if self.head is None:
                self.head = temp
            else:
                temp2 = self.head
                while temp2.next is not None:
                    temp2 = temp2.next
                temp2.next = temp

    def insert_first(self, val):
        if self.search(val) is None:
            temp = Node(val)
            temp.next = self.head
            self.head = temp

    def search(self, val):
        temp = self.head
        while temp is not None:
            if temp.data == val:
                return temp
            temp = temp.next
        return None

    def add_after_u_v(self, u, v):
        if self.search(u) is None and self.search(v) is not None:
            temp = Node(u)
            temp.next = self.search(v).next
            self.search(v).next = temp

    def add_before_u_v(self, u, v):
        if self.search(u) is None and self.search(v) is not None:
            temp = Node(u)
            temp.next = self.search(v)
            temp2 = self.head
            while temp2.next is not self.search(v):
                temp2 = temp2.next
            temp2.next = temp

    def remove(self, val):
        temp = self.head
        if self.search(val) is not None:
            if self.search(val) == self.head:
                self.head = self.head.next
                del temp
            else:
                while temp.next is not self.search(val):
                    temp = temp.next
                temp.next = self.search(val).next
                if self.search(val):
                    self.remove(self.search(val))

    def reverse(self):
        current = self.head
        prev = None
        next = None
        while current is not None:
            next = current.next
            current.next = prev
            prev = current
            current = next
        self.head = prev

    def print_list(self):
        temp = self.head
        while temp is not None:
            print(temp.data, end=" ")
            temp = temp.next
        print()

if __name__ == "__main__":
    n = int(input())
    t = Linked_List()
    vals = input().split()
    for val in vals:
        t.insert_last(int(val))

    while True:
        text = input()
        if "addlast" in text:
            val = int(text.split()[1])
            t.insert_last(val)
        elif "addfirst" in text:
            val = int(text.split()[1])
            t.insert_first(val)
        elif "addafter" in text:
            u, v = map(int, text.split()[1:3])
            t.add_after_u_v(u, v)
        elif "addbefore" in text:
            u, v = map(int, text.split()[1:3])
            t.add_before_u_v(u, v)
        elif "remove" in text:
            val = int(text.split()[1])
            t.remove(val)
        elif "reverse" in text:
            t.reverse()
        elif text == "#":
            t.print_list()
            break
