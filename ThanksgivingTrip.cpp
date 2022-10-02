/*********************************************************

	Algorithms, Fall, 2022
	Assignment#3 : Thanksgiving trip

	Written by Rina Kim (krn2363@gachon.ac.kr)
	September, 2022

************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char inFileName[5][20] = { "Input_1.txt", "Input_2.txt", "Input_3.txt", "Input_4.txt", "Input_5.txt" };
	char outFileName[5][20] = { "Output_1.txt", "Output_2.txt", "Output_3.txt", "Output_4.txt", "Output_5.txt" };

	for (int i = 0; i < 5; i++){
	
		char* infilename = inFileName[i];
		char* outfilename = outFileName[i];
		
		int num_student;	
		int expense[100];
		int average = 0;
		int exchange[100];

		FILE* inFile;
		FILE* outFile;

		inFile = fopen(infilename, "r");
		if (inFile == NULL)
			printf("\nInput File Could Not Be Opened\n");
		outFile = fopen(outfilename, "w");
		if (outFile == NULL)
			printf("Output File Couldn't Be Opened.");

		fscanf(inFile, "%d", &num_student);	//Receive number of students 

		while (num_student != 0)	//Repeat until num_student is 0
		{
			int total = 0;

			if (num_student == 1)	//If num_student is 1, not necessary to calculate, so prints 0.
			{
				fscanf(inFile, "%d", &expense[0]);
				fprintf(outFile, "%d\n", 0);
			}
			else
			{
				for (int i = 0; i < num_student; i++)
				{
					fscanf(inFile, "%d", &expense[i]);	
					total += expense[i];	//add expenses to get the average amount of money.
				}
				average = total / num_student;	//Get average amount

				int exchange_sum = 0;
				for (int i = 0; i < num_student; i++)
				{
					exchange[i] = average - expense[i]; //Find how far off the average.
					if (exchange[i] >= 0)	//Add everything only if exchange[i]==0.
						exchange_sum += exchange[i];
				}
				fprintf(outFile, "%d\n", exchange_sum);
			}
			fscanf(inFile, "%d", &num_student);
		}
		fclose(inFile);
		fclose(outFile);
	}

	return 0;
}
