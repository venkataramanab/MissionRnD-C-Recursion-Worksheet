/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>
#define min(rows,cols) rows < cols ? rows : cols
int* spiralArr(int **arr, int *res, int rows, int cols, int startPt, int curPos);
int *spiral(int rows, int columns, int **input_array)
{
	if ((rows > 0) && (columns > 0) && input_array){
		int *res = NULL;
		res=spiralArr(input_array, res, rows, columns, 0, 0);
		return res;
	}
	return 0;
}
int* spiralArr(int **arr, int *res, int rows, int cols, int startPt, int curPos){
	if (startPt <= ((min(rows,cols) / 2) + (min(rows,cols) % 2))){
		//right move
		for (int i = startPt; i < cols; i++){
			res = (int *)realloc(res, sizeof(int)*(curPos + 1));
			res[curPos++] = arr[startPt][i];
		}
		//down move
		cols--;
		for (int i = startPt + 1; i < rows; i++){
			res = (int*)realloc(res, sizeof(int)*(curPos + 1));
			res[curPos++] = arr[i][cols];
		}
		//left move
		rows--;
		for (int i = cols - 1; i >= startPt; i--){
			res = (int*)realloc(res, sizeof(int)*(curPos + 1));
			res[curPos++] = arr[rows][i];
		}
		//top move
		for (int i = rows - 1; i>startPt; i--){
			res = (int*)realloc(res, sizeof(int)*(curPos + 1));
			res[curPos++] = arr[i][startPt];
		}
		res=spiralArr(arr, res, rows, cols, startPt + 1, curPos);
	}
	return res;
}
