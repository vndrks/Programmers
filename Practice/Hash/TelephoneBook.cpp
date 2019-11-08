#include "TelephoneBook.h"

using namespace std;

typedef unordered_multimap<int, string>::iterator umsIt;	//	<length, phone_number>

bool TelephoneBook::solution(vector<string> phone_book)
{
	bool answer = true;

	unordered_multimap<int, string> lPhoneBook;
	int minLength = 21;

	for (const string& element : phone_book)
	{
		lPhoneBook.insert(std::make_pair<int, string>(element.length(), element.c_str()));
		if (element.length() < minLength)
		{
			minLength = element.length();
		}
	}

	//std::pair<unordered_multimap<int, string>::iterator, unordered_multimap<int, string>::iterator> iterPair =  lPhoneBook.equal_range(minLength);
	umsIt it;

	//for (const auto& element : lPhoneBook)
	//{
	//	printf("Element : %s / %p \n", element.second.c_str(), &element.second);
	//}

	for (it = lPhoneBook.equal_range(minLength).first; it != lPhoneBook.equal_range(minLength).second; ++it)
	{
		int nDupCnt = 0;
		for (const auto& element : lPhoneBook)
		{
			//const char* pch;
			//pch = strstr(element.second.c_str(), it->second.c_str());	// strstr 을 사용할 경우 문자열의 처음부터 비교하게 동작하는 로직 추가 필요.

			int rc = strncmp(element.second.c_str(), it->second.c_str(), it->second.length());
			if (rc == 0)
			{
				nDupCnt++;
			}
			if (nDupCnt >= 2)
			{
				answer = false;
				return answer;
			}

			/*if (pch != NULL)
			{
				nDupCnt++;
			}

			if (nDupCnt >= 2)
			{
				answer = false;
				return answer;
			}*/
		}
	}
	
	return answer;
}
