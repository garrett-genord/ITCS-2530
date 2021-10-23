#include <iostream>
#include <string> 
// Including string header file for string datatypes

using namespace std; // using std namespace in iostream header file for cin, cout

int main()
{
    const int sec_per_min = 60; // Constant conversion factors 
    const int min_per_hour = 60;
    // Strings that will be printed to console 
    string prompt_line1 = "************************************************************************************\n"; // Using /n instead of endl for ease when possible
    string prompt_line2 = "************************* Welcome to my first program ******************************\n";
    string prompt_line3 = "This program will convert a large number of seconds into hours, minutes, and seconds\n";
    string prompt_line4 = "************************************************************************************\n";
    string prompt_line5 = "\nPlease enter a large number of seconds: ";
    string output_line1 = "Number of hours in the number is: ";
    string output_line2 = "Number of minutes in the number is: ";
    string output_line3 = "Number of seconds in the number is: ";

    int num_sec_input; // Will hold number of seconds input
    // These will hold the final sec, min, hr numbers 
    int num_sec; 
    int num_min;
    int num_hour;
    // Temp variable used during calculation
    int temp_sec_holder;
    
    cout << prompt_line1 << prompt_line2 << prompt_line3 << prompt_line4 << prompt_line5; // Sending out prompts
 
    cin >> num_sec_input; // Retrieving user input
    
    num_hour = num_sec_input / sec_per_min / min_per_hour; // Finding number of hours w/ conversion factors, if it is less than 1, int math will force it to 0
    num_sec = num_sec_input % sec_per_min; // Number of seconds will always be the remainder when dividing total number of seconds by 60 (b/c divide by 60 to find minutes/hrs)

    // If there is an hour or more in number of seconds (!=0 is ok for integer math), the number of minutes can be found by subtracting out the  
    // hours and then dividing that by 60 
    if (num_hour != 0) 
    {
        temp_sec_holder = num_sec_input - (sec_per_min * min_per_hour * num_hour); //Remaining seconds after subtracting out the hours
        num_min = temp_sec_holder / sec_per_min; // Calculating number of minutes
    } 
    else // If there isn't a whole hour, then just divide by 60 to find the total number of minutes
    {
        num_min = num_sec_input / sec_per_min;
    }
    
    // Outputting results
    cout <<  output_line1 << num_hour << endl;
    cout <<  output_line2 << num_min << endl;
    cout <<  output_line3 << num_sec << endl;

    return 0;
}

// Initial thought process, but this didnt work b/c would give total number, not the hours, minutes, seconds format
//num_sec = (num_sec_input % 60);
//num_min = num_sec_input / sec_per_min;
//num_hour = num_min / min_per_hour;