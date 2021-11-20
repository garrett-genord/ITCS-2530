// ITCS2530_Week5_SurfShop.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip> // For IO manipulators
#include <string> // For strings
#include <cctype> // for toupper

using namespace std;

// function prototypes
void ShowUsage(); // displays option menu to user
void MakePurchase(int& iTotalXS, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge); // makes purchase and modifies the passed in counts of boards
void DisplayPurchase(const int iTotalXS, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge); // uses passed in counts to display number of boards purchased
void DisplayTotal(const int iTotalXS, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge); // displays totaal # of surfboards purchased and cost

// constants
const int col_width = 60;
const string welcome_message = " Welcome to my Johnny Utah's PointBreak Surf Shop ";
const int welcome_length = welcome_message.length();

const double cost_per_XS_board = 1234.0;
const double cost_per_small_board = 175.0;
const double cost_per_medium_board = 190.0;
const double cost_per_large_board = 200.0;

int main()
{
	// for user input and count number of boards purchased
	char user_input;
	int num_XS = 0, num_small = 0, num_med = 0, num_large = 0;

	// Formatting welcome message and option menu
	cout << fixed << showpoint << setprecision(2) << setfill('*') << setw(col_width) << '*' << endl;
	int col_remainder_each_side_after_text = (col_width - welcome_length) / 2; // Calculating the remainder of *'s that will be needed on each side of the text to meet the col_width
	cout << setw(col_remainder_each_side_after_text) << '*' << welcome_message << setw(col_remainder_each_side_after_text) << '*' << endl; //  Output centered welcome message
	cout << setw(col_width) << '*' << endl;
	ShowUsage();

	do // Keep asking user until the quit the program
	{
		cout << "\nPlease enter selection: ";
		cin >> user_input;

		// Make decision based on what user enters
		switch (toupper(user_input))
		{
		case 'S':
			ShowUsage();
			break;
		case 'P':
			MakePurchase(num_XS ,num_small, num_med, num_large);
			break;
		case 'C':
			DisplayPurchase(num_XS, num_small, num_med, num_large);
			break;
		case 'T':
			DisplayTotal(num_XS, num_small, num_med, num_large);
			break;
		}
	} while (toupper(user_input) != 'Q');
}

// Outputs menu
void ShowUsage()
{
	cout << endl << "To show program usage 'S'\n" << "To purchase a surfboard press 'P'\n" << "To display current purchases press 'C\n" << "To display total amount due press 'T'\n" << "To quit the program press 'Q'\n";
}

// Makes a purchase and modifies the parameter passed to it in main
void MakePurchase(int& iTotalXS, int& iTotalSmall, int& iTotalMedium, int& iTotalLarge)
{
	int num_in = 0;
	char type_in;

	// prompt user and retrieve input
	cout << "Please enter the quantity and type (X =Xsmall, S=small, M=medium, L=large) or surfboard\nyou would like to purchase:";
	cin >> num_in; cin >> type_in;

	// make purchase
	switch (toupper(type_in))
	{
	case 'X': 
		iTotalXS += num_in;
		break;
	case 'S':
		iTotalSmall += num_in;
		break;
	case 'M':
		iTotalMedium += num_in;
		break;
	case 'L':
		iTotalLarge += num_in;
		break;
	}

}

// Displays # boards purchased
void DisplayPurchase(const int iTotalXS, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
	if ((iTotalXS == 0) &&(iTotalSmall == 0) && (iTotalMedium == 0) && (iTotalLarge == 0)) // If no purchases made, don't need to execute following code
	{
		cout << "No purchases made yet\n";
		return;
	}

	if(iTotalXS != 0)
	{
		cout << "The total number of Xsmall surfboards is " << iTotalXS << endl;
	}
	
	if (iTotalSmall != 0)
	{
		cout << "The total number of small surfboards is " << iTotalSmall << endl;
	}

	if (iTotalMedium != 0)
	{
		cout << "The total number of medium surfboards is " << iTotalMedium << endl;
	}

	if (iTotalLarge != 0)
	{
		cout << "The total number of large surfboards is " << iTotalLarge << endl;
	}
}

// Displays # boards purchased and cost
void DisplayTotal(const int iTotalXS, const int iTotalSmall, const int iTotalMedium, const int iTotalLarge)
{
	if ((iTotalXS == 0) && (iTotalSmall == 0) && (iTotalMedium == 0) && (iTotalLarge == 0)) // If nothing purchased, can leave function
	{
		cout << "No purchases made yet\n";
		return;
	}

	if (iTotalXS != 0)
	{
		cout << "The total number of Xsmall surfboards is " << iTotalXS << " at a total of $" << iTotalXS *cost_per_XS_board << endl;
	}
	
	if (iTotalSmall != 0)
	{
		cout << "The total number of small surfboards is " << iTotalSmall << " at a total of $" << iTotalSmall *cost_per_small_board << endl;
	}

	if (iTotalMedium != 0)
	{
		cout << "The total number of medium surfboards is " << iTotalMedium << " at a total of $" << iTotalMedium * cost_per_medium_board << endl;
	}

	if (iTotalLarge != 0)
	{
		cout << "The total number of large surfboards is " << iTotalLarge << " at a total of $" << iTotalLarge * cost_per_large_board << endl;
	}

	cout << "Amount due: $" << (iTotalXS * cost_per_XS_board) + (iTotalLarge * cost_per_large_board) + (iTotalMedium * cost_per_medium_board) + (iTotalSmall * cost_per_small_board) << endl;
}
