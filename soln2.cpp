#include <string>
#include <fstream>
#include <algorithm> // use of vector algorithms
#include <cmath>
#include <vector>
#include <cassert>   // For the assert statement
#include <cctype>    // access to tolower() or toupper() function
#include <utility>   // std::pair
#include <stdexcept> // std::runtime_error
#include <sstream>   // std::stringstream
#include <iostream>  // For Input and Output

/*CSV is a simple file format used to store tabular data such as a 
spreadsheet or a database. CSV stands for Comma Separated Values. 
The data fields in a CSV file are separated/delimited by a comma (‘, ‘) 
and the individual rows are separated by a newline (‘\n’). CSV File management in C++ 
is similar to text-type file management, except for a few modifications.*/

using namespace std;

// Utility functions getting distant between two map points
// Attribution: https://www.geeksforgeeks.org/program-distance-two-points-earth/
// converting degrees to radians
long double toRadians(const long double degree)
{
    // cmath library in C++
    // defines the constant
    // M_PI as the value of
    // pi accurate to 1e-30
    long double one_deg = (3.14159265358979323846) / 180;
    return (one_deg * degree);
}

long double distance(long double lat1, long double long1,
                     long double lat2, long double long2)
{
    // Convert the latitudes
    // and longitudes
    // from degree to radians.
    lat1 = toRadians(lat1);
    long1 = toRadians(long1);
    lat2 = toRadians(lat2);
    long2 = toRadians(long2);

    // Haversine Formula
    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;

    long double ans = pow(sin(dlat / 2), 2) +
                      cos(lat1) * cos(lat2) *
                          pow(sin(dlong / 2), 2);

    ans = 2 * asin(sqrt(ans));

    // Radius of Earth in
    // Kilometers, R = 6371
    // Use R = 3956 for miles
    long double R = 3956;

    // Calculate the result
    ans = ans * R;

    return ans;
}

// display total sample rides
void count_sample_rides()
{
    FILE *fp;
    int countLines = 0;
    int i;

    fp = fopen("divvyridesampledata.csv", "r");
    if (fp == NULL)
    {
        cout << "We can't open the file.";
        fclose(fp);
    }
    else
    {
        while ((i = fgetc(fp)) != EOF)
        {
            if (i == '\n')
                countLines++;
        }
        cout << "Total # of trips found in datafile: " << countLines << std::endl;
    }
}

// display total weekday vs weekend rides
void count_weekday_vs_weekend_rides()
{
    FILE *fp;
    int countLines = 0;
    int i;

    fp = fopen("weekdayweekend.csv", "r");
    if (fp == NULL)
    {
        cout << "We can't open the file.";
        fclose(fp);
    }
    else
    {
        while ((i = fgetc(fp)) != EOF)
        {
            if (i == '\n')
                countLines++;
        }
        cout << "Total # of trips found in datafile: " << countLines << std::endl;
    }
}

// display all divvy rides
void display_all_rides()
{
    FILE *fp;
    int countLines = 0;
    int i;

    fp = fopen("all_divvy_rides_september.csv", "r");
    if (fp == NULL)
    {
        cout << "We can't open the file.";
        fclose(fp);
    }
    else
    {
        while ((i = fgetc(fp)) != EOF)
        {
            if (i == '\n')
                countLines++;
        }
        cout << "Total # of trips found in datafile: " << countLines << std::endl;
    }
}

// display distance between two points
// sample rides file
void distance_sample_rides()
{
    int rows = 0;
    string rides;
    ifstream ip("divvyridesampledata.csv");

    if (!ip.is_open())
    {
        cout << "Error opening file" << endl;
        exit(1);
    }
    // assign columns to variables
    string ride_id;
    string start_station_name;
    string end_station_name;
    string start_station_lat;
    string start_station_long;
    string end_station_lat;
    string end_station_long;

    while (ip.good())
    {
        getline(ip, rides, '\n');
        rows++;
        getline(ip, ride_id, ',');

        // loop through file stream and get ride data
        while (getline(ip, start_station_name, ','))
        {
            getline(ip, end_station_name, ',');
            getline(ip, start_station_lat, ',');
            getline(ip, start_station_long, ',');
            getline(ip, end_station_lat, ',');
            getline(ip, end_station_long, ',');
            cout << "Distance between " << start_station_name << " and " << end_station_name << " is " << distance(stod(start_station_lat), stod(start_station_long), stod(end_station_lat), stod(end_station_long)) << " miles" << endl;
        }
    }

    ip.close();
}

int main(int argc, char *argv[])
{
    char selection;

    std::cout << "\n select menu";
    std::cout << "\n========";
    std::cout << "\n 1 - Select datafile, display rides totals and clean data";
    std::cout << "\n 2 - Display overall trip information";
    std::cout << "\n 3 - Display percentage of members vs. casual riders";
    std::cout << "\n 4 - Display weekday vs weekend usage";
    std::cout << "\n Enter selection: ";

    // read the input
    std::cin >> selection;
    switch (selection)
    {
    case '1':
        // menu selection 2
        char menu2;
        std::cout << "\n select datafile: ";
        std::cout << "\n========";
        std::cout << "\n 1 - Small subset of data with 14 rides";
        std::cout << "\n 2 - Week day vs weekend rides";
        std::cout << "\n 3 - All September 2021 data";
        std::cout << "\n Enter selection: ";

        std::cin >> menu2;
        switch (menu2)
        {
        case '1':
            // Read divvyridesampledata.csv
            count_sample_rides();
            return 0;
            break;

        case '2':
            // Read weekdayweekend.csv
            count_weekday_vs_weekend_rides();
            return 0;
            break;

        case '3':
            // Read all_divvy_rides_september.csv
            display_all_rides();
            return 0;
            break;
        }
        return 0;
        break;

    case '2':
        // menu selection 2
        char menu3;
        std::cout << "\n select datafile: ";
        std::cout << "\n========";
        std::cout << "\n 1 - Small subset of data with 14 rides";
        std::cout << "\n 2 - Week day vs weekend rides";
        std::cout << "\n 3 - All September 2021 data";
        std::cout << "\n Enter selection: ";

        std::cin >> menu3;
        switch (menu3)
        {
        case '1':
            // Read divvyridesampledata.csv
            distance_sample_rides();
            return 0;
            break;

            // case '2':
            //     // Read weekdayweekend.csv
            //     count_weekday_vs_weekend_rides();
            //     return 0;
            //     break;

            // case '3':
            //     // Read all_divvy_rides_september.csv
            //     display_all_rides();
            //     return 0;
            //     break;
        }
        return 0;
        break;
    }
}
