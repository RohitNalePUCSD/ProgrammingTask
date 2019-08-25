/*
	Given a string, deduce a mathematical formula to check if the string is palindrom or not. Implement
	the function for the same.

	Dont use reverse function.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int palindrome(char arr[], int n)
{
	int total1 = 0.0 , total2 = 0.0; 
	int cnt = 1, i;
	
	/*
		Ist for loop :

		If the string is  divide into half 0 to ((n/2) - 1.)
		each charater is 0 to (n/2) - 1 which is divided by counter 
		counter is start from 1 and incremented by one at each charater 
		upto (n/2) - 1. 
		the total1 is sum of charater divided by counter.

		2nd for loop:
	
                If the string is remaining sub part of string is  (n/2) + 1 to (n - 1) if string is odd or
		string is even then (n/2) to (n - 1)
                each charater is (n/2) + 1 to n - 1  or (n/2) to (n - 1) which is divided by counter 
                counter is start from counter value() and decrement  by one at each charater 
            	upto n - 1. 
                the total2 is sum of charater divided by counter.
        */ 

	// String is even

	if(n % 2 == 0)
	{
		for(i = 0; i <= ((n/2) - 1); i++)
		{
			total1 += (arr[i])/cnt;
			cnt++;
		}

		for(i = n/2; i < n; i++)
		{
			cnt--;
			total2 += (arr[i])/cnt;
		}
	}
	
	 // String is odd
 
	else
	{
		for(i = 0; i <= ((n/2) - 1); i++)
                {
                        total1 += (arr[i])/cnt;
                        cnt++;
                }
                for(i = ((n/2) + 1); i < n; i++)
                {
			cnt--;
                        total2 += (arr[i])/cnt;
                }
	}
	// Total1 and Total2 is same then string is Palindrome or not

	if(total1 == total2)
             return 1;
	else
             return 0;
}

int main()
{
	char arr[20];
	puts("Enter the string");
	gets(arr);

	if(palindrome(arr, strlen(arr)))
		printf("YES given string is palindrome\n");
	else
		printf("NO given string is not palindrome\n");
}
