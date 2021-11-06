#include <string>
#include <fstream>
#include <vector>
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

// display total sample rides
void count_sample_rides()
{
    FILE *fp;
    int countLines = 1;
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
    int countLines = 1;
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
    int countLines = 1;
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
        char selection2;
        std::cout << "\n select datafile: ";
        std::cout << "\n========";
        std::cout << "\n 1 - Small subset of data with 14 rides";
        std::cout << "\n 2 - Week day vs weekend rides";
        std::cout << "\n 3 - All September 2021 data";
        std::cout << "\n Enter selection: ";

        std::cin >> selection2;
        switch (selection2)
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
    }
}
