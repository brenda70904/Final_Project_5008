#include <iostream>
#include <string>
#include <limits>
#include "AirQuality.h"
#include "AirQualityDataLoader.h"
#include "CustomVector.cpp"
#include <iomanip>

using namespace std;

// Function declarations
void displayMenu();
void calculateAverageTemperature(const CustomVector<AirQuality>& data);
void calculateAverageHumidity(const CustomVector<AirQuality>& data, bool isRelative);
void showDataForDateAndTime(const CustomVector<AirQuality>& data);
void showHighestTemperature(const CustomVector<AirQuality>& data);
void showHighestHumidity(const CustomVector<AirQuality>& data, bool isRelative);
void showTemperaturesHigherThanAverage(const CustomVector<AirQuality>& data);
void showHumidityHigherThanAverage(const CustomVector<AirQuality>& data, bool isRelative);

/**
 * Main function that initializes the program.
 * Loads air quality data and handles user interface for data analysis.
 */
int main() {
//    string filePath = "/Users/bowanglin/Desktop/finalProject/Final_Project/AirQualityUCI.csv";
    string filePath = "/Users/bowanglin/Desktop/cs5008/Final_Project/AirQualityUCI.csv";
    CustomVector<AirQuality> data = loadData(filePath);

    int choice;
    bool running = true;

    while (running) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // clear input buffer to restore cin to a usable state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore last input
            cout << "You can only enter numbers.\n";
            continue;
        }

        switch(choice) {
                    case 1:
                        calculateAverageTemperature(data);
                        break;
                    case 2:
                        calculateAverageHumidity(data, true);
                        break;
                    case 3:
                        calculateAverageHumidity(data, false);
                        break;
                    case 4:
                        showDataForDateAndTime(data);
                        break;
                    case 5:
                        showHighestTemperature(data);
                        break;
                    case 6:
                        showHighestHumidity(data, true);
                        break;
                    case 7:
                        showHighestHumidity(data, false);
                        break;
                    case 8:
                        showTemperaturesHigherThanAverage(data);
                        break;
                    case 9:
                        showHumidityHigherThanAverage(data, true);
                        break;
                    case 10:
                        showHumidityHigherThanAverage(data, false);
                        break;
                    case 0:
                        running = false;
                        cout << "Program exited successfully." << endl;
                        break;
                    default:
                        cout << "Invalid choice. Please enter a number between 1 and 10, or 0 to exit.\n";
                        break;
                }
            }

            return 0;
}

/**
 * Displays the main menu with options for air quality data analysis.
 */
void displayMenu() {
    cout << "Air Quality Data Menu options:" << endl;
    cout << "1) Display average temperature for a month" << endl;
    cout << "2) Display average relative humidity for a month" << endl;
    cout << "3) Display average absolute humidity for a month" << endl;
    cout << "4) Display temperature and relative humidity at a specific date and time" << endl;
    cout << "5) Display highest temperature for a month" << endl;
    cout << "6) Display highest relative humidity for a month" << endl;
    cout << "7) Display highest absolute humidity for a month" << endl;
    cout << "8) Display temperature higher than average for a month" << endl;
    cout << "9) Display relative humidity higher than average for a month" << endl;
    cout << "10) Display absolute humidity higher than average for a month" << endl;
    cout << "0) Exit" << endl;
}

/**
 * Calculates and displays the average temperature for specified years and a specified month.
 * @param data CustomVector of AirQuality records.
 */
void calculateAverageTemperature(const CustomVector<AirQuality>& data) {
    int month, year;
    cout << "Enter the month (1-12): ";
    cin >> month;

    if (month < 1 || month > 12) {
        cout << "Invalid month. Please try again." << endl;
        return;
    }

    cout << "Enter the year (2004 or 2005): ";
    cin >> year;

    if (year != 2004 && year != 2005) {
        cout << "Invalid year. Please enter 2004 or 2005." << endl;
        return;
    }

    double total = 0.0;
    int count = 0;
    for (const auto& entry : data) {
        if (entry.getDate().GetMonth() == month) {
            if (entry.getDate().GetYear() == year) {
                total += entry.getTemperature();
                count += 1;
            }
        }
    }
    double average = total / count;
    if (count > 0) {
        cout << "Average Temperature for month " << month << " in " << year << " is " << average << " degrees." << endl;
    } else {
        cout << "No data available for month " << month << " in " << year << endl;
    }

}
/**
 * Calculates and displays the average humidity (relative or absolute) for a specified month.
 * @param data CustomVector of AirQuality records.
 * @param isRelative Boolean flag to indicate whether to calculate relative humidity (true) or absolute humidity (false).
 */
void calculateAverageHumidity(const CustomVector<AirQuality>& data, bool isRelative) {
    int month, year;
    cout << "Enter the month (1-12): ";
    cin >> month;

    if (month < 1 || month > 12) {
        cout << "Invalid month. Please try again." << endl;
        return;
    }

    cout << "Enter the year (2004 or 2005): ";
    cin >> year;

    if (year != 2004 && year != 2005) {
        cout << "Invalid year. Please enter 2004 or 2005." << endl;
        return;
    }

    double totalHumidity = 0;
    int count = 0;

    for (const auto& entry : data) {
        if (entry.getDate().GetMonth() == month) {
            if (entry.getDate().GetYear() == year) {
                totalHumidity += isRelative ? entry.getRelativeHumidity() : entry.getAbsoluteHumidity();
                count++;
            }
        }
    }

    if (count > 0) {
        cout << "Average " << (isRelative ? "Relative Humidity" : "Absolute Humidity") << " for month " << month << " is " << (totalHumidity / count) << endl;
    } else {
        cout << "No data available for month " << month << "." << endl;
    }
}

/**
 * Displays air quality data for a specific date and time input by the user.
 * @param data CustomVector of AirQuality records.
 */
void showDataForDateAndTime(const CustomVector<AirQuality>& data) {
    int day, month, year, hour, minute, second;
    cout << "Enter date and time (DD MM YYYY HH MM SS): ";
    cin >> month >> day >> year >> hour >> minute >> second;
    bool found = false;
    for (const auto& entry : data) {
        if (entry.getDate().GetDay() == day && entry.getDate().GetMonth() == month && entry.getDate().GetYear() == year &&
            entry.getTime().GetHour() == hour && entry.getTime().GetMin() == minute && entry.getTime().GetSec() == second) {
            cout << "At date: " << entry.getDate().GetMonth() << "/" << entry.getDate().GetDay() << "/" << entry.getDate().GetYear()  << " "
            << setfill('0')<< setw(2) << entry.getTime().GetHour() << ":" << setw(2)<< entry.getTime().GetMin() << ":" << setw(2) << entry.getTime().GetSec()<< ", Temperature: " << entry.getTemperature()
                 << "°C, Relative Humidity: " << entry.getRelativeHumidity() << "%, Absolute Humidity: " << entry.getAbsoluteHumidity() << "%" << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No data available for the specified date and time." << endl;
    }
}

/**
 * Finds and displays the highest temperature recorded in a specified month.
 * @param data CustomVector of AirQuality records.
 */
void showHighestTemperature(const CustomVector<AirQuality>& data) {
    int month, year;
    cout << "Enter the month (1-12): ";
    cin >> month;

    if (month < 1 || month > 12) {
        cout << "Invalid month. Please try again." << endl;
        return;
    }

    cout << "Enter the year (2004 or 2005): ";
    cin >> year;

    if (year != 2004 && year != 2005) {
        cout << "Invalid year. Please enter 2004 or 2005." << endl;
        return;
    }

    double maxTemp = numeric_limits<double>::lowest();
    for (const auto& entry : data) {
        if (entry.getDate().GetMonth() == month) {
            if (entry.getDate().GetYear() == year) {
                if (entry.getTemperature() > maxTemp) {
                    maxTemp = entry.getTemperature();
                }
            }
        }
    }

    if (maxTemp > numeric_limits<double>::lowest()) {
        cout << "Highest Temperature for month " << month << " is " << maxTemp << "°C" << endl;
    } else {
        cout << "No temperature data available for month " << month << "." << endl;
    }
}

/**
 * Finds and displays the highest humidity (relative or absolute) recorded in a specified month.
 * @param data CustomVector of AirQuality records.
 * @param isRelative Boolean flag to indicate whether to display relative humidity (true) or absolute humidity (false).
 */
void showHighestHumidity(const CustomVector<AirQuality>& data, bool isRelative) {
    int month, year;
    cout << "Enter the month (1-12): ";
    cin >> month;

    if (month < 1 || month > 12) {
        cout << "Invalid month. Please try again." << endl;
        return;
    }

    cout << "Enter the year (2004 or 2005): ";
    cin >> year;

    if (year != 2004 && year != 2005) {
        cout << "Invalid year. Please enter 2004 or 2005." << endl;
        return;
    }

    double maxHumidity = numeric_limits<double>::lowest();
    for (const auto& entry : data) {
        double humidity = isRelative ? entry.getRelativeHumidity() : entry.getAbsoluteHumidity();
        if (entry.getDate().GetYear() == year && entry.getDate().GetMonth() == month && humidity > maxHumidity) {
            maxHumidity = humidity;
        }
    }

    if (maxHumidity > numeric_limits<double>::lowest()) {
        cout << "Highest " << (isRelative ? "Relative Humidity" : "Absolute Humidity")
             << " for month " << month << " is " << maxHumidity << "%" << endl;
    } else {
        cout << "No humidity data available for month " << month << "." << endl;
    }
}

/**
 * Displays all temperatures for a specified month that are higher than the month's average temperature.
 * @param data CustomVector of AirQuality records.
 */
void showTemperaturesHigherThanAverage(const CustomVector<AirQuality>& data) {
    int month, year;
    cout << "Enter the month (1-12): ";
    cin >> month;

    if (month < 1 || month > 12) {
        cout << "Invalid month. Please try again." << endl;
        return;
    }

    cout << "Enter the year (2004 or 2005): ";
    cin >> year;

    if (year != 2004 && year != 2005) {
        cout << "Invalid year. Please enter 2004 or 2005." << endl;
        return;
    }

    double totalTemp = 0;
    int count = 0;

    for (const auto& entry : data) {
        if (entry.getDate().GetMonth() == month) {
            if (entry.getDate().GetYear() == year) {
                totalTemp += entry.getTemperature();
                count++;
            }
        }
    }

    if (count == 0) {
        cout << "No temperature data available for month " << month << "." << endl;
        return;
    }

    double averageTemp = totalTemp / count;
    cout << "Temperatures higher than the average (" << averageTemp << "°C) for month " << month << ":" << endl;

    for (const auto& entry : data) {
        if (entry.getDate().GetYear() == year && entry.getDate().GetMonth() == month && entry.getTemperature() > averageTemp) {
            cout << entry.getDate() << " Time: " <<setfill('0')<< setw(2) << entry.getTime().GetHour() << ":" << setw(2)<< entry.getTime().GetMin() << ":" << setw(2) << entry.getTime().GetSec() << " Temperature: " << entry.getTemperature() << "°C" << endl;
        }
    }
}

/**
 * Displays all humidity values for a specified month that are higher than the month's average humidity.
 * @param data CustomVector of AirQuality records.
 * @param isRelative Boolean flag to indicate whether to display relative humidity (true) or absolute humidity (false).
 */
void showHumidityHigherThanAverage(const CustomVector<AirQuality>& data, bool isRelative) {
    int month, year;
    cout << "Enter the month (1-12): ";
    cin >> month;

    if (month < 1 || month > 12) {
        cout << "Invalid month. Please try again." << endl;
        return;
    }

    cout << "Enter the year (2004 or 2005): ";
    cin >> year;

    if (year != 2004 && year != 2005) {
        cout << "Invalid year. Please enter 2004 or 2005." << endl;
        return;
    }

    double totalHumidity = 0;
    int count = 0;

    for (const auto& entry : data) {
        double humidity = isRelative ? entry.getRelativeHumidity() : entry.getAbsoluteHumidity();
        if (entry.getDate().GetMonth() == month) {
            if (entry.getDate().GetYear() == year) {
                totalHumidity += humidity;
                count++;
            }
        }
    }

    if (count == 0) {
        cout << "No humidity data available for month " << month << "." << endl;
        return;
    }

    double averageHumidity = totalHumidity / count;
    cout << "Humidity values higher than the average (" << averageHumidity << "%) for month " << month << ":" << endl;

    for (const auto& entry : data) {
        double humidity = isRelative ? entry.getRelativeHumidity() : entry.getAbsoluteHumidity();
        if (entry.getDate().GetYear() == year && entry.getDate().GetMonth() == month && humidity > averageHumidity) {
            cout << entry.getDate() << " Time: " << setfill('0')<< setw(2) << entry.getTime().GetHour() << ":" << setw(2)<< entry.getTime().GetMin() << ":" << setw(2) << entry.getTime().GetSec()<< " Humidity: " << humidity << "%" << endl;
        }
    }
}


