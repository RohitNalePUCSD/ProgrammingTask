//Question :- Find all element in array which have
//at least two greater element

#include<stdio.h>
#include<malloc.h>


//marge short

void marge(int arr[], int low, int mid, int heigh)
{
	int i = low;
	int j = mid+1;
	int k = 0;
	int brr[heigh];
	
	while(i <= mid && j <= heigh)
	{
		if(arr[i]<arr[j])
			brr[k++] = arr[i++];
		else
			brr[k++] = arr[j++];		
	}

	while(i <= mid)
	{
		brr[k++] = arr[i++];
	}

	while(j <= heigh)
	{
		brr[k++] = arr[j++];
	}

	for(i = heigh; i >= low; i--)
		arr[i] = brr[--k];
}

// Given array is sorting by using the MargeSort algorithm

void margeSort(int arr[], int low, int heigh)
{
	if(low < heigh)
	{
		int mid = (low+heigh)/2;
		margeSort(arr, low, mid);
		margeSort(arr, mid+1, heigh);
		
		marge(arr, low, mid, heigh);
	}

}

// Display the Array 

void display(int arr[], int n)
{
	for(int i = 0; i < n; i++)
		printf("%d\t",arr[i]);
}


// In given array are only select the 
//at least two greater number

void largest_Element(int arr[], int n)
{
	int t1 = arr[n-2],t2 = arr[n-1];
	int i = n;

	while(i>0)
	{
		if(t1 == t2)
		{
			i--;
			t1 = arr[i];
		}	
		else
			break;
	}	
	n = i;

	if(arr[0] < t1 && arr[0] <t2)
		printf("\n%d\t",arr[0]);

	for( i = 1; i < n; i++)
	{
		if((arr[i] < t1 && arr[i] < t2) && arr[i-1] != arr[i]) 
		{
			printf("%d\t",arr[i]);
		}
	}	
}

// Entry point function of program
 
int main()
{
	int n,*arr;

	printf("Enter the how many number of elements\n");
	scanf("%d",&n);

	//Dynamic memory allocation of array
	arr = (int*)malloc(sizeof(int)*n);
	
	printf("Enter the element \n");

	for(int i = 0;i < n; i++)
	{
		scanf("%d",&arr[i]);
	}

	// call to margeShort function
	margeSort(arr, 0, n-1);

	// Display the given array
	display(arr,n);


	printf("\n\nAt least 2 greater element in array at given number:\n");
	largest_Element(arr, n);
}
