def bubble_sort(arr):
    ARR_SIZE = len(arr)

    for i in range(ARR_SIZE - 1):
        SWAPPED = False
        for j in range(ARR_SIZE-1-i):
            if(arr[j] > arr[j+1]):
               arr[j], arr[j+1] = arr[j+1], arr[j]
               SWAPPED = True
        if not SWAPPED:
            break

    return arr 

if __name__ == "__main__":
    arr = [5, 2, 3, 4, 1]
    print(bubble_sort(arr))