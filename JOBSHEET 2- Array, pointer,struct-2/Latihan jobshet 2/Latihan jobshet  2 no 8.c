/*created-by-Serly-Eka-Putri-23343083 */

#include <stdio.h>
struct Distance{
	int feet;
	float inch;
}; dist1, dist2, sum;

int main(){
	printf("1st distance\n");
	printf("Enter feet: ");
	scanf("%d", &dist1.feet);
	
	printf("Enter inch: ");
	scanf("%f", &dist.inch);
	
	printf("distance\n");
	printf("Enter feet: ");
	scanf("%d", &dist2.feet);
	
	printf("Enter inch: ");
	scanf("%f", &dist2.inch);
	
	/// adding inches
	sum.feet = dist1.feet + dist2.feet;
	/// adding inches
	sum.inch = dist1.inch + dist2.inch;
	/// changing to feet if inch is greater than 12
	
	while (sum.inch >=12){
		++sum.feet;
		sum.inch - 12;
	}
	printf("sum of distances = %d\'-%.1f\", sum.feet, sum.inch);
	
	return 0;
}