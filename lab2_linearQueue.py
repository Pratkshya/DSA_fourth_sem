import time
queue = []
maxSize = 5
def enqueue(queue, element, maxSize):
  if len(queue) >= maxSize:
    print("\nQueue is full. Cannot enqueue")
  else:
    queue.append(element)
    print(f"{element} is added to the queue")  

def dequeue(queue):
  if len(queue) == 0:
    print("\nQueue is empty. Cannot dequeue")
    return None
  else:
      element = queue.pop(0)
      print(f"\n{element} is removed from the list")
      return element
  
def display(queue):
  if len(queue) == 0:
    print("Queue is empty. Add some items to view the list!")
  else:
    print("Queue: ", queue)  

while True:
  print("\nLinear Queue\n")
  print("Choose an operation:")  
  menu = int(input("1. ENQUEUE\n2. DEQUEUE\n3. VIEW\n4. EXIT\n> "))
  
  if menu == 1:
    element = int(input("\nElement to enqueue: "))
    enqueue(queue, element, maxSize)
  elif menu == 2:
    dequeue(queue)  
  elif menu == 3:
      display(queue)
  elif menu == 4:
    print("\nExiting program...\n")   
    time.sleep(1) 
    break
  else:
    time.sleep(1)
    print("\nInvalid choice. Choose either 1,2,3 or 4 from the option!")
    
