#include <iostream>
#include <string>

 #include "HashTable.h"

void PopulateTable(HashTable<long long> &theTable);
template<typename Type> bool TestUserInput(Type &userInput, bool clearScreen = false);

int main()
{
	HashTable<long long> theTable(10);
	PopulateTable(theTable);

	std::string teams[39] = { "Anaheim Ducks", "Arizona Coyotes", "Calgary Flames", "Edmonton Oilers", "Los Angeles Kings", "San Jose Sharks", 
		"Vancouver Canucks", "Vegas Golden Knights", "Chicago Blackhawks", "Colorado Avalanche", "Dallas Stars", "Minnesota Wild", 
		"Nashville Predators", "St. Louis Blues", "Winnipeg Jets", "Carolina Hurricanes", "Columbus Blue Jackets", "New Jersey Devils",
		"New York Islanders", "New York Rangers", "Philadelphia Flyers", "Pittsburgh Penguins", "Washington Capitals", "Boston Bruins", 
		"Buffalo Sabres", "Detroit Red Wings", "Florida Panthers", "Montréal Canadiens", "Ottawa Senators", "Tampa Bay Lightning", 
		"Toronto Maple Leafs", "Seattle Expansion"};

	bool runProgram = true;
	std::string output = "";
	int menuInput;

	while (runProgram)
	{
		system("cls");

		std::cout <<
			"***********************************************************************************************************************\n"
			"*************************                  NHL Ticket  Information Directory                  *************************\n"
			"***********************************************************************************************************************\n"
			"  Pacific Division:            Central Division:            Metropolitan Division:            Atlantic Division:     \n"
			"\n"
			"  01. " << teams[0] << "            09. "	 << teams[8] << "     "
			"  16. " << teams[15] << "           24. "	 << teams[23] << "\n"
			"  02. " << teams[1] << "          10. "	 << teams[9] << "     "
			"  17. " << teams[16] << "         25. "	 << teams[24] << "\n"
			"  03. " << teams[2] << "           11. "	 << teams[10] << "           "
			"  18. " << teams[17] << "             26. " << teams[25] << "\n"
			"  04. " << teams[3] << "          12. "	 << teams[11] << "         "
			"  19. " << teams[18] << "            27. "  << teams[26] << "\n"
			"  05. " << teams[4] << "        13. "		 << teams[12] << "    "
			"  20. " << teams[19] << "              28. " << teams[27] << "\n"
			"  06. " << teams[5] << "          14. "	 << teams[13] << "        "
			"  21. " << teams[20] << "           29. "	 << teams[28] << "\n"
			"  07. " << teams[6] << "        15. "		 << teams[14] << "          "
			"  22. " << teams[21] << "           30. "	 << teams[29] << "\n"
			"  08. " << teams[7] << "                                "
			"  23. " << teams[22] << "           31. "	 << teams[30] << "\n"
			"\n\n"
			"  32. " << teams[31] << "\n"
			"\n"
			"***********************************************************************************************************************\n"
			"*****   Please enter a team number for information, 311 to see the hash table's contents, or enter 98 to quit.    *****\n"
			"***********************************************************************************************************************\n"
			"\n" << output << "\n\n"
			"Your choice: ";

		output = "";

		if (TestUserInput(menuInput, false))
		{
			if (menuInput > 0 && menuInput < 32)
			{
				long long phoneNumber = theTable.Retrieve(teams[menuInput - 1]);

				if (phoneNumber != -1)
				{
					output = teams[menuInput - 1] + " Ticket Sales Contact Number: " + std::to_string(phoneNumber);
				}
				else
				{
					output = "Information could not be found.";
				}
			}
			else if (menuInput == 32)
			{
			output = "Ticket sales for the Seattle expansion team have not yet started.\n"
				"Check back before the 2021-22 season!";
			}
			else if (menuInput == 311)
			{
				system("cls");
				theTable.PrintTable();
				system("pause");
			}
			else if (menuInput == 98)
			{
				// Exit program
				runProgram = false;
			}
			else
			{
				output = "Invalid choice.";
			}
		}
	}

	return 0;
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

// Gets user input
template<typename Type> bool TestUserInput(Type &userInput, bool clearScreen)
{
	bool failure;

	std::cin >> userInput;

	if (clearScreen)
	{
		system("cls");
	}
	else
	{
		std::cout << std::endl;
	}

	// Checks to see if there were any problems getting the user's input
	failure = std::cin.fail();
	// Clears cin's failure flag for next input
	std::cin.clear();
	// Clears the input buffer
	std::cin.ignore(256, '\n');

	if (failure) // User did not input a valid value
	{
		std::cout << "Invalid entry. Please try again." << std::endl;
	}

	// Returns whether the input was valid (true) or not (false)
	return !failure;
}