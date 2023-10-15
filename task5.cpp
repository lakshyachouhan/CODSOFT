/*    TASK 5 - MOVIE TICKET BOOKING SYSYTEM
Develop a program that simulates a movie ticket booking system.
Allow users to view movie listings, select seats, make bookings,
and calculate the total cost. Consider implementing seat
availability and seat selection validation.
 */
/* NAME - LAKSHYA CHOUHAN
   ID: CS07WX75038         */

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Movie
{
public:
    string title;
    string time;
    double price;
    vector<vector<bool>> seatingMap;

    Movie(const string &t, const string &tm, double p, int rows, int cols)
        : seatingMap(rows, vector<bool>(cols, true))
    {
        title = t;
        time = tm;
        price = p;
    }

    bool isSeatAvailable(int row, int col)
    {
        return seatingMap[row][col];
    }

    void bookSeat(int row, int col)
    {
        seatingMap[row][col] = false;
    }

    int getAvailableSeatCount()
    {
        int availableCount = 0;
        for (int i = 0; i < seatingMap.size(); ++i)
        {
            for (int j = 0; j < seatingMap[i].size(); ++j)
            {
                if (seatingMap[i][j])
                {
                    availableCount++;
                }
            }
        }
        return availableCount;
    }
};

class Booking
{
public:
    Movie movie;
    int selectedSeats;
    double totalCost;

    Booking(const Movie &m, int seats): movie(m)
    {
        movie = m;
        selectedSeats = seats;
        totalCost = m.price * seats;
    }
};

vector<Movie> movies;
vector<Booking> bookings;

void showMovieList()
{
    cout << "Available Movies:" << endl;
    cout << "-----------------" << endl;

    for (size_t i = 0; i < movies.size(); ++i)
    {
        Movie &movie = movies[i];
        int availableSeats = movie.getAvailableSeatCount();
        cout << "[" << i + 1 << "] " << movie.title << " at " << movie.time
             << " (Rs" << movie.price << ") - Available Seats: " << availableSeats << endl;
    }

    cout << "-----------------" << endl;
}

void bookingMovie()
{
    showMovieList();
    int choice;
    cout << "Select a movie (enter its number): ";
    cin >> choice;

    if (choice < 1 || choice > static_cast<int>(movies.size()))
    {
        cout << "Invalid choice." << endl;
        return;
    }

    Movie &selectedMovie = movies[choice - 1];

    cout << "Available seats for " << selectedMovie.title << ":" << endl;
    for (int i = 0; i < selectedMovie.seatingMap.size(); ++i)
    {
        for (int j = 0; j < selectedMovie.seatingMap[i].size(); ++j)
        {
            if (selectedMovie.isSeatAvailable(i, j))
            {
                cout << "[" << i + 1 << "," << j + 1 << "] ";
            }
            else
            {
                cout << "  X   "; // X indicates a booked seat
            }
        }
        cout << endl;
    }
    
    int totalAvailable =  selectedMovie.seatingMap.size()*selectedMovie.seatingMap[2].size();
    int numSeats;
    cout << "How many seats would you like to book? ";
    cin >> numSeats;

    if (numSeats <= 0 || numSeats > totalAvailable)
    {
        cout << "Invalid number of seats." << endl;
        return;
    }

    int bookedSeats = 0;
    vector<pair<int, int>> selectedSeats;

    while (bookedSeats < numSeats)
    {
        int row, col;
        cout << "Select a seat (row and column): ";
        cin >> row >> col;
        row--; // Converting to zero-based indexing
        col--;

        if (row >= 0 && row < static_cast<int>(selectedMovie.seatingMap.size()) &&
            col >= 0 && col < static_cast<int>(selectedMovie.seatingMap[0].size()) &&
            selectedMovie.isSeatAvailable(row, col))
        {
            selectedSeats.push_back({row, col});
            selectedMovie.bookSeat(row, col);
            bookedSeats++;
        }
        else
        {
            cout << "Invalid seat selection. Please try again." << endl;
        }
    }

    Booking newBooking(selectedMovie, numSeats);
    bookings.push_back(newBooking);

    cout << "\nSuccessfully booked " << numSeats << " seat(s) for " << selectedMovie.title << ". Total cost: Rs " << newBooking.totalCost << endl;
}

int main()
{
    movies.push_back(Movie("Movie 1", "9:00 AM", 100.0, 5,5));
    movies.push_back(Movie("Movie 2", "12:30 PM", 120.0,5,5));
    movies.push_back(Movie("Movie 3", "4:00 PM", 180.0, 5,5));

    while (true)
    {
        cout << "Movie Ticket Booking System" << endl<<endl;
        cout << "-----------------------------" << endl;
        cout << "|  [1] View Movie Listings  |" << endl;
        cout << "|  [2] Book a Movie         |" << endl;
        cout << "|  [3] Exit                 |" << endl;
        cout << "-----------------------------" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            showMovieList();
            break;
        case 2:
            bookingMovie();
            break;
        case 3:
            cout << "Thank you for using the Movie Ticket Booking System. Have a good journey!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please select a valid option." << endl;
            break;
        }
    }

    return 0;
}
