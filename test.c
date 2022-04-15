#include <stdio.h>
#include <math.h>

void convert_to_D(long long n)
{
	int num, binary_num, decimal_num = 0, base = 1, rem;    
    num = n;
  
    binary_num = num; // assign the binary number to the binary_num variable  
    while ( num > 0)  
    {  
        rem = num % 10; /* divide the binary number by 10 and store the remainder in rem variable. */  
        decimal_num = decimal_num + rem * base;  
        num = num / 10; // divide the number with quotient  
        base = base * 2;  
    }  
    printf ( " The binary number is %d \n", binary_num); 
    printf (" \n The decimal number is %d \n", decimal_num); 
}
/*------------------------------------------------------*/
long long	convert_to_B(int n)
{
	long long bin = 0;
	int rem, i = 1;
	while (n!=0)
	{
		rem = n % 2;
		n /= 2;
		bin += rem * i;
		i *= 10;
	}
	return (bin);
}
/*------------------------------------------------------*/
int main()
{
	long long	bin;
	int	num;

	num = 113;
	bin = convert_to_B(num);
	printf("----------------------------------\n");
	printf("decimal befor shifting is %d\n", num);
	printf("bin befor shifting is %lld\n", bin);
	printf("----------------------------------\n");

	convert_to_D(num);
	printf("----------------------------------\n");
	
	return (0);
}