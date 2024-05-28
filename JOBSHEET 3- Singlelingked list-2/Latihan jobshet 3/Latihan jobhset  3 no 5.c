/*created-by-Serly-Eka-Putri-23343083 */

/// Topik : Single Linked List 
/// Topik : Single Linked List 
#include <stdio.h>
#include <stdlib.h>  
   
typedef struct LinkedList {
	int data;  
    struct LinkedList* next;  

};node;

int maint(){
	
	node* head = NULL;
	node* second = NULL;
	node* third = NULL; 
	head = 	(node*)malloc(sizeof(node));
	second  = (node*)malloc(sizeof(node));
	third  = (node*)malloc(sizeof(node));  
	
	head->data = 1;
	head->next = second; 
    second->data = 2;
	second->next = third;  
	third->data = 3;
	third->next = NULL;  
   
    printf("%d", head->data);  
       
	return 0;
	
}

