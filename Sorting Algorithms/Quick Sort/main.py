def quick_sort(arr):
    if (len(arr) <= 1):
        return arr
    
    pivot = arr[0]
    
    left = [i for i in arr[1:] if i <= pivot]
    right = [i for i in arr[1:] if i > pivot]
    
    return quick_sort(left) + [pivot] + quick_sort(right)

if __name__ == "__main__":
    arr = [5, 3, 2, 1, 4]
    print(quick_sort(arr))