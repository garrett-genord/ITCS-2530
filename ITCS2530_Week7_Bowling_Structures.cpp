#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Constants from file 
const int num_bowlers = 10;
const int num_games = 5;

// Bowler type struct
struct bowler_type
{
	string bowler_name;
	int scores[num_games];
	double avg_score;
};

// Function prototypes
bool GetBowlingData(char filename[], bowler_type arr[]); // Retrieves data from file, 0 if successful, -1 if error
void GetAverageScore(bowler_type arr[]); // Finds averages for each player
void PrettyPrintResults(bowler_type arr[]); // Outputs results

int main()
{
	// Arrays/variables
	bowler_type bowler_arr[num_bowlers];
	char file_name[] = "BowlingScores.txt\0";

	// Function calls
	GetBowlingData(file_name, bowler_arr);
	GetAverageScore(bowler_arr);
	PrettyPrintResults(bowler_arr);
}

void PrettyPrintResults(bowler_type arr[])
{
	// Printing out all results
	cout << "\nResults:\n\n\n";
	cout << "Format: Name Score1 Score2 Score3 Score4 Score5 Average\n";

	// Prints each bowler name, their scores, and then their avg
	for (int bowlers = 0; bowlers < num_bowlers; bowlers++)
	{
		cout << arr[bowlers].bowler_name << " ";

		for (int cols = 0; cols < (num_games); cols++)
		{
			cout << arr[bowlers].scores[cols] << " ";
		}

		cout << arr[bowlers].avg_score << endl;
	}

}
void GetAverageScore(bowler_type arr[])
{
	double temp_sum = 0;

	for (int bowlers = 0; bowlers < num_bowlers; bowlers++)
	{
		// find the summed scores for each bowler
		for (int games = 0; games < num_games; games++)
		{
			temp_sum += arr[bowlers].scores[games];
		}

		// divide by total number of games and reset the sum for the next bowler
		arr[bowlers].avg_score = temp_sum / num_games;
		temp_sum = 0;
	}
}


bool GetBowlingData(char filename[], bowler_type arr[])
{
	ifstream inData;
	inData.open(filename);

	if (!inData) // Return false on error
	{
		cout << "File does not exist\n";
		return false;
	}

	// Iterate down the rows, column by column
	for (int rows = 0; rows < num_bowlers; rows++)
	{
		// for each row, get the name and then the scores
		inData >> arr[rows].bowler_name;

		for (int cols = 0; cols < num_games; cols++)
		{
			inData >> arr[rows].scores[cols];
		}
	}

	// always close the file!
	inData.close();
	return true;
}




