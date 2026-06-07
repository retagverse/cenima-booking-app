// Cinema Ticket Booking System
// Made by: [Your Name]
// This program lets users book movie tickets and shows the total price

#include <iostream>
#include <string>
using namespace std;

// I put the movie info in arrays so its easier to manage
// All arrays use the same index, so index 0 = movie 1, index 1 = movie 2, etc.
string movieNames[5] = {
    "Project Hail Mary",
    "The Backrooms",
    "Michael",
    "Obsession",
    "7 Dogs"
};

// each movie has a different price (in EGP)
double moviePrices[5] = {
    150.00,   // Project Hail Mary
    120.00,   // The Backrooms
    100.00,   // Michael
    90.00,    // Obsession
    80.00     // 7 Dogs
};

// -----------------------------------------------
// this function just prints a line to make it look nicer
void printLine()
{
    cout << "-------------------------------------------" << endl;
}

// -----------------------------------------------
// this function shows the welcome message at the start
void showWelcome()
{
    printLine();
    cout << "     Welcome to Star Cinema!" << endl;
    cout << "     Ticket Booking System" << endl;
    printLine();
}

// -----------------------------------------------
// this function prints all the movies with their prices
void showMovies()
{
    cout << endl;
    printLine();
    cout << "         Movies Now Showing:" << endl;
    printLine();

    // i used a for loop here so i dont have to write cout 5 times
    for (int i = 0; i < 5; i++)
    {
        // i + 1 because arrays start at 0 but the menu should start at 1
        cout << i + 1 << ". " << movieNames[i] << endl;
        cout << "   Price: " << moviePrices[i] << " EGP" << endl;
        cout << endl;
    }

    printLine();
}

// -----------------------------------------------
// this function asks the user to pick a movie
// it keeps asking until the user enters a valid number
// it returns a number from 0 to 4 (the array index)
int getMovieChoice()
{
    int choice;

    while (true)
    {
        cout << "Enter movie number (1-5): ";
        cin >> choice;

        // check if the number is valid
        if (choice >= 1 && choice <= 5)
        {
            // subtract 1 to turn it into an array index
            return choice - 1;
        }
        else
        {
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    }
}

// -----------------------------------------------
// this function asks how many tickets the user wants
// max is 10 tickets per booking
int getTicketCount()
{
    int tickets;

    while (true)
    {
        cout << "How many tickets do you want? (1-10): ";
        cin >> tickets;

        if (tickets >= 1 && tickets <= 10)
        {
            return tickets;
        }
        else
        {
            cout << "Please enter a number between 1 and 10." << endl;
        }
    }
}

// -----------------------------------------------
// this function calculates the total price
// i pass in the price and number of tickets and it returns the total
double calcTotal(double price, int tickets)
{
    double total = price * tickets;
    return total;
}

// -----------------------------------------------
// this function prints the booking summary (like a receipt)
void showSummary(int movieIndex, int tickets, double total)
{
    cout << endl;
    printLine();
    cout << "         Booking Summary" << endl;
    printLine();
    cout << "Movie:          " << movieNames[movieIndex] << endl;
    cout << "Ticket Price:   " << moviePrices[movieIndex] << " EGP" << endl;
    cout << "No. of Tickets: " << tickets << endl;
    printLine();
    cout << "TOTAL:          " << total << " EGP" << endl;
    printLine();
    cout << "Booking confirmed! Enjoy the movie :)" << endl;
    printLine();
    cout << endl;
}

// -----------------------------------------------
// this function asks if the user wants to book again
// returns true if yes, false if no
bool bookAgain()
{
    char answer;

    while (true)
    {
        cout << "Do you want to book another movie?  ";
        cin >> answer;

        if (answer == 'y' || answer == 'Y')
        {
            return true;
        }
        else if (answer == 'n' || answer == 'N')
        {
            return false;
        }
        else
        {
            cout << "Please enter y or n." << endl;
        }
    }
}

// -----------------------------------------------
// MAIN FUNCTION
// this is where the program starts running
int main()
{
    // variables to keep track of the whole session
    int totalBookings = 0;
    double grandTotal = 0;
    bool keepGoing = true;

    showWelcome();

    // this loop keeps running until the user says they dont want more tickets
    while (keepGoing == true)
    {
        // step 1 - show the movies
        showMovies();

        // step 2 - ask which movie they want
        int movieIndex = getMovieChoice();

        // step 3 - confirm the choice using switch
        cout << endl << "You picked: ";
        switch (movieIndex)
        {
            case 0: cout << "Project Hail Mary"; break;
            case 1: cout << "The Backrooms";     break;
            case 2: cout << "Michael";           break;
            case 3: cout << "Obsession";         break;
            case 4: cout << "7 Dogs";            break;
        }
        cout << endl;

        // step 4 - ask how many tickets
        int numTickets = getTicketCount();

        // step 5 - calculate the total
        double total = calcTotal(moviePrices[movieIndex], numTickets);

        // step 6 - show the summary
        showSummary(movieIndex, numTickets, total);

        // step 7 - add to session totals
        totalBookings = totalBookings + 1;
        grandTotal = grandTotal + total;

        // step 8 - ask if they want to book again
        keepGoing = bookAgain();
    }

    // when the user is done, show a goodbye message with session totals
    cout << endl;
    printLine();
    cout << "Thanks for using Star Cinema!" << endl;
    cout << "Total bookings:  " << totalBookings << endl;
    cout << "Total paid:      " << grandTotal << " EGP" << endl;
    printLine();
    cout << "See you next time!" << endl;
    printLine();
    cout << endl;

    return 0;
}
