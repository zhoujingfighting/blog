#include <iostream>
using namespace std;

int main()
{

	const int seconds = 1;
	const int minutes = 60 * seconds;
	const int hours = 60 * minutes;
	const int days = 24 * hours;
	std::cout << "Enter the number of seconds: ";
	long long actual_time;
	std::cin >> actual_time;
	int actual_day = (int)actual_time / days;
	int actual_hour = (actual_time - actual_day * days) / hours;
	int actual_minute = (actual_time - actual_day*days - actual_hour*hours) / minutes;
	int actual_second = actual_time - actual_day*days - actual_hour*hours - actual_minute * minutes;
	std::cout << actual_time << " seconds = " << actual_day << " days, " << actual_hour << " hours, " << actual_minute << " minutes, " << actual_second << " seconds " << std::endl; 
}
