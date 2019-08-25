/*

Input
	The first lines of the input is an integer N (1 <= N <= 100). Next follows
	the input consisting of ASCII characters. The input is terminated by EOF.
	You may assume that length of each word is less than 1024 and maximum
	number of words can be never more than 1024.

Output
	The input reversed N times with atleast a space/newline between any two
	words of your output.

Input:
	2
	fox jumps over the lazy dog.
Output:
	.god .god yzal yzal eht eht revo revo spmuj spmuj xof xofInput:

Input:
	1
	It matters not how strait the gate,
	How charged with punishments the scroll.
	I am the master of my fate:
	I am the captain of my soul.

Output:
	.luos ym fo niatpac eht ma I
	:etaf ym fo retsam eht ma I
	.llorcs eht stnemhsinup htiw degrahc woH
	,etag eht tiarts woh ton srettam tI
	.luos ym fo niatpac eht ma I
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void function(FILE *fp, int k)
{
	int i = 0, j = 0, len = 0, cnt = 0;
	char ch, arr[1024];

	while(i < 1024)
		arr[i++] = '\0';

	fseek(fp, 0, SEEK_END);
    	cnt = ftell(fp);

	i = 0;    
 
    	while( i < cnt )
    	{
        	i++;
        	fseek(fp, -i, SEEK_END);
		ch = fgetc(fp);
		if(ch != '\n')
			arr[j++] = ch;
		else
			arr[j++] = ' ';

		if(i == cnt)
			arr[j++] = ' ';
	
		if(ch == ' ' || ch == '\n' || i == cnt)
		{
			for(j = 0; j < k; j++)
       		                printf("%s",arr);
	
	                for(j = 0; j < 1024; j++)
                       		arr[j] = '\0';
			if(ch == '\n')
				printf("\n");
			j = 0;
		}
	}
    	printf("\n");
}


int main()
{
		
	FILE *fp = fopen("data","r");
	int k;	

	if(fp == NULL)
	{
		printf("File does not found\n\n");
		exit(0);
	}
	
	printf("Enter the k number\n");
	scanf("%d",&k);
	
	function(fp, k);
}
