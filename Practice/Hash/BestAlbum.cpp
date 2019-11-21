#include "BestAlbum.h"

#include <map>
#include <unordered_map>
#include <algorithm>

vector<int> BestAlbum::solution(vector<string> genres, vector<int> plays)
{
	vector<int> answer;

	map<string, int> lGenrePlayCnt;
	
	for (int i = 0; i < genres.size(); ++i)
	{
		map<string, int>::iterator it = lGenrePlayCnt.find(genres[i]);
		if (it != lGenrePlayCnt.end())
		{
			it->second += plays[i];
		}
		else
		{
			lGenrePlayCnt.insert(make_pair(genres[i], plays[i]));
		}
	}

	while (1)
	{
		// Get favorite genre.
		map<string, int>::iterator itfavoritGenre = max_element (
			lGenrePlayCnt.begin(), lGenrePlayCnt.end()
			, [](std::pair <std::string, int> p1, std::pair <std::string, int> p2)
			{
				return p1.second < p2.second;
			}
		);

		map<int, int> lSongs;	// uid, playcnt
		
		for (int i = 0, nChoiceCnt = 0; i < genres.size(); ++i)
		{
			if (itfavoritGenre->first.compare(genres[i]) == 0)
			{
				lSongs.insert(make_pair(i, plays[i]));
			}			
		}

		for (int i = 0; ; ++i)
		{
			if (i >= 2 || lSongs.size() == 0)
			{
				break;
			}
			map<int, int>::iterator itFavoriteSong = max_element(lSongs.begin(), lSongs.end()
				, [](std::pair<int, int> p1, std::pair<int, int> p2)
				{
					return p1.second < p2.second;
				}
			);
			answer.emplace_back(itFavoriteSong->first);
			lSongs.erase(itFavoriteSong);
		}

		lGenrePlayCnt.erase(itfavoritGenre);
		if (lGenrePlayCnt.size() == 0)
		{
			break;
		}
	}
	
	return answer;
}