def bubble_sort(my_list):
  list_length = len(my_list)
  is_sorted = False
  while not is_sorted:
    is_sorted = True
    for i in range(list_length-1):
      if my_list[i] > my_list[i+1]:
        my_list[i] , my_list[i+1] = my_list[i+1] , my_list[i]
        is_sorted = False
    list_length -= 1
  return my_list

print(bubble_sort([5, 7, 9, 1, 4, 2]))