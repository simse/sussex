/*****************************************
 * p06_display_vat.c
 * Calculate VAT
 * Simon Sorensen
 * 15/10/2019
 ****************************************/
 
 #include <stdio.h>
 
 float calculateVAT(float price);
 
 int main(void)
 {
 	float price;
 	
 	printf("Please enter a price: ");
 	scanf("%f", &price);
 	
 	printf("\nThe VAT of %g is %g\n", price, calculateVAT(price));
 	
 	return 0;
 }
 
 float calculateVAT(float price)
 {
 	return price * 0.2;
 }
