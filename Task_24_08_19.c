/*
	Given two strings, check if they’re anagrams or not. Two strings are
	anagrams if they are written using the same exact letters, ignoring
	space, punctuation and capitalization. Each letter should have the same
	count in both strings.

	For example, ‘Eleven plus two’ and ‘Twelve plus one’ are meaningful
	anagrams of each other.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int anagrams(char string1[], char string2[])
{
	int i,pt;
	int arr[26], brr[26];

	for(i = 0; i < 26; i++)
	{
		arr[i] = 0;
		brr[i] = 0;
	}

	// if string lenght is not same then exit
	if(strlen(string1) != strlen(string2))
	{
		printf("Given string is not anagrams\n");
		exit(0);
	}

	// only check the chrater of string1 and store the in array of index  
	for(i = 0; string1[i] != '\0'; i++)
	{
		if(string1[i] <= 65 && string1[i] >= 91)
		{
			pt = string1[i] - 65;
			arr[pt] = arr[pt] + 1;
		}

		if(string1[i] <= 97 && string1[i] >= 123)
                {
                        pt = string1[i] - 97;
                        arr[pt] = arr[pt] + 1;
                }
	}

	// only check the chrater of string2 and store the in array of index
	for(i = 0; string2[i] != '\0'; i++)
        {
                if(string2[i] <= 65 && string2[i] >= 91)
                {
                        pt = string2[i] - 65;
                        brr[pt] = brr[pt] + 1;
                }

                if(string2[i] <= 97 && string2[i] >= 123)
                {
                        pt = string2[i] - 97;
                        brr[pt] = brr[pt] + 1;
                }
        }
	
	for(i = 0; i < 26; i++)
	{
		if(arr[i] != brr[i])
			return 0;
	}

	return 1;
}




int main()
{
	char string1[100], string2[100];
	printf("Enter the First string\n");
	gets(string1);
	printf("Enter the Second String\n");
	gets(string2);

	if(anagrams(string1, string2))
		printf("Given string is anagrams\n");
	else
		printf("Given string is not anagrams\n");
}
