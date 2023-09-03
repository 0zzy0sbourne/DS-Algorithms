#include <stdio.h>  
void swap(int ar[], int, int);
int partition(int ar[], int, int); 
void quickSort(int ar[], int , int ); 
void printArray(int ar[], int );
int main(){

    int array[9] = {6,5,8,9,3,10,15,12,16}; 
    quickSort(array, 0, 8);
    printArray(array, 9);  
    return 0 ; 
}
void printArray(int ar[], int size){
    for(size_t i = 0;i<size;i++){
        printf("%d ", ar[i]); 
    }
}

void  quickSort(int ar[], int low, int high){
    if(low <  high){
        int j = partition(ar, low, high); 
        quickSort(ar, low, j); 
        quickSort(ar, j+1, high); 
    }
    

}
int partition(int ar[] , int low , int high){
    int pivot = ar[low]; 
    int i = low ;  
    int j = high ; 
    while(i < j){
        while(ar[i] <= pivot){
            i++ ; 
        } 
        while(ar[j] > pivot ){
            j--; 
        }
        if(i < j){
            swap(ar, i, j); // pass indexes  
        }
    }
    swap(ar, low, j); // indexes  
    return j ; 
}
void swap(int ar[], int firstindex, int secondindex){
    int temp = ar[firstindex]; 
    ar[firstindex] = ar[secondindex]; 
    ar[secondindex] = temp ; 
}