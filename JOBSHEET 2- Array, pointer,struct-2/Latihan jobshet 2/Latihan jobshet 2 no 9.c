/*created-by-Serly-Eka-Putri-23343083 */

#include <stdio.h>
struct person {
	
	int age;
	float weight;
};

int main(){
	
	struct person *personptr, person1;
	personptr = &person1;
	
	printf("Enter age: ");
	scanf("%d", &personptr->age);
	
	printf("Enter weight: ");
	scanf("%f", &personptr->weight);
	
	printf("Displaying:\n");
	printf("Age: %d\n", personptr->age);
	printf("weight: %f\n", personptr->weight);
	
	return 0;
	
}