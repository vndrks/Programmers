#include <stdio.h>

#include "Hash/IncompletePlayer.h"
#include "Hash/TelephoneBook.h"
#include "Hash/Camouflage.h"
#include "Hash/BestAlbum.h"

#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	vector<string> participant;
	vector<string> completion;

	participant.push_back("leo");
	participant.push_back("kiki");
	participant.push_back("eden");
	participant.push_back("leo");

	completion.push_back("leo");
	completion.push_back("kiki");
	completion.push_back("eden");
		
	/*
	IncompletePlayer icp;
	std::string strIncomplete = icp.solution(participant, completion);
	*/

	vector<string> lPhoneBook;
	lPhoneBook.push_back("1");
	lPhoneBook.push_back("512");
	lPhoneBook.push_back("4512");
	lPhoneBook.push_back("6512");

	/*
	TelephoneBook tb;
	bool isDup = tb.solution(lPhoneBook);

	isDup ? printf("TRUE\n") : printf("FALSE\n");
	*/
	
	vector<vector<string>> clothes;
	vector<string> cloth1;
	vector<string> cloth2;
	vector<string> cloth3;

	cloth1.push_back("yellow_hat");
	cloth1.push_back("headgear");

	clothes.push_back(cloth1);

	cloth2.push_back("blue_sunglasses");
	cloth2.push_back("eyewear");

	clothes.push_back(cloth2);

	cloth3.push_back("green_turban");
	cloth3.push_back("headgear");

	clothes.push_back(cloth3);

	//Camouflage camouflage;
	//camouflage.solution2(clothes);

	vector<string> genres{ "classic", "pop", "classic", "classic", "pop" };
	vector<int> plays{ 500, 600, 150, 800, 2500 };

	BestAlbum bestAlbum;
	bestAlbum.solution(genres, plays);

	return 0;
}