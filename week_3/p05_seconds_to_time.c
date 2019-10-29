/*****************************************
 * p05_seconds_to_time.c
 * Input seconds and you get the time
 * Simon Sorensen
 * 15/10/2019
 ****************************************/
 
 #include <stdio.h>
 
void formatFromSeconds(int seconds);
 
 int main(void)
 {
 	int seconds;
 	
 	printf("Please enter seconds: ");
 	scanf("%d", &seconds);
 	
 	formatFromSeconds(seconds);
 	
 	return 0;
 }
 
void formatFromSeconds(int seconds)
{
	int hours, minutes;
	
	minutes = seconds / 60;
	hours = minutes / 60;
	
	minutes -= hours * 60;
	
	printf("\nThe formatted time for %d seconds is: %2d:%2d\n", seconds, hours, minutes); 
}
 
 
