// Program for Creating an Array, Filling it with elements, Finding an element and Inserting the element Using DMA

#include <stdio.h>
#include <stdlib.h>

// creating an array Using DMA
int main()
{
	int *arr;
	int i, sizeOfarray , search_element;
	printf("Enter the size of array : \n");
	scanf(" %d", &sizeOfarray);
	arr = (int *)malloc(sizeOfarray*sizeof(int));
	for (i = 0; i < sizeOfarray; ++i){
		printf("Enter the array element : arr[%d]\n", i);
		scanf(" %d", (arr+i));
	}
    printf("The given array is :\n");
	for (i = 0; i < sizeOfarray; ++i){
		printf(" arr[%d] = %d\n", i, *(arr+i));
	}
    // Inserting Element in Array
	
    arr = realloc(arr,(sizeOfarray* sizeof(int)+1));
	printf("Enter the new array element at index value : arr[%d]\n", sizeOfarray);
	scanf(" %d", (arr+sizeOfarray));
    printf("The new array formed is :\n");
	for (i = 0; i < sizeOfarray+1; ++i){
		printf(" arr[%d] = %d\n", i, *(arr+i));
	}
    //performing linear search to find the given element  
    printf("Enter element to search: "); 
    scanf("%d",&search_element);
     
    for(i=0;i<sizeOfarray+1;++i)
    if(arr[i]==search_element)
        break;
     
    if(i<sizeOfarray+1)
        printf("Element found at index %d",i); 
        else
        printf("Element not found!"); 
  
    return 0;
}
