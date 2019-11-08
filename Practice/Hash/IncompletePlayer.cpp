#include "IncompletePlayer.h"

typedef unordered_multiset<string>::iterator umsIt;
string IncompletePlayer::solution(vector<string> participant, vector<string> completion)
{
	unordered_multiset<string> lParticipant(participant.begin(), participant.end());
		
	for(const auto& element : completion)
	{
		umsIt it = lParticipant.find(element);
		if (it != lParticipant.end())
		{
			lParticipant.erase(it);
		}
	}

	string answer;
	for (const auto& element : lParticipant)
	{
		answer = element;
	}

	return answer;
}