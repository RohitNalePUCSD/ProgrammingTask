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
