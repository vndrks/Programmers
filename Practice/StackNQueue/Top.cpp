#include "Top.h"

vector<int> Top::solution(vector<int> heights)
{
	vector<int> answer;

	while (1)
	{

	}


	for (int i = heights.size(); i > 0; --i)
	{

		while (1)
		{
			if (heights[i] < heights[i - 1])
			{
				answer.push_back(i - 1);
			}
			else
			{
				answer.push_back(i - 2);
			}
		}
	}

	return answer;
}