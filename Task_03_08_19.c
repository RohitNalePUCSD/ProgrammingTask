/* Question : Given an array of interger , 
	print all alternate prime number from that list

*/

#include<stdio.h>
#include<malloc.h>

/* Select one element of an given  array and first check it is a prime 
	or not, if it is a prime then check the alternatives of
	that sequenece of PRIME number 
*/

void primeNumber(int arr[], int n)
{
	// set the flag which deside alternate of given prime number
	int c = 0;

	//Select one element of given array
	for(int i = 0; i < n; i++)
	{
		// set the flag to check prime or not
		int f = 1;

		// find out the given number is prime or not
		for(int j = 2; j <= (arr[i]/2); j++)
		{
			if(arr[i] % j == 0)
			{
				f = 0;
				break;
			}
			
		}

		// check the given number is prime or not
		if(f == 1)
		{
			// alternatives of prime number to dispaly element
			if(c == 0)
			{
				printf("%d\t",arr[i]);
				c = 1;
			}
			else
			{
				c--;
			}
		}
	}		
}


// display function
void display(int arr[], int n)
{
      for(int i = 0; i < n; i++)
            printf("%d\t",arr[i]);
}


// Entry point function
int main()
{
	int *arr,n;

	printf("Enter the how many number\n");
	scanf("%d",&n);

	arr = (int*)malloc(sizeof(int)*n);
	
	printf("Enter the number \n");

	for(int i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}

	printf("\n\n");
	display(arr,n);

	printf("\n\nGiven alternet prime number from that list : \n");

	primeNumber(arr,n);
	
	printf("\n\n");
}
