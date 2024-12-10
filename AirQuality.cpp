#include "AirQuality.h"
using namespace std;

/**
 * Default constructor for AirQuality.
 * Initializes temperature, absolute humidity, and relative humidity to zero.
 */
AirQuality::AirQuality() : Temp(0.0), AbsoluteHumidity(0.0), RelativeHumidity(0.0) {}

/**
 * Parameterized constructor for AirQuality.
 *
 * @param d A Date object representing the date of the air quality measurement.
 * @param t A Time object representing the time of the air quality measurement.
 * @param temp A double value representing the temperature in degrees Celsius.
 * @param aHum A double value representing the absolute humidity.
 * @param rHum A double value representing the relative humidity.
 */
AirQuality::AirQuality(const Date& d, const Time& t, double temp, double aHum, double rHum)
        : D1(d), T1(t), Temp(temp), AbsoluteHumidity(aHum), RelativeHumidity(rHum) {}

/**
 * Getters and Setters
 * @return values for Air quality datas.
 */
Date AirQuality::getDate() const {
    return D1;
}

Time AirQuality::getTime() const {
    return T1;
}

double AirQuality::getTemperature() const {
    return Temp;
}

double AirQuality::getAbsoluteHumidity() const {
    return AbsoluteHumidity;
}

double AirQuality::getRelativeHumidity() const {
    return RelativeHumidity;
}

void AirQuality::setDate(const Date& d) {
    D1 = d;
}

void AirQuality::setTime(const Time& t) {
    T1 = t;
}

void AirQuality::setTemperature(double temp) {
    Temp = temp;
}

void AirQuality::setAbsoluteHumidity(double aHum) {
    AbsoluteHumidity = aHum;
}

void AirQuality::setRelativeHumidity(double rHum) {
    RelativeHumidity = rHum;
}

/**
 * Prints the details of the AirQuality object in a formatted manner.
 */
void AirQuality::print() const {
    D1.printDate();
    T1.printTime();
    cout << "Temperature: " << Temp << " degrees Celsius\n"
         << "Absolute Humidity: " << AbsoluteHumidity << "\n"
         << "Relative Humidity: " << RelativeHumidity << "%" << endl;
}
