#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

// -----------------------------
// Movie Class
// -----------------------------
class Movie
{
private:
    int movieId;
    string name;
    string genre;
    string duration;
    float rating;
    int ticketPrice;

public:
    Movie(int id, string n, string g, string d, float r, int price)
    {
        movieId = id;
        name = n;
        genre = g;
        duration = d;
        rating = r;
        ticketPrice = price;
    }

    void displayMovie()
    {
        cout << "\nMovie ID      : " << movieId;
        cout << "\nMovie Name    : " << name;
        cout << "\nGenre         : " << genre;
        cout << "\nDuration      : " << duration;
        cout << "\nRating        : " << rating << "/10";
        cout << "\nTicket Price  : Rs. " << ticketPrice << endl;
    }

    int getId() { return movieId; }
    string getName() { return name; }
    int getPrice() { return ticketPrice; }
};

// -----------------------------
// Booking Class
// -----------------------------
class Booking
{
private:
    int bookingId;
    string customerName;
    string mobileNumber;
    string movieName;
    int numberOfTickets;
    int totalAmount;

public:
    Booking(int id, string customer, string mobile,
            string movie, int tickets, int amount)
    {
        bookingId = id;
        customerName = customer;
        mobileNumber = mobile;
        movieName = movie;
        numberOfTickets = tickets;
        totalAmount = amount;
    }

    int getBookingId() { return bookingId; }

    void displayBooking()
    {
        cout << "\n================================";
        cout << "\n        BOOKING DETAILS";
        cout << "\n================================";
        cout << "\nBooking ID      : " << bookingId;
        cout << "\nCustomer Name   : " << customerName;
        cout << "\nMobile Number   : " << mobileNumber;
        cout << "\nMovie Name      : " << movieName;
        cout << "\nTickets         : " << numberOfTickets;
        cout << "\nTotal Amount    : Rs. " << totalAmount;
        cout << "\n================================\n";
    }
};

// -----------------------------
// Main Function
// -----------------------------
int main()
{
    vector<Movie> movies;

    movies.push_back(Movie(1, "Avengers: Endgame",
                           "Action/Sci-Fi",
                           "3h 2m", 8.4, 250));

    movies.push_back(Movie(2, "3 Idiots",
                           "Comedy/Drama",
                           "2h 50m", 8.4, 200));

    movies.push_back(Movie(3, "Dangal",
                           "Sports/Drama",
                           "2h 41m", 8.3, 220));

    movies.push_back(Movie(4, "Inception",
                           "Sci-Fi/Thriller",
                           "2h 28m", 8.8, 280));

    vector<Booking> bookings;

    int choice;
    int bookingCounter = 1001;

    do
    {
        cout << "\n\n==========================================";
        cout << "\n       MOVIE TICKET BOOKING SYSTEM";
        cout << "\n==========================================";
        cout << "\n1. View Movies";
        cout << "\n2. View Movie Details";
        cout << "\n3. Book Movie Ticket";
        cout << "\n4. View Booking Details";
        cout << "\n5. Cancel Ticket";
        cout << "\n6. Exit";
        cout << "\n------------------------------------------";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\n\n============== AVAILABLE MOVIES ==============\n";

            cout << left
                 << setw(5) << "ID"
                 << setw(25) << "Movie Name"
                 << setw(20) << "Genre"
                 << setw(10) << "Rating"
                 << setw(10) << "Price"
                 << endl;

            cout << "-------------------------------------------------------------\n";

            for (int i = 0; i < movies.size(); i++)
            {
                cout << left
                     << setw(5) << movies[i].getId()
                     << setw(25) << movies[i].getName()
                     << setw(20) << "Available"
                     << setw(10) << "View"
                     << "Rs." << movies[i].getPrice()
                     << endl;
            }
        }
        else if (choice == 2)
        {
            int movieId;
            cout << "\nEnter Movie ID: ";
            cin >> movieId;

            bool found = false;

            for (int i = 0; i < movies.size(); i++)
            {
                if (movies[i].getId() == movieId)
                {
                    movies[i].displayMovie();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "\nMovie not found!";
        }
        else if (choice == 3)
        {
            string customerName;
            string mobileNumber;
            int movieId;
            int tickets;

            cout << "\n========== BOOK MOVIE TICKET ==========\n";

            cout << "Enter Customer Name: ";
            cin.ignore();
            getline(cin, customerName);

            cout << "Enter Mobile Number: ";
            cin >> mobileNumber;

            cout << "\nAvailable Movies:\n";

            for (int i = 0; i < movies.size(); i++)
            {
                cout << movies[i].getId()
                     << ". " << movies[i].getName()
                     << " - Rs." << movies[i].getPrice()
                     << endl;
            }

            cout << "\nEnter Movie ID: ";
            cin >> movieId;

            bool found = false;

            for (int i = 0; i < movies.size(); i++)
            {
                if (movies[i].getId() == movieId)
                {
                    found = true;

                    cout << "Enter Number of Tickets: ";
                    cin >> tickets;

                    if (tickets <= 0)
                    {
                        cout << "\nInvalid number of tickets!";
                        break;
                    }

                    int totalAmount = tickets * movies[i].getPrice();

                    cout << "\n========== BILL ==========";
                    cout << "\nCustomer Name : " << customerName;
                    cout << "\nMovie         : " << movies[i].getName();
                    cout << "\nTickets       : " << tickets;
                    cout << "\nPrice/Ticket  : Rs." << movies[i].getPrice();
                    cout << "\n---------------------------";
                    cout << "\nTotal Amount  : Rs." << totalAmount;
                    cout << "\n===========================\n";

                    bookings.push_back(
                        Booking(bookingCounter, customerName,
                                mobileNumber, movies[i].getName(),
                                tickets, totalAmount));

                    cout << "\nTicket booked successfully!";
                    cout << "\nYour Booking ID is: "
                         << bookingCounter << endl;

                    bookingCounter++;
                    break;
                }
            }

            if (!found)
                cout << "\nMovie not found!";
        }
        else if (choice == 4)
        {
            if (bookings.empty())
            {
                cout << "\nNo bookings available.";
            }
            else
            {
                int bookingId;
                cout << "\nEnter Booking ID: ";
                cin >> bookingId;

                bool found = false;

                for (int i = 0; i < bookings.size(); i++)
                {
                    if (bookings[i].getBookingId() == bookingId)
                    {
                        bookings[i].displayBooking();
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "\nBooking not found!";
            }
        }
        else if (choice == 5)
        {
            if (bookings.empty())
            {
                cout << "\nNo bookings available.";
            }
            else
            {
                int bookingId;
                cout << "\nEnter Booking ID to cancel: ";
                cin >> bookingId;

                bool found = false;

                for (int i = 0; i < bookings.size(); i++)
                {
                    if (bookings[i].getBookingId() == bookingId)
                    {
                        bookings.erase(bookings.begin() + i);
                        cout << "\nTicket cancelled successfully!";
                        found = true;
                        break;
                    }
                }

                if (!found)
                    cout << "\nBooking ID not found!";
            }
        }
        else if (choice == 6)
        {
            cout << "\nThank you for using Movie Ticket Booking System!";
            cout << "\nHave a great day!\n";
        }
        else
        {
            cout << "\nInvalid choice! Please try again.";
        }

    } while (choice != 6);

    return 0;
}
