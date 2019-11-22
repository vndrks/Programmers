#include "Top.h"

#include <stack>

vector<int> Top::solution(vector<int> heights)
{
	vector<int> answer;
	stack<int> lRecvNum;
	
	for (int i = heights.size() - 1; i >= 0; --i)
	{
		for (int j = i - 1; j >= 0; )	// Check recv signal top id
		{
			if (heights[j] > heights[i])
			{
				lRecvNum.push(j + 1);
				break;
			}
			else
			{
				--j;
			}

			if (j < 0)
			{
				lRecvNum.push(0);
				break;
			}
		}
	}

	lRecvNum.push(0);	// first Top. Cannot send.

	for (int i = 0; i < heights.size(); ++i)
	{
		answer.push_back(lRecvNum.top());
		lRecvNum.pop();
	}
	
	return answer;
}