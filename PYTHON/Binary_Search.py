#Binary Search in Python
def binary_search(arr, low, high, item):

  # Base case
  if high >= low:

    middle = (high + low) // 2

    #if search item is present in the middle 
    if arr[middle] == item:
      return middle

    #if search item is smaller than the middle element search in the left half
    elif arr[middle] > item:
      return binary_search(arr, low, middle - 1, item)

    # Else the element can only be present in right subarray
    else:
      return binary_search(arr, middle + 1, high, item)

  else:
    # Element is not present in the array
    return -1

# Test array
arr= [15,25,33,45,74,86,]
search_item = 74
l=len(arr)
low=0
high=l-1
# Function call
result = binary_search(arr, low, high, search_item)

if result != -1:
  print("Element is present at index:", result)
else:
  print("Element is not present in array")