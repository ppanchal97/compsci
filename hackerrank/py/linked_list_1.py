class Node():
    def __init__(self, value):
        self.value = value
        self.next = None


class LinkedList():
    def __init__(self, head):
        self.head = head

    def length(self):
        counter = 0
        current_node = self.head
        while True:
            if current_node.next == None:
                counter += 1
                break
            else:
                counter += 1
                current_node = current_node.next
        return counter


if __name__ == "__main__":
    n1 = Node(2)

    ll1 = LinkedList(n1)

    n2 = Node(4)
    n3 = Node(5)
    n4 = Node(7)
    n5 = Node(8)

    n1.next = n2
    n2.next = n3
    n3.next = n4
    n4.next = n5

    print(ll1.length())
