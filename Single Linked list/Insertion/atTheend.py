class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

nodeA = Node(12)
nodeB = Node(3)
nodeC = Node(5)
nodeD = Node(9)

nodeA.next = nodeB
nodeB.next = nodeC
nodeC.next = nodeD

newNode = Node(77)
head = nodeA
current = head
while current.next is not None: 
    current = current.next
current.next = newNode

current = head
while current is not None:
    print(current.data, end=" -->  ")
    current = current.next
print("None")      
        