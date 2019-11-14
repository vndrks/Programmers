#include "BestAlbum.h"

#include <algorithm>
#include <unordered_map>

vector<int> BestAlbum::solution(vector<string> genres, vector<int> plays)
{
	vector<int> answer;

	unordered_map<int, int> lSong;
	lSong.insert(make_pair<int, int>(3, 5));

	int nMaxPlayIdx = std::distance(plays.begin(), max_element(plays.begin(), plays.end()));

	string strGenre = genres[nMaxPlayIdx];
	
	
	

	unordered_map<string, unordered_map<int, int>> lGenres;
	return answer;
}
