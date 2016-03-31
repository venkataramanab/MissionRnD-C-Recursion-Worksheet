/*
There is a general and he has N Snipers in his control . He has a battefield of NxN Blocks .
He now has to place all N snipers in the battle field such that he can have control of all Blocks,
ie each block should atleast have One sniper having control on it .

A Sniper has control of all blocks in line in all 4 directions . and also all blocks in all 4 diagonals
from his position .

Example :

. C C C
C C S C
. C C C
C . C .

In the above field if Sniper S is placed at (1,2) He has control of all blocks denoted by C .
But their is a problem for the General. All his snipers dont like each other So if any sees any
other sniper in his field of view (Control Blocks) ,he will instantly kill the other sniper .So
Your task is to help the general to place all his N Snipers on NxN field such that ,No sniper can
kill other sniper,but still have control of all the Blocks .

Input : A NxN board , which is all 0's , and N (number of snipers )
Output : Return 1 if its General can place all N snipers or else return 0 .
		 Also modify the battlefield ,such that Blocks which have sniper placed are denoted by 1
		 and all other blocks as 0.

		 Note : If there are multiple correct arrangements ,Arrange in any 1 of the possible ways.
Example Input :
int battle_field[4][4]={0};
solve_nsnipers(&battle_field[0][0],4);

Example Output :
Returns 1 , and modifies battle_field as follows .
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0


Read :How to access elements in 2D array when its first element address is passed : http://www.geeksforgeeks.org/pass-2d-array-parameter-c/

P.S: The Above Problem is just a modified version of a popular BackTracking problem .
*/

#include "stdafx.h"
bool validPos(int *board, int N, int row, int col);
bool sniperPlace(int *battlefield, int N, int col);
//similar to nQueens algorithm
int solve_nsnipers(int *battlefield, int n){
	if (n < 4)
		return 0;
	else if (sniperPlace(battlefield, n,0))
		return 1;
	return 0;
}
bool validPos(int *battlefield,int N, int row, int left)
{
	for (int i = 0; i < left; i++)
	if (battlefield[row*N+i])
		return false;
	for (int i = row, j = left; i >= 0 && j >= 0; i--, j--)
	if (battlefield[i*N+j])
		return false;
	for (int i = row, j = left; j >= 0 && i<N; i++, j--)
	if (battlefield[i*N+j])
		return false;
	return true;
}
bool sniperPlace(int *battlefield, int N,int col)
	{
		if (col >= N)
			return true;
		for (int i = 0; i < N; i++)
		{
			if (validPos(battlefield,N, i, col))
			{
				battlefield[i*N+col] = 1;
				if (sniperPlace(battlefield,N, col + 1))
					return true;
				battlefield[i*N+col] = 0;
			}
		}
		return false;
}