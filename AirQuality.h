#ifndef AIRQUALITY_H
#define AIRQUALITY_H

#include "Date.h"
#include "Time.h"
#include <iostream>

class AirQuality {
private:
    Date D1;
    Time T1;
    double Temp;
    double AbsoluteHumidity;
    double RelativeHumidity;

public:
    AirQuality(); // Default constructor
    AirQuality(const Date& d, const Time& t, double temp, double aHum, double rHum); // Parameterized constructor

    // Getters
    Date getDate() const;
    Time getTime() const;
    double getTemperature() const;
    double getAbsoluteHumidity() const;
    double getRelativeHumidity() const;

    // Setters
    void setDate(const Date& d);
    void setTime(const Time& t);
    void setTemperature(double temp);
    void setAbsoluteHumidity(double aHum);
    void setRelativeHumidity(double rHum);

//    // Method to output AirQuality data
    void print() const;
};

#endif // AIRQUALITY_H
