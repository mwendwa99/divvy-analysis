#include <iostream>
#include <fstream> //read/write from/to file
#include <string>

using namespace std;

int main()
{
    int rows = 0;
    ifstream ip("all_divvy_rides_september.csv");

    if (!ip.is_open())
    {
        cout << "Error opening file" << endl;
        return 1;
    }
    // display rides total
    std::string rides;

    // string ride_id;
    // string rideable_type;
    // string start_date;
    // string start_time;
    // string start_station_id;
    // string start_station_name;
    // string start_station_lat;
    // string start_station_long;
    // string end_date;
    // string end_time;
    // string end_station_id;
    // string end_station_name;
    // string end_station_lat;
    // string end_station_long;
    // string bike_id;
    // string subscription_type;

    while (ip.good())
    {
        getline(ip, rides, '\n');
        rows++;
        // getline(ip, ride_id, ',');
        // getline(ip, rideable_type, ',');
        // getline(ip, start_station_long, ',');
        // getline(ip, end_date, '\n');

        // total rides
        std::cout << "Total rides: " << rows << std::endl;
        // std::cout << "ride_id: " << ride_id << std::endl;
        // std::cout << "rideable_type: " << rideable_type << std::endl;
        // std::cout << "start_date: " << start_date << std::endl;
        // std::cout << "start_time: " << start_time << std::endl;
        // std::cout << "start_station_id: " << start_station_id << std::endl;
        // std::cout << "start_station_name: " << start_station_name << std::endl;
        // std::cout << "start_station_lat: " << start_station_lat << std::endl;
        // std::cout << "start_station_long: " << start_station_long << std::endl;
        // std::cout << "-----------------------------------------------------";
    }

    ip.close();
}