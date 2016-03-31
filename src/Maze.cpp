/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>
#define visited 2
int* dupMaze(int *maze, int rows, int cols);
int pathFinder(int *maze, int rows, int cols, int xPtr, int yPtr, int xDest, int yDest);
bool validPos(int rows, int cols, int x, int y, int *maze);
int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	if (validPos(rows, columns, x1, y1, maze) && validPos(rows, columns, x2, y2, maze)){
		int *newMaze = dupMaze(maze, rows, columns);
		return pathFinder(newMaze, rows, columns, x1, y1, x2, y2);
	}
	return 0;
}
int pathFinder(int *maze, int rows, int cols, int xPtr, int yPtr, int xDest, int yDest){
	*(maze + xPtr*cols + yPtr) = visited;
	if (xPtr == xDest && yPtr == yDest){
		return 1;
	}
	if (*(maze + (xPtr + 1)*cols + yPtr) != visited && validPos(rows, cols, xPtr + 1, yPtr, maze)){
		return pathFinder(maze, rows, cols, xPtr + 1, yPtr, xDest, yDest);
	}
	else if (*(maze + xPtr*cols + yPtr + 1) != visited && validPos(rows, cols, xPtr, yPtr + 1, maze)){
		return pathFinder(maze, rows, cols, xPtr, yPtr + 1, xDest, yDest);
	}
	else if (*(maze + xPtr*cols + yPtr - 1) != visited && validPos(rows, cols, xPtr, yPtr - 1, maze)){
		return pathFinder(maze, rows, cols, xPtr, yPtr - 1, xDest, yDest);
	}
	else if (*(maze + (xPtr - 1)*cols + yPtr) != visited && validPos(rows, cols, xPtr - 1, yPtr, maze)){
		return pathFinder(maze, rows, cols, xPtr - 1, yPtr, xDest, yDest);
	}
}
bool validPos(int rows, int cols, int x, int y, int *maze){
	if (x >= 0 && x < rows && y >= 0 && y < cols && *(maze + x*cols + y)){
		return true;
	}
	return false;
}
int* dupMaze(int *maze, int rows, int cols){
	int *newMaze = NULL;
	for (int i = 0; i < rows; i++){
		for (int j = 0; j < cols; j++){
			newMaze = (int*)realloc(newMaze, sizeof(int)*(cols*i + j + 1));
			newMaze[cols*i + j] = maze[cols*i + j];
		}
	}
	return newMaze;
}