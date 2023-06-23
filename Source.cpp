/**
 * Name: Nathalie Morales
 * Course: CS 210
 * Description: This program displays the time in 12-hour format and 24-hour format.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

unsigned int hour = 0;
unsigned int minute = 0;
unsigned int second = 0;

// Global variables to store hour, minute, and second in 24 hour format
int hour24, minute24, second24;

/**
 * Formats a number as 2 digits, with a leading 0 if needed
 *
 * @param n number to format, assumed between 0 and 59, inclusive
 * @return two digit string representation of number
 */
string twoDigitString(unsigned int n) {
    if (n < 10) {
        return "0" + to_string(n);
    }
    else {
        return to_string(n);
    }
}

/**
 * Create a string of a specified length with a specific character
 *
 * @param n the desired length of the string
 * @param c the character to repeat
 * @return a string of length n with all characters c
*/
string nCharString(size_t n, char c) {
    return string(n, c);
}

/**
 * Formats a time in 24 hour format
 *
 * @param h hour to format, assumed between 0 and 23, inclusive
 * @param m minute to format, assumed between 0 and 59, inclusive
 * @param s second to format, assumed between 0 and 59, inclusive
*/
string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    string hour = twoDigitString(h);
    string minute = twoDigitString(m);
    string second = twoDigitString(s);
    return hour + ":" + minute + ":" + second;
}

/**
 * Formats a time in 12 hour format
 *
 * @param h hour to format, assumed between 0 and 23, inclusive
 * @param m minute to format, assumed between 0 and 59, inclusive
 * @param s second to format, assumed between 0 and 59, inclusive
*/
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    string period = (h < 12) ? "A M" : "P M";
    if (h == 0) {
        h = 12;
    }
    else if (h > 12) {
        h -= 12;
    }
    string hour = twoDigitString(h);
    string minute = twoDigitString(m);
    string second = twoDigitString(s);
    return hour + ":" + minute + ":" + second + " " + period;
}

/**
 * Prints out the menu illustrated in the project
 *
 * @param menu the array of strings to print
 * @param size the number of elements in the array
 * @param width the width of the menu
*/
void printMenu(const string menu[], size_t size, size_t width) {
    cout << nCharString(width, '*') << endl;

    for (size_t i = 0; i < size; i++) {
        cout << "* " << i << "- " << menu[i];
        size_t spaces = width - menu[i].length() - to_string(i).length() - 3;
        cout << nCharString(spaces, ' ') << "*\n";
        if (i < size - 1) {
            cout << endl;
        }
    }

    cout << nCharString(width, '*') << endl;
}

/**
 * Processes user input from the menu choices in the user interface
 *
 * @param maxChoice the maximum valid choice
 * @return the user's choice
*/
unsigned int getMenuChoice(unsigned int maxChoice) {
    unsigned int choice;
    while (true) {
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice >= 1 && choice <= maxChoice) {
            break;
        }
        cout << "Invalid choice. Please try again." << endl;
    }
    return choice;
}

/**
 * Displays the clocks in 12 hour and 24 hour format
 *
 * @param h hour to display, assumed between 0 and 23, inclusive
 * @param m minute to display, assumed between 0 and 59, inclusive
 * @param s second to display, assumed between 0 and 59, inclusive
*/
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    string line27 = nCharString(27, '*');
    string spaces3 = nCharString(3, ' ');
    string spaces6 = nCharString(6, ' ');
    string spaces7 = nCharString(7, ' ');
    string spaces8 = nCharString(8, ' ');
    string spaces9 = nCharString(9, ' ');
    string lineBreak = "\n";

    cout << lineBreak << endl;
    cout << line27 << spaces3 << line27 << endl;
    cout << "*" << spaces6 << "12-HOUR CLOCK" << spaces6 << "*" << spaces3 << "*" << spaces6 << "24-HOUR CLOCK" << spaces6 << "*" << endl;
    cout << "*" << spaces6 << formatTime12(h, m, s) << spaces7 << "*" << spaces3 << "*" << spaces8 << formatTime24(h, m, s) << spaces9 << "*" << lineBreak;
    cout << line27 << spaces3 << line27 << endl;
}

/**
 * Sets the hour
 * @param h the hour to set
*/
void setHour(unsigned int h) {
    hour = h;
}

/**
 * Gets the hour
 * @return the hour
*/
unsigned int getHour() {
    return hour;
}

/**
 * Sets the minute
 * @param m the minute to set
*/
void setMinute(unsigned int m) {
    minute = m;
}

/**
 * Gets the minute
 * @return the minute
*/
unsigned int getMinute() {
    return minute;
}

/**
 * Sets the second
 * @param s the second to set
*/
void setSecond(unsigned int s) {
    second = s;
}

/**
 * Gets the second
 * @return the second
*/
unsigned int getSecond() {
    return second;
}

/**
 * Adds one hour to the time
*/
void addOneHour() {
    unsigned int currHour = getHour();
    if (currHour >= 0 && currHour <= 22) {
        setHour(currHour + 1);
    }
    else {
        setHour(0);
    }
}

/**
 * Adds one minute to the time
*/
void addOneMinute() {
    unsigned int currMinute = getMinute();
    if (currMinute >= 0 && currMinute <= 58) {
        setMinute(currMinute + 1);
    }
    else {
        setMinute(0);
        addOneHour();
    }
}

/**
 * Adds one second to the time
*/
void addOneSecond() {
    unsigned int currSecond = getSecond();
    if (currSecond >= 0 && currSecond <= 58) {
        setSecond(currSecond + 1);
    }
    else {
        setSecond(0);
        addOneMinute();
    }
}

// Function to display the menu
void displayMenu() {
    cout << "\n\n****************************" << endl;
    cout << "* 1-Add one hour           *" << endl;
    cout << "* 2-Add one minute         *" << endl;
    cout << "* 3-Add one second         *" << endl;
    cout << "* 4-Exit program           *" << endl;
    cout << "****************************" << endl;
}


// mainMenu function
void mainMenu() {
    unsigned int choice;
    do {
        displayClocks(getHour(), getMinute(), getSecond());
        displayMenu();
        choice = getMenuChoice(4);
        switch (choice) {
        case 1:
            addOneHour();
            break;
        case 2:
            addOneMinute();
            break;
        case 3:
            addOneSecond();
            break;
        case 4:
            cout << "Exiting program..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 4);

    cout << "Goodbye!" << endl;

}

int main() {
    mainMenu();
    return 0;
}
