/*

	You have N steps to climb .
	You can either take one step or two steps at a time .
	You need to find the total number of ways you can reach N steps .

	Example : For N=4 , You can either reach 4 steps in following ways
	->1111
	->112
	->211
	->22
	So total number of ways is 4

	Input : A Integer denoting N (number of steps )
	Output : Return an Integer denoting the number of ways to reach N steps

	Example Input : get_steps(5)
	Example Output : Returns 8

	Note : Test Cases would be small <25.

*/
#include "stdafx.h"


int get_steps(int s)
{
	if (s>1){
		return get_steps(s - 1) + get_steps(s - 2);//for nth step it is sum of ways from (n-1)th step and (n-2)th step
	}
	else if (s == 1){
		return 1;								//we know for the first step it can be reached in only one way
	}
	//this automatically returns 0 fails both if
}
