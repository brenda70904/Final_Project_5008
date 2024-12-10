#include "AirQualityDataLoader.h"
#include <fstream>
#include <sstream>
#include "Time.h"
#include "Date.h"
#include "CustomVector.cpp"

using namespace std;

/**
 * Parses a date string into a Date object.
 *
 * @param dateStr A string representing a date in the format MM/DD/YYYY.
 * @return A Date object initialized with the day, month, and year extracted from dateStr.
 */
Date parseDate(const string& dateStr) {
    istringstream ss(dateStr);
    int year, month, day;
    char delim;
    ss >> month >> delim >> day >> delim >> year;
    return Date(day, month, year);  // Ensure constructor matches this order
}

/**
 * Parses a time string into a Time object.
 *
 * @param timeStr A string representing time in the format HH:MM:SS.
 * @return A Time object initialized with the hour, minute, and second extracted from timeStr.
 */
Time parseTime(const string& timeStr) {
    istringstream ss(timeStr);
    int hour, minute, second;
    char delim;
    ss >> hour >> delim >> minute >> delim >> second;
    return Time(hour, minute, second);
}

/**
 * Loads AirQuality data from a CSV file into a CustomVector of AirQuality objects.
 * Skips lines with missing or dirty data (specifically humidity values marked as -200).
 *
 * @param filePath The path to the CSV file containing air quality data.
 * @return A CustomVector containing AirQuality objects each initialized from a line in the CSV file.
 */
CustomVector<AirQuality> loadData(const string& filePath) {
    CustomVector<AirQuality> entries;
    ifstream file(filePath);
    string line;

    getline(file, line);  // Skip the header line

    while (getline(file, line)) {
        istringstream iss(line);
        string dateStr, timeStr, temperatureStr, relativeHumidityStr, absoluteHumidityStr;
        getline(iss, dateStr, ',');
        getline(iss, timeStr, ',');
        iss.ignore(numeric_limits<streamsize>::max(), ','); // Skip the CO concentration
        iss.ignore(numeric_limits<streamsize>::max(), ','); // Skip pt08_s1_co
        iss.ignore(numeric_limits<streamsize>::max(), ','); // Skip nmhc_gt
        iss.ignore(numeric_limits<streamsize>::max(), ','); // Skip c6h6Str
        iss.ignore(numeric_limits<streamsize>::max(), ','); // Skip pt08_s2_nmhc
        iss.ignore(numeric_limits<streamsize>::max(), ','); // Skip nox_gt
        iss.ignore(numeric_limits<streamsize>::max(), ','); // Skip pt08_s3_nox
        iss.ignore(numeric_limits<streamsize>::max(), ','); // Skip no2_gt
        iss.ignore(numeric_limits<streamsize>::max(), ','); // Skip pt08_s4_no2
        iss.ignore(numeric_limits<streamsize>::max(), ','); // Skip pt08_s5_o3
        getline(iss, temperatureStr, ',');
        getline(iss, relativeHumidityStr, ',');
        getline(iss, absoluteHumidityStr, ',');

        double temperature = stod(temperatureStr);
        double relativeHumidity = stod(relativeHumidityStr);
        double absoluteHumidity = stod(absoluteHumidityStr);

        if (relativeHumidity == -200 || absoluteHumidity == -200) continue;  // Skip dirty data

        Date date = parseDate(dateStr);
        Time time = parseTime(timeStr);
        entries.push_back(AirQuality(date, time, temperature, absoluteHumidity, relativeHumidity));
    }
    return entries;
}

