def insertion_sort(arr):
    ARR_SIZE = len(arr)
    
    for i in range(1, ARR_SIZE):
        CURRENT_VALUE = arr[i]
        j = i - 1
        
        while(j >= 0 and CURRENT_VALUE < arr[j]):
            arr[j + 1] = arr[j]
            j -= 1
            arr[j + 1] = CURRENT_VALUE
            
    return arr

if __name__ == "__main__":
    arr = [5, 3, 2, 1, 4]
    print(insertion_sort(arr))