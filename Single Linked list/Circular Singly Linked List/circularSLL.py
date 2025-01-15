#Cicular Singly Linked List
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

node1 = Node(2)
node2 = Node(45)
node3 = Node(27)
node4 = Node(55)

node1.next = node2
node2.next = node3
node3.next = node4
node4.next = node1 #circular link

head = node1
currentNode = head
if head is not None:
    while True:
        print(currentNode.data, end=" --> ")
        currentNode = currentNode.next
        if currentNode == head:
            break
print("....")    
