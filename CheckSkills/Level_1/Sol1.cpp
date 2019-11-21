#include "Sol1.h"

#include <map>
#include <algorithm>
#include <math.h>
/*

�ܾ� s�� ��� ���ڸ� ��ȯ�ϴ� �Լ�, solution�� ����� ������. �ܾ��� ���̰� ¦����� ��� �α��ڸ� ��ȯ�ϸ� �˴ϴ�.

���ѻ���
s�� ���̰� 1 �̻�, 100������ ��Ʈ���Դϴ�.
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
���ɽð��� ������ ���, �Ϻ� �л��� ü������ �������߽��ϴ�. ������ ���� ü������ �ִ� �л��� �̵鿡�� ü������ �����ַ� �մϴ�. �л����� ��ȣ�� ü�� ������ �Ű��� �־�, �ٷ� �չ�ȣ�� �л��̳� �ٷ� �޹�ȣ�� �л����Ը� ü������ ������ �� �ֽ��ϴ�. ���� ���, 4�� �л��� 3�� �л��̳� 5�� �л����Ը� ü������ ������ �� �ֽ��ϴ�. ü������ ������ ������ ���� �� ���� ������ ü������ ������ ���� �ִ��� ���� �л��� ü�������� ���� �մϴ�.
��ü �л��� �� n, ü������ �������� �л����� ��ȣ�� ��� �迭 lost, ������ ü������ ������ �л����� ��ȣ�� ��� �迭 reserve�� �Ű������� �־��� ��, ü�������� ���� �� �ִ� �л��� �ִ��� return �ϵ��� solution �Լ��� �ۼ����ּ���.
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
