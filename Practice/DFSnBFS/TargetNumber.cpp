#include "TargetNumber.h"

#include <queue>
#include <math.h>

//BFS (Breadth First Search) & use queue (tree)
int TargetNumber::solution(vector<int> numbers, int target)
{
	int answer = 0;
	
	queue<int> lQueue;
	int nHeight = 1;		// root node
	int nCurNodeNum = 0;	// root node's number - 1

	lQueue.push(0);			// Set value of root node 

	while(!lQueue.empty())
	{
		++nCurNodeNum;
		int nCurVal = lQueue.front();
		lQueue.pop();

		if (nCurVal == target && nHeight == numbers.size())		// Check last level of tree
		{
			++answer;
		}

		if(nCurNodeNum <= pow(2, numbers.size() + 1) - 1)
		{
			// Expand Child
			lQueue.push(nCurVal + numbers[nHeight - 1]);
			lQueue.push(nCurVal - numbers[nHeight - 1]);
		}

		if ((nCurNodeNum == pow(2, nHeight) - 1) && nHeight < numbers.size())
		{
			++nHeight;
		}
	}

	return answer;
}
