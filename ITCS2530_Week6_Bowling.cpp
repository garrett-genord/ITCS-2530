// ITCS2530_Week6_Bowling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// Constants from file 
const int num_bowlers = 10;
const int num_games = 4;

// Function prototypes
int GetBowlingData(char filename[], string names[], int scores[][num_games]); // Retrieves data from file, 0 if successful, -1 if error
void GetAverageScore(int scores[][num_games], double avg[]); // Finds averages for each player
void PrettyPrintResults(string names[], int scores[][num_games], double avg[]); // Outputs results

int main()
{
	// Arrays/variables
	string bowler_names[num_bowlers];
	int game_scores[num_bowlers][num_games];
	double avg_scores[num_bowlers];
	char file_name[] = "BowlingScores.txt\0";

	// Function calls
	GetBowlingData(file_name, bowler_names, game_scores);
	GetAverageScore(game_scores, avg_scores);
	PrettyPrintResults(bowler_names, game_scores, avg_scores);
}


void PrettyPrintResults(string names[], int scores[][num_games], double avg[])
{
	// Printing out all results
	cout << "\nResults:\n\n\n";
	cout << "Format: Name Score1 Score2 Score3 Score4 Average\n";
	
	// Prints each bowler name, their scores, and then their avg
	for (int bowlers = 0; bowlers < num_bowlers; bowlers++)
	{
		cout << names[bowlers] << " ";

		for (int cols = 0; cols < (num_games); cols++)
		{
			cout << scores[bowlers][cols] << " ";
		}

		cout << avg[bowlers] << endl;
	}
}

int GetBowlingData(char filename[], string names[], int scores[][num_games])
{
	ifstream inData;
	inData.open(filename);

	if (!inData) // Return -1 on error
	{
		cout << "File does not exist\n";
		return -1;
	}

	// Iterate down the rows, column by column
	for (int rows = 0; rows < num_bowlers; rows++)
	{
		// for each row, get the name and then the scores
		inData >> names[rows];

		for (int cols = 0; cols < num_games; cols++)
		{
			inData >> scores[rows][cols];
		}
	}

	// always close the file!
	inData.close();
	return 0;
}

void GetAverageScore(int scores[][num_games], double avg[])
{
	double temp_sum = 0;

	for (int bowlers = 0; bowlers < num_bowlers; bowlers++)
	{
		// find the summed scores for each bowler
		for (int games = 0; games < num_games; games++)
		{
			temp_sum += scores[bowlers][games];
		}
		
		// divide by total number of games and reset the sum for the next bowler
		avg[bowlers] = temp_sum / num_games;
		temp_sum = 0;
	}
}

