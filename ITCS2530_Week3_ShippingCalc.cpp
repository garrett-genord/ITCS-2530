#include <iostream>
#include <iomanip> // For IO manipulators
#include <string> // For strings
#include <algorithm> // For transform to upper function
#include <fstream> // For file I/O

using namespace std;

// Indices for the cost matrix
#define INDEX_LESS_THAN_50 0
#define INDEX_50_TO_100 1
#define INDEX_100_TO_150 2
#define INDEX_OVER_150 3
#define INDEX_USA 0
#define INDEX_CAN 1
#define INDEX_AUS 2
#define INDEX_MAR 3

// Cost matrix
double cost_matrix[4][4] = { {6, 8, 10, 900},
                        {9, 12, 14, 312312321321},
                        {12, 15, 17, 0.01},
                        {0, 0, 0, 143} };


const string welcome_text = "ITCS 2530 - Programming Assignment for week #3"; // Intro message and length for console formatting
const int welcome_length = welcome_text.length();
const int input_col_width = welcome_length + 3; // The width of the input prompt window in columns
const int output_col_width = input_col_width - 10; // Width of the output text in columns, 10 was arbitrarily chosen and seemed to fit

// Strings to be sent to console
const string item_prompt = "Please enter the item name (no spaces)"; 
const string fragile_prompt = "Is the item fragile? (y=yes/n+no)";
const string order_prompt = "Please enter your order total";
const string dest_prompt = "Please enter your destination (usa/can/aus/mar)";
const string invalid_entry_string = "Invalid entry, exiting";
const string no_file_string = "Invalid file, exiting";
const string item_out_string = "Your item is";
const string ship_out_string = "Your shipping cost is";
const string ship_dest_out_string = "You are shipping to";
const string total_ship_cost_out_string = "Your total shipping costs are";
const string thank_out_string = "Thank You!";

// Function prototypes
int Get_Price_Index(double price); // Returns the appropriate price index based on the price
int Get_Dest_Index(string dest); // Returns destination index based on destination string
int Prompt_Get_Input(string* item_name, string* item_fragile, double* order_total, string* destination); // Outputs the prompts to the user and retrieves the data, returns the data by reference to each of its arguments
// Will return -1 on user input error


int main()
{
    // Will hold the input data
    string item_name;
    string item_fragile;
    double order_total;
    string destination;
    // Will hold the output data
    double shipping_cost;
    double total_cost;

    // Retrieve user input, if any error, exit the program
    if (Prompt_Get_Input(&item_name, &item_fragile, &order_total, &destination) == -1)
    {
        return 0;
    }

    // Find shipping cost from matrix
    shipping_cost = cost_matrix[Get_Price_Index(order_total)][Get_Dest_Index(destination)];
    // If item is fragile, add 2 dollars
    if (item_fragile == "Y") shipping_cost += 2.0;
    // Find total cost
    total_cost = shipping_cost + order_total;

    // Formatting output window
    cout << endl << fixed << showpoint << setprecision(2); // Output 2 decimals, show trailing 0's
    // Output the appropriate strings and spacing
    cout << setw(output_col_width) << item_out_string << item_name << endl;
    cout << setw(output_col_width) << ship_out_string << '$' << shipping_cost << endl;
    cout << setw(output_col_width) << ship_dest_out_string << destination << endl;
    cout << setw(output_col_width) << total_ship_cost_out_string << '$' << total_cost << endl;
    cout << endl << right << setfill('-') << setw(output_col_width) << '-' << thank_out_string << endl;


    ofstream outData; // Variable for file output

    outData.open("Order.txt"); // Open file

    outData << endl << fixed << left << showpoint << setprecision(2) << setfill('.'); // Formatting - Output 2 decimals, show trailing 0's, left justified, etc
    // Send the output to the file
    outData << setw(output_col_width) << item_out_string << item_name << endl;
    outData << setw(output_col_width) << ship_out_string << '$' << shipping_cost << endl;
    outData << setw(output_col_width) << ship_dest_out_string << destination << endl;
    outData << setw(output_col_width) << total_ship_cost_out_string << '$' << total_cost << endl;
    outData << endl << right << setfill('-') << setw(output_col_width) << '-' << thank_out_string << endl;
    outData.close(); // Close file

}

// Outputs prompt to user and retrieves input
int Prompt_Get_Input(string* item_name, string* item_fragile, double* order_total, string* destination)
{
    string input_item_name; // Will store the input here 
    string input_item_fragile;
    double input_order_total;
    string input_destination;

    // Welcome text
    cout << setfill('.');
    cout << setw(input_col_width) << '.' << endl;
    cout << welcome_text << endl;
    cout << setw(input_col_width) << '.' << endl << endl;

    // Item name prompt, retrieve, and convert to uppercase
    cout << left;
    cout << setw(input_col_width - 1) << item_prompt << ':'; // -1 accounts for the colon
    cin >> input_item_name;
    transform(input_item_name.begin(), input_item_name.end(), input_item_name.begin(), ::toupper);

    // Fragile prompt, retrieve, convert to uppercase, and error check
    cout << setw(input_col_width - 1) << fragile_prompt << ':'; // -1 accounts for the colon
    cin >> input_item_fragile;
    transform(input_item_fragile.begin(), input_item_fragile.end(), input_item_fragile.begin(), ::toupper);
    // If not a Y or N, end the program
    if (input_item_fragile != "N" && input_item_fragile != "Y")
    {
        cout << invalid_entry_string;
        return -1;
    }

    // order total prompt and retrieve
    cout << setw(input_col_width - 1) << order_prompt << ':'; // -1 accounts for the colon
    cin >> input_order_total;

    // Destination prompt, retrieve, convert to uppercase, and error check
    cout << setw(input_col_width - 1) << dest_prompt << ':'; // -1 accounts for the colon
    cin >> input_destination;
    // If not a valid destination, end the program
    transform(input_destination.begin(), input_destination.end(), input_destination.begin(), ::toupper);
    if (input_destination != "USA" && input_destination != "AUS" && input_destination != "CAN" && input_destination != "MAR")
    {
        cout << invalid_entry_string;
        return -1;
    }

    // Return the values via pointers
    *item_name = input_item_name;
    *item_fragile = input_item_fragile;
    *order_total = input_order_total;
    *destination = input_destination; 
    return 1; // Return 1 if no errors
}

// Gets the destination index
int Get_Dest_Index(string dest)
{

    if (dest == "USA")
    {
        return INDEX_USA;
    }

    if (dest == "CAN")
    {
        return INDEX_CAN;
    }

    if (dest == "AUS")
    {
        return INDEX_AUS;
    }
    
    if(dest == "MAR")
    {
        return INDEX_MAR;
    }
}

// Gets price index
int Get_Price_Index(double price)
{
    // I know these may be 'magic' numbers, but it would seem weird to me to declare them all as constants and then have each of the macro indices be called 50, 50_TO_100, etc
    if (price <= 50)
    {
        return INDEX_LESS_THAN_50;
    }

    if ((price <= 100) && (price > 50))
    {
        return INDEX_50_TO_100;
    }

    if ((price <= 150) && (price > 100))
    {
        return INDEX_100_TO_150;
    }

    if (price > 150)
    {
        return INDEX_OVER_150;
    }
}
