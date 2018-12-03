#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <math.h>
#define MAX_FNAME_LENGTH 100

int main() {
	
	setlocale(LC_ALL, "Russian");
	
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	char inputFileName[MAX_FNAME_LENGTH];
	char *outputFileName = "output.txt";
	
	FILE *inputFile, *outputFile;
	
	puts("Enter input file name:");
	
	fgets(inputFileName, MAX_FNAME_LENGTH, stdin);
	inputFileName[strlen(inputFileName) - 1] = '\0';
	
	printf("Input file name:");
	puts(inputFileName);
	
	if ((inputFile = fopen(inputFileName, "r")) == NULL) {
		
		perror("An error occurred while trying to read the file");
		
		system("pause");
		
		return 1;
		
	}
	
	if ((outputFile = fopen(outputFileName, "w")) == NULL) {
		
		perror("An error occurred while trying to open the output file for writing");
		
		system("pause");
		
		return 2;
		
	}
	
	/* file streams opened */
	
	int matrixElement, count = 0;
	
	while (fscanf(inputFile, "%d", &matrixElement) != EOF) {
		
		printf("Current matrix element: %d\n", matrixElement);
		
		count++;
		
	}
	
	count = sqrt(count);
	
	printf("This is a %dx%d matrix.\n", count, count);
	
	int x, y;
	
	for (y = 0; y < count; y++) {
		
		for (x = 0; x < count; x++) {
			
			if (x == count - 1) {
				
				fprintf(outputFile, "%.2f\n", 1.0);
				
			}
			else {
				
				fprintf(outputFile, "%.2f ", 1.19);
				
			}
			
		}
		
	}
	
	fclose(inputFile);
	fclose(outputFile);
	
	system("pause");
	
	return 0;
	
}
