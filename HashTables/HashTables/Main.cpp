#include <iostream>

 #include "HashTable.h"

void PopulateTable(HashTable<long long> &theTable);

int main()
{
	HashTable<long long> theTable(10);
	PopulateTable(theTable);

	bool runProgram = true;

	while (runProgram)
	{
		std::cout <<
			"***********************************************************************************************************************\n"
			"*************************                  NHL Ticket  Information Directory                  *************************\n"
			"***********************************************************************************************************************\n"
			"  Pacific Division:            Central Division:            Metropolitan Division:            Atlantic Division:     \n"
			"\n"
			"  01. Anaheim Ducks            11. Chicago Blackhawks       21. Carolina Hurricanes           31. Boston Bruins      \n"
			"  02. Arizona Coyotes          12. Colorado Avalanche       22. Columbus Blue Jackets         32. Buffalo Sabres     \n"
			"  03. Calgary Flames           13. Dallas Stars             23. New Jersey Devils             33. Detroit Red Wings  \n"
			"  04. Edmonton Oilers          14. Minnesota Wild           24. New York Islanders            34. Florida Panthers   \n"
			"  05. Los Angeles Kings        15. Nashville Predators      25. New York Rangers              35. Montréal Canadiens \n"
			"  06. San Jose Sharks          16. St. Louis Blues          26. Philadelphia Flyers           36. Ottawa Senators    \n"
			"  07. Vancouver Canucks        17. Winnipeg Jets            27. Pittsburgh Penguins           37. Tampa Bay Lightning\n"
			"  08. Vegas Golden Knights                                  28. Washington Capitals           38. Toronto Maple Leafs\n"
			"\n"
			"***********************************************************************************************************************\n"
			"***** Please enter a team number for information, or enter 98 to quit.                                            *****\n"
			"***********************************************************************************************************************\n"
			"\n";


		system("pause");
		return 0;
	}
}

void PopulateTable(HashTable<long long> &theTable)
{
	theTable.Insert("Carolina Hurricanes", 8666452263);
	theTable.Insert("Columbus Blue Jackets", 6142463350);
	theTable.Insert("New Jersey Devils", 9737576200);
	theTable.Insert("New York Islanders", 8443347537);
	theTable.Insert("New York Rangers", 2124656073);
	theTable.Insert("Philadelphia Flyers", 2152187825);
	theTable.Insert("Pittsburgh Penguins", 8006427367);
	theTable.Insert("Washington Capitals", 2022662277);

	theTable.Insert("Boston Bruins", 6176242327);
	theTable.Insert("Buffalo Sabres", 8882236000);
	theTable.Insert("Detroit Red Wings", 3134717575);
	theTable.Insert("Florida Panthers", 9548357825);
	theTable.Insert("Montréal Canadiens", 8774632674);
	theTable.Insert("Ottawa Senators", 6135990200);
	theTable.Insert("Tampa Bay Lightning", 8133016600);
	theTable.Insert("Toronto Maple Leafs", 4167035323);

	theTable.Insert("Chicago Blackhawks", 3124557090);
	theTable.Insert("Colorado Avalanche", 3034287645);
	theTable.Insert("Dallas Stars", 2144678277);
	theTable.Insert("Minnesota Wild", 6512229453);
	theTable.Insert("Nashville Predators", 6157707800);
	theTable.Insert("St. Louis Blues", 3146222583);
	theTable.Insert("Winnipeg Jets", 8559855000);

	theTable.Insert("Anaheim Ducks", 8779453946);
	theTable.Insert("Arizona Coyotes", 4805637825);
	theTable.Insert("Calgary Flames", 4037774646);
	theTable.Insert("Edmonton Oilers", 8664144625);
	theTable.Insert("Los Angeles Kings", 8885464752);
	theTable.Insert("San Jose Sharks", 4089995757);
	theTable.Insert("Vancouver Canucks", 6048994625);
	theTable.Insert("Vegas Golden Knights", 7026454259);
}