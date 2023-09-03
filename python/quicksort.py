def swap( ar, firstindex, secondindex): 
    temp = ar[firstindex]
    ar[firstindex] = ar[secondindex]
    ar[secondindex] = temp
def partition( ar, low, high): 
    pivot = ar[low] 
    i = low 
    j = high 
    while i < j: 
        while ar[j] > pivot :
            j -= 1 
        while ar[i] <= pivot: 
            i+=1
        if(i<j): 
            swap(ar,i,j ) # ?? 
    swap(ar, low, j)
    return j  

def quickSort( ar, low, high): 
    if low < high :
        j = partition(ar, low, high)
        quickSort(ar, low, j)
        quickSort(ar, j+1, high)  




array = [6,5,8,9,3,10,15,12,16]
quickSort(array, 0, 8)
print(array)