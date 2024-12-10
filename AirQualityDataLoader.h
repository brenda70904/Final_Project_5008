#ifndef AIRQUALITYDATALOADER_H
#define AIRQUALITYDATALOADER_H

#include <vector>
#include <string>
#include "AirQuality.h"
#include "CustomVector.cpp"

using namespace std;

CustomVector<AirQuality> loadData(const string& filePath);
Date parseDate(const string& dateStr);
Time parseTime(const string& timeStr);

#endif // AIRQUALITYDATALOADER_H

