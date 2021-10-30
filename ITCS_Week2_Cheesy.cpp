

#include <iostream>
#include <iomanip> // For IO manipulators
#include <string> // For strings
#include <cmath> // For the rounding function

using namespace std;

// Provided constants
const float cheese_per_container = 2.76; //kg
const float cost_per_container = 4.12; // dollars
const float profit_per_container = 1.45; // dollars

// Constants that can be declared before main
const int col_width = 80; // The width of the window in columns
const string welcome_text = "Welcome to my Cheesy Program"; // Intro message and length
const int welcome_length = welcome_text.length();
const string prompt_text = "Please enter the total number of kilograms of cheese produced: "; // Prompt message and lengtj
const int prompt_length = prompt_text.length();
const string num_cont_hold = "The number of containers to hold the cheese is: "; // First output string after input that does not depend on input
const int num_cont_hold_length = num_cont_hold.length();



int main()
{
	// Variables to hold values that will be output
	int num_kg_cheese;
	int num_containers;
	float total_cost;
	float total_profit;

	// Outputting a ling of col_with astericks
	cout << setfill('*');
	cout << setw(col_width) << '*' << endl;

	int col_remainder_each_side_after_text = (col_width - welcome_length) / 2; // Calculating the remainder of *'s that will be needed on each side of the text to meet the col_width
	cout << setw(col_remainder_each_side_after_text) << '*' << welcome_text << setw(col_remainder_each_side_after_text) << '*' << endl; //  Output centered welcome message
	cout << setw(col_width) << '*' << endl; // Output 80 *'s

	cout << endl << prompt_text; // Prompting user and retrieving input
	cin >> num_kg_cheese;

	// Making calculations
	num_containers = round(num_kg_cheese / cheese_per_container); // Rounding to nearest integer
	total_cost = num_containers * cost_per_container;
	total_profit = num_containers * profit_per_container;

	cout << setfill(' '); // Now using spaces to fill 
	cout << num_cont_hold << setw(col_width - num_cont_hold_length) << num_containers << endl; // Outputting number of containers, already has length calculated as a global

	const string cost_prod_text = "The cost of producing " + to_string(num_containers) + " container(s) of cheese is: $"; // Making next string to output - cost of producing
	const int cost_prod_text_length = cost_prod_text.length();  // Finding length

	cout << fixed << showpoint <<  setprecision(2); // Output 2 decimals, show trailing 0's
	cout << cost_prod_text << setw(col_width - cost_prod_text_length) << total_cost << endl; // Output cost string with right justified value

	const string profit_text = "The profit from producing " + to_string(num_containers) + "container(s) of cheese is: $"; // Making the profit string 
	const int profit_text_length = profit_text.length(); // Finding its length

	cout << profit_text << setw(col_width - profit_text_length) << total_profit << endl; // Output profit string with right justified value
}


// I first tried to subtract of the length of the text divided by to from the toal col_width, but that did not work how I thought it would
//cout << setw(col_width - prompt_length_div2 - prompt_length - 1) << '*' << endl; 
//cout << setw(80 - 28 - 28) << prompt_text;
//<< setw(80 - 29 - 29) << '*';
