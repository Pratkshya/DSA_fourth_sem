class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def appendNode(head,data):
    #newNode with the give data
    newNode = Node(data)

    if head is None:
        return newNode
    
    current = head
    while current.next is not None:
        current = current.next

    current.next = newNode
    return head    

nodeA = Node(1)
nodeB = Node(5)
nodeC = Node(8)

nodeA.next = nodeB
nodeB.next = nodeC

nodeA = appendNode(nodeA, 10)
current = nodeA
while current is not None:
    print(current.data, end=" -> ")
    current = current.next
print("None")