#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Recursive Function finds how many groups in our matrix  
int check(int arr[][5], int i, int j, int mark) 
{
	if (i<0 || j<0 || i > 4 || j > 4)
		return mark;
	if (arr[i][j]==1)
	{
		arr[i][j] = mark;
		for (int k=-1;k<2;k++)
		{
			for (int l=-1;l<2;l++)
			{
				check (arr, i+k, j+l, mark);
			}
		}
		return mark - 1;
	}
	return mark;
}

int main (void)
{
	int arr[5][5];
	srand(time(NULL));
	int mark = -1;
	
	// to assign random numbers
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			arr[i][j]=rand()%2;
		}
	}
	
	// display array
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%2d ", arr[i][j]);
		}
		printf("\n");
		
	}
	
	//call function for each number
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			 mark = check(arr, i, j, mark);
		}
	}
	
	if (mark==-2)
	{
		printf ("\n\n%d Block is found in the matrix", -(mark+1));
	}
	
	else
		printf ("\n\n%d Blocks are found in the matrix", -(mark+1));
		
	getchar();
	
	
	return 0;
}

