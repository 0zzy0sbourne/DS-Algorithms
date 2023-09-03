#include <stdio.h>
void merge_sort(int ar[], int , int); 
void merge(int ar[], int , int , int); 
void printArray(int ar[], int ); 
int main(){
    int array[] = {6,5,8,9,3,10,15,12,16}; 
    merge_sort(array,0, 8 );
    printArray(array, 9); 
     
    return 0 ; 
}
void merge(int ar[], int firstindex, int middleindex, int lastindex){
    int sizefirst = middleindex+1 ; 
    int sizesecond = lastindex - middleindex  ; 
    int firstpart[sizefirst] ; 
    int secondpart[sizesecond];
    int counter = 0 ; 
    for(size_t i = firstindex;i<=middleindex+1;i++){
        firstpart[counter] = ar[i];
        counter++; 
    } 
    counter = 0 ; 
    for(size_t i = middleindex+1; i<= lastindex;i++){
        secondpart[counter] = ar[i]; 
        counter++;
    }
    int firstiter = 0 , seconditer = 0 ; 
    for(size_t i = 0;i<=lastindex; i++){
        if(firstpart[firstiter] <= secondpart[seconditer]){
            ar[i] = firstpart[firstiter];
            firstiter++;  
        } else {
            ar[i] = secondpart[seconditer]; 
            seconditer++; 
        }
    }

}
void merge_sort(int ar[], int firstindex, int lastindex){
    if(firstindex<lastindex){
        int middleindex = (firstindex + lastindex) / 2 ; 
        merge_sort(ar, firstindex, middleindex) ;
        merge_sort(ar, middleindex+1, lastindex); 
        merge(ar, firstindex, middleindex, lastindex);
    }
}
void printArray(int ar[], int size){
    for(size_t i = 0;i<size;i++){
        printf("%d ", ar[i]); 
    }
}