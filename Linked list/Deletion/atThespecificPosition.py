class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

head = Node(12)
nodeB = Node(3)
nodeC = Node(5)
nodeD = Node(9)

head.next = nodeB
nodeB.next = nodeC
nodeC.next = nodeD

current = head
while current.next.data != 5:
    current = current.next
current.next = current.next.next    

current = head
while current is not None:
    print(current.data, end=" --> ")
    current = current.next
print ("None")        
        