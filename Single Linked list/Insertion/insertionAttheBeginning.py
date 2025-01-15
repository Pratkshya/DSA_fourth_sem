#Insertion at the beginning of the linekd list
class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

nodeA = Node(12)
nodeB = Node(3)
nodeC = Node(5)
nodeD = Node(9)

nodeA.next = nodeB
nodeB.next = nodeC
nodeC.next = nodeD

head = nodeA
newNode = Node(55)
newNode.next = head
head = newNode

current = head
while current is not None:
    print(current.data, end=" -->  ")
    current = current.next
print("None")    