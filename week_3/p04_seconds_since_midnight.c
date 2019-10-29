/*****************************************
 * p04_seconds_since_midnight.c
 * Input HH:MM and get seconds since midnight
 * Simon Sorensen
 * 15/10/2019
 ****************************************/
 
 #include <stdio.h>
 
 int inputToSeconds(void);
 
 int main(void)
 {
 	printf("\nSeconds since midnight: %d\n", inputToSeconds());
 	
 	return 0;
 }
 
 int inputToSeconds(void)
 {
 	int hours, minutes;
 	
 	printf("Please enter a time in the following format (HH:MM): ");
 	scanf("%d:%d", &hours, &minutes);
 	
 	return (hours * 60 + minutes) * 60;
 }
