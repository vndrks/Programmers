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

	int nWearCnt = 0;

	// 1개
	for (auto const& element : lClothes)
	{
		nWearCnt += element.second.size();
	}

	// Type > 1
	int nCnt = 1;

	if (lClothes.size > 1)
	{	
		for (auto const& element : lClothes)
		{
			nCnt *= element.second.size();
		}
	}

	// 모두 입었을떄
	int nAllWear = 1;
	for (auto const& element : lClothes)
	{
		nAllWear *= element.second.size();
	}

	return answer;
}

void Camouflage::DFS(int v, int gole)
{
	int arrVisit[v]
}
