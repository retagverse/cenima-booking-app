#include <iostream>
#include <string>
using namespace std;

string movieNames[5] = {
    "Project Hail Mary",
    "The Backrooms",
    "Michael",
    "Obsession",
    "7 Dogs"
};

double moviePrices[5] = {
    150.00,
    120.00,
    100.00,
    90.00,
    80.00
};

void printLine()
{
    cout << "-------------------------------------------" << endl;
}

void showWelcome()
{
    printLine();
    cout << "     Welcome to Star Cinema!" << endl;
    cout << "     Ticket Booking System" << endl;
    printLine();
}

void showMovies()
{
    cout << endl;
    printLine();
    cout << "         Movies Now Showing:" << endl;
    printLine();

    for (int i = 0; i < 5; i++)
    {
        cout << i + 1 << ". " << movieNames[i] << endl;
        cout << "   Price: " << moviePrices[i] << " EGP" << endl;
        cout << endl;
    }

    printLine();
}

int getMovieChoice()
{
    int choice;

    while (true)
    {
        cout << "Enter movie number (1-5): ";
        cin >> choice;

        if (choice >= 1 && choice <= 5)
        {
            return choice - 1;
        }
        else
        {
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    }
}

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

double calcTotal(double price, int tickets)
{
    double total = price * tickets;
    return total;
}

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

bool bookAgain()
{
    char answer;

    while (true)
    {
        cout << "Do you want to book another movie? (y/n): ";
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

int main()
{
    int totalBookings = 0;
    double grandTotal = 0;
    bool keepGoing = true;

    showWelcome();

    while (keepGoing == true)
    {
        showMovies();

        int movieIndex = getMovieChoice();

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

        int numTickets = getTicketCount();

        double total = calcTotal(moviePrices[movieIndex], numTickets);

        showSummary(movieIndex, numTickets, total);

        totalBookings = totalBookings + 1;
        grandTotal = grandTotal + total;

        keepGoing = bookAgain();
    }

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
