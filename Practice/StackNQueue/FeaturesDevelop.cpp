#include "FeaturesDevelop.h"

#include <string>
#include <deque>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

#define JD_COMPLETE_FLAG -1

vector<int> FeaturesDevelop::solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;

	map<int, int> lProgresses;			// <uid, percent> : progresses Structure
	deque<int> lWaiting;				// Waiting Task uid
	queue<pair<int, int>> lComplete;	// Complete Task <uid (index), Days (N th)>

	for (int i = 0; i < progresses.size(); ++i)
	{
		lProgresses.insert(make_pair(i, progresses[i]));
	}

	int nWhatDay = 0;					// From now N days.

	while (lProgresses.size() != (lComplete.size() + lWaiting.size()))
	{
		++nWhatDay;
		
		map<int, int>::iterator itProgress;

		/* Insert the completion and waiting task into the Queue. */
		for(itProgress = lProgresses.begin(); itProgress != lProgresses.end(); ++itProgress)
		{
			if (itProgress->second != -1)
			{
				itProgress->second += speeds[itProgress->first];
			}
			
			if (itProgress->second >= 100)
			{
				if (itProgress->first == 0)
				{
					lComplete.push(make_pair(itProgress->first, nWhatDay));	// If Process is 0 then push to Complete Queue.
				}
				else
				{
					lWaiting.push_back(itProgress->first);	// Move to Waiting Queue. (uid)
				}
				
				itProgress->second = -1;		// Change Complete task to -1.
			}
		}

		sort(lWaiting.begin(), lWaiting.end());

		/* Check the Waiting Queue for complete task.*/
		while (lWaiting.front() && lComplete.size() >= 1)
		{
			if (lWaiting.front() - 1 == lComplete.back().first)
			{
				lComplete.push(make_pair(lWaiting.front(), nWhatDay));
				lWaiting.pop_front();
			}
			else
			{
				break;
			}
		}
	}
	
	/* Insert to answer array. */
	int nDays = 0;

	while (lComplete.size())
	{
		pair<int, int> completeTask = lComplete.front();
		if (nDays != completeTask.second)
		{
			nDays = completeTask.second;
			answer.push_back(1);
		}
		else
		{
			answer.back() += 1;
		}
		lComplete.pop();
	}

	return answer;
}
