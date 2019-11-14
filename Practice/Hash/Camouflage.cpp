#include "Camouflage.h"

unordered_map<string, unordered_set<string>>::iterator umIt;	// Cloth Type, Cloth Name

int Camouflage::solution(vector<vector<string>> clothes)
{
	int answer = 0;

	unordered_map<string, unordered_set<string>> lClothes;
	
	for(auto const& element : clothes)
	{
		umIt = lClothes.find(element[1]);
		if (umIt != lClothes.end())
		{
			umIt->second.insert(element[0]);
		}
		else
		{
			lClothes.insert(make_pair <string, unordered_set<string>>(element[1].c_str(), { element[0] }));
		}
	}

	int nWearCnt = 1;

	for (auto const& element : lClothes)
	{
		nWearCnt *= (element.second.size() + 1);
	}

	answer = nWearCnt - 1;

	return answer;
}

//best
int Camouflage::solution2(vector<vector<string>> clothes)
{
	int answer = 1;

	unordered_map <string, int> attributes;
	for (int i = 0; i < clothes.size(); i++)
	{
		attributes[clothes[i][1]]++;
	}
		
	for (auto it = attributes.begin(); it != attributes.end(); it++)
	{
		answer *= (it->second + 1);
	}
		
	answer--;

	return answer;
}
