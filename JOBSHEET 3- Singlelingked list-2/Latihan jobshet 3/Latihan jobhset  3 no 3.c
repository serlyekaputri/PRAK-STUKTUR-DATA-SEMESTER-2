/*created-by-Serly-Eka-Putri-23343083 */

/// 3. Single Link List (Typedef) 
#include <stdio.h>
#include <stdlib.h>  

struct LinkedList {
	int data; 
	struct LinkedList *next; 
};

typedef struct LinkedList node; 
node *head = NULL;  
node *second = NULL;
node *third = NULL;

/// Topik : Single Linked List 
int main()  {
	head  = (node*)malloc(sizeof(node));
	second  = (node*)malloc(sizeof(node));
	third  = (node*)malloc(sizeof(node)); 
	
	head->data = 1;  
	head->next = second; 
    second->data = 2;
	second->next = third; 
    third->data = 3;
	third->next = NULL; 
	 
	return 0;
    
}