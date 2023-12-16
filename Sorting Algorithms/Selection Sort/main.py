def selection_sort(arr):
    ARR_SIZE = len(arr)

    for i in range(ARR_SIZE - 1):
        SMALLEST = i
        for j in range(i+1, ARR_SIZE):
            if(arr[j] > arr[SMALLEST]):
                SMALLEST = j

            arr[j], arr[SMALLEST] = arr[SMALLEST], arr[j]

    return arr

        
if __name__ == "__main__":
    arr = [5, 2, 3, 4, 1]
    print(selection_sort(arr))