

#include <iostream>
#include <iomanip> // For IO manipulators
#include <string> // For strings
#include <algorithm> // For transform to upper function
#include <fstream> // For file I/O
using namespace std;

// Constants that will be used
const int col_width = 60;
const string welcome_text = " Welcome to my Letter Count Program ";
const string num_A_txt = "The number of A's: ";
const string num_E_txt = "The number of E's: ";
const string num_I_txt = "The number of I's: ";
const string num_O_txt = "The number of O's: ";
const string num_U_txt = "The number of U's: ";
const string vowel_txt = "The vowel count is: ";
const string invalid_txt = "Invalid file, exiting...\n";
const int welcome_length = welcome_text.length();
const int num_txt_length = num_A_txt.length();
const int vowel_txt_length = vowel_txt.length();

// arg count and arg vector that will be passed in from cmd line
int main(int argc, char* argv[])
{

	// Setting fill and outputting welcome message
	cout << setfill('*');
	cout << setw(col_width) << '*' << endl;
	int col_remainder_each_side_after_text = (col_width - welcome_length) / 2; // Calculating the remainder of *'s that will be needed on each side of the text to meet the col_width
	cout << setw(col_remainder_each_side_after_text) << '*' << welcome_text << setw(col_remainder_each_side_after_text) << '*' << endl; //  Output centered welcome message
	cout << setw(col_width) << '*' << endl;

	// file variable, temp storage variable, and counter variables
	ifstream inData;
	char char_in;
	int num_A = 0, num_E = 0, num_I = 0, num_O = 0, num_U = 0;

	// Open file and check if it exists
	inData.open(argv[1]);
	if (!inData) // if no file, exit program
	{
		cout << invalid_txt;
		return 0;
	}
	else
	{
		cout << endl << "Analyzing file " << "'" << argv[1] << "'..." << endl << endl;
	}

	// Analyze until the end of file
	while (!inData.eof())
	{
		inData >> char_in;
		
		if (char_in == 'A' || char_in == 'a')
		{
			num_A++;
		}
		else if (char_in == 'E' || char_in == 'e')
		{
			num_E++;
		}
		else if (char_in == 'I' || char_in == 'i')
		{
			num_I++;
		}
		else if (char_in == 'O' || char_in == 'o')
		{
			num_O++;
		}
		else if (char_in == 'U' || char_in == 'u')
		{
			num_U++;
		}
	}
	// Close file
	inData.close();

	// Output results formatted
	cout << setfill('.');
	cout << num_A_txt  << setw(col_width - num_txt_length) << '.' << num_A << endl;
	cout << num_E_txt << setw(col_width - num_txt_length) << '.' << num_E << endl;
	cout << num_I_txt << setw(col_width - num_txt_length) << '.' << num_I << endl;
	cout << num_O_txt << setw(col_width - num_txt_length) << '.' << num_O << endl;
	cout << num_U_txt << setw(col_width - num_txt_length) << '.' << num_U << endl;
	cout << vowel_txt << setw(col_width - vowel_txt_length) << '.' << (num_A + num_E + num_I + num_O + num_U) << endl;

}

