#include "Sol1.h"

#include <map>
#include <algorithm>
#include <math.h>
/*

단어 s의 가운데 글자를 반환하는 함수, solution을 만들어 보세요. 단어의 길이가 짝수라면 가운데 두글자를 반환하면 됩니다.

재한사항
s는 길이가 1 이상, 100이하인 스트링입니다.
*/
string Sol1::solution(string s)
{
	string answer = "";

	int nCenterChar = s.length() / 2;

	if (s.length() % 2 != 0)	// odd number
	{
		answer = s[nCenterChar];
	}
	else						// even number
	{
		answer.push_back(s[nCenterChar - 1]);
		answer.push_back(s[nCenterChar]);
	}
	return answer;
}

/*
점심시간에 도둑이 들어, 일부 학생이 체육복을 도난당했습니다. 다행히 여벌 체육복이 있는 학생이 이들에게 체육복을 빌려주려 합니다. 학생들의 번호는 체격 순으로 매겨져 있어, 바로 앞번호의 학생이나 바로 뒷번호의 학생에게만 체육복을 빌려줄 수 있습니다. 예를 들어, 4번 학생은 3번 학생이나 5번 학생에게만 체육복을 빌려줄 수 있습니다. 체육복이 없으면 수업을 들을 수 없기 때문에 체육복을 적절히 빌려 최대한 많은 학생이 체육수업을 들어야 합니다.
전체 학생의 수 n, 체육복을 도난당한 학생들의 번호가 담긴 배열 lost, 여벌의 체육복을 가져온 학생들의 번호가 담긴 배열 reserve가 매개변수로 주어질 때, 체육수업을 들을 수 있는 학생의 최댓값을 return 하도록 solution 함수를 작성해주세요.
*/
int Sol1::solution2(int n, vector<int> lost, vector<int> reserve)
{
	for (const auto& element : lost)
	{
		vector<int>::iterator it;
		it = std::find(reserve.begin(), reserve.end(), element);

		reserve.erase(it);
	}

	for (const auto& res : reserve)
	{
		for (const auto& lo : lost)
		{
			if (lo == res || lo == res + 1 || lo == res - 1)
			{
				vector<int>::iterator it;
				it = std::find(reserve.begin(), reserve.end(), res);
				reserve.erase(it);
			}
		}
	}

	return 0;
}

long long Sol1::solution(long long n)
{
	long long answer = 0;
	long long origin = sqrt(n);

	if (pow(origin, 2) == n)
	{
		return pow(origin + 1, 2);
	}

	return -1;
}
