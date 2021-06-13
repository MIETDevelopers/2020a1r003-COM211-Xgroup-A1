#include<stdio.h>
#include<stdlib.h>
int size=0;
int printArray(int *array, int size){
    	int count, newSizeOfList;
    	for(count=0;count<size;++count){
        	printf("\nlistA[%d] = %d", count, *(array+count));
    	}
    return 1;
}
int insertElementInListAt(int*list, int size, int location, int item){
	int newSizeOfList,count;
	list=realloc(list,((size+1)*sizeof(int)));        // Dynamically re-allocating memory using realloc()
	/* here we are using for loop to shift the elements to the right,
	to make space for the new element to be inserted,then we are
	starting the loop from the last and shifting elements until we reach the required index  */
	for(count=size;count>=location;count--){
		list[count] = list[count - 1];
	}
	list[location] = item;                            // element is inserted  at its required index
	newSizeOfList = ++size;                        // size of array increased after insertion of new element
	return newSizeOfList;
}
int deletion(int*list, int size, int index){
	int newSizeOfList,count;
	/* here we are using for loop to shift the elements to the left,
	after the deletion of the element from the list to fill up the empty index */
	if (index == size-1){
		return --size;
	}
	for(count=index+1 ;count < size; count++)
		list[count-1] = list[count];                            // every element is shifted to its left to fill the empty index
		newSizeOfList = --size;                         // size of array reduced after deletion of an element
		return newSizeOfList;
}
int linearSearch(int*list, int size, int element){
	int count;
	/* here for loop is used to search the element traversely,
	until the desired element is found */
	for(count=0 ;count < size; count++)
		if(list[count]==element)
			break;
		if(count < size)
			printf("\n%d is present at location %d.\n", element, count);
		else
			printf("\nElement is not available\n");
	return -1;
}
int main(){
    int *listA;
	int count, newSizeOfList, element, index, location, item, operation;
	/* for convenience we use item  in insertion and element  in linearSearch but both have same meaning,
	similarly location is used in insertion and index is used in deletion but both have same meaning */
	printf("How many numbers?\n");
	scanf(" %d", &size);
	listA = (int*)malloc(size*sizeof(int));                             //Dynamically allocating memory using malloc()
	for (count = 0; count < size; ++count){
		printf("\nEnter listA[%d]\n", count);
		scanf(" %d", (listA+count));
	}
	for (count = 0; count < size; ++count){
		printf("\nlistA[%d] = %d\n", count, *(listA+count));
	}
	do{
    	printf("\nChoose any option\n");
    	printf("1. Insertion \n");
    	printf("2. Deletion \n");
    	printf("3. Linear Search \n");
        printf("4. Display \n");
    	printf("5. Exit \n\n");
    	scanf("%d", &operation);
    	switch (operation){
    		case 1:
    	    	printf("\nEnter the location where you want to insert the element :\n");
				scanf("%d",&location);
        		printf("\nEnter the element to be inserted :\n");
				scanf("%d",&item);
        		size = insertElementInListAt(listA, size, location, item);
        		printArray(listA, size);
        		printf("\n\nElement inserted successfully\n");
        		break;
    		case 2:
        		printf("\nEnter the index of the element to be deleted :\n");
        		scanf("%d",&index);
				if(index >= size){
					printf("wrong index!!!!\n");
					break;
				}
				else{
        			size = deletion(listA, size, index);
       				printArray(listA, size);
        			printf("\n\nElement deleted successfully\n\n");
        			break;
			}
    		case 3:
        		printf("\nEnter the element to be searched :\n");
				scanf("%d",&element);
        		int searchElement = linearSearch(listA, size, element);
        		break;
        	case 4:
				printArray(listA, size);
				break;    
        	case 5:
        		exit(0);
        		break;
    		default:
            	printf("Error!");

    	}
	printf("\nPress enter to continue");
	}
	while (1);
	free(listA);
	return 0;
}
