//Giogioanni Morales Completed on 9/16/2023
#include <iostream>
#include <string>
using namespace std;

// Function to display the instructions for the program
void displayWelcome()
{
    cout << "***********************************************" << endl;
    cout << "*                                             *" << endl;
    cout << "*      Chada Tech Interview Process!          *" << endl;
    cout << "*                                             *" << endl;
    cout << "***********************************************" << endl;
    cout << endl;

    cout << "***********************************************" << endl;
    cout << "*   INSTRUCTIONS:                             *" << endl;
    cout << "*   1. You will be asked to enter the time     *" << endl;
    cout << "*      in hours, minutes, and seconds.         *" << endl;
    cout << "*   2. The clock will be displayed in both     *" << endl;
    cout << "*      24-hour and 12-hour formats.            *" << endl;
    cout << "*   3. You will be given a menu to add hours,   *" << endl;
    cout << "*      minutes, or seconds, or to exit the     *" << endl;
    cout << "*      program.                                *" << endl;
    cout << "***********************************************" << endl;
    cout << endl;
}

// Function to display time in both 24-hour and 12-hour formats
void displayTime(int hour, int minute, int second)
{
    cout << "***********************************************" << endl;
    cout << "*      24-Hour Clock      *      12-Hour Clock *" << endl;
    cout << "*      ";

    // Display the time in 24-hour format
    cout << (hour < 10 ? "0" : "") << hour << ":";
    cout << (minute < 10 ? "0" : "") << minute << ":";
    cout << (second < 10 ? "0" : "") << second << "      ";

    // Initialize period for 12-hour format
    string period = "AM";

    // Convert the time to 12-hour format
    if (hour >= 12) {
        period = "PM";
        if (hour > 12)
            hour = hour - 12;
    }
    else {
        if (hour == 0)
            hour = 12;
    }

    cout << (hour < 10 ? "0" : "") << hour << ":";
    cout << (minute < 10 ? "0" : "") << minute << ":";
    cout << (second < 10 ? "0" : "") << second << " " << period;

    cout << "          *" << endl;
    cout << "***********************************************" << endl;
}

// The main function
int main()
{
    // Display the welcome message with instructions
    displayWelcome();

    // Declare and initialize variables
    int hour, minute, second;

    // Get initial time input from the user
    cout << "Enter Hour: ";
    cin >> hour;
    cout << "Enter Minute: ";
    cin >> minute;
    cout << "Enter Second: ";
    cin >> second;

    // Display the initial time in both formats
    displayTime(hour, minute, second);

    // Loop until the user chooses to exit
    while (true)
    {
        // Display the menu for the user to select from in an asterisk box
        cout << "***********************************************" << endl;
        cout << "* Menu:                                       *" << endl;
        cout << "* 1. Add Hour                                 *" << endl;
        cout << "* 2. Add Minute                               *" << endl;
        cout << "* 3. Add Second                               *" << endl;
        cout << "* 4. Exit                                     *" << endl;
        cout << "***********************************************" << endl;

        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            hour++;
            // Reset hour to 0 if it reaches 24
            if (hour == 24)
                hour = 0;
            break;
        case 2:
            minute++;
            // If minute reaches 60, reset it to 0 and increment hour
            if (minute == 60) {
                minute = 0;
                hour++;
                if (hour == 24)
                    hour = 0;
            }
            break;
        case 3:
            second++;
            // If second reaches 60, reset it to 0 and increment minute
            if (second == 60) {
                second = 0;
                minute++;
                if (minute == 60) {
                    minute = 0;
                    hour++;
                    if (hour == 24)
                        hour = 0;
                }
            }
            break;
        case 4:
            // Exit the program if the user chooses to
            cout << "Exiting...";
            return 0;
        default:
            // For invalid choices, display an error message to the user
            cout << "Invalid choice! Please try again\n";
            break;
        }
        // Display the updated time in both formats
        displayTime(hour, minute, second);
    }
    return 0;
}