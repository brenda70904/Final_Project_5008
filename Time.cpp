#include "Time.h"
using namespace std;

/**
 * Default constructor that initializes time to 00:00:00.
 */
Time::Time() : hour(0), min(0), sec(0) {}

/**
* Constructor that initializes time with hour, minute, and second.
*
* @param hh The hour component of the time.
* @param mm The minute component of the time.
* @param ss The second component of the time.
*/
Time::Time(int hh, int mm, int ss) : hour(hh), min(mm), sec(ss) {}

Time::~Time() {}

/**
 * Getter and setters for the time.
 *
 * @return component of the time.
 */
int Time::GetHour() const {
    return hour;
}

int Time::GetMin() const {
    return min;
}

int Time::GetSec() const {
    return sec;
}

void Time::SetHour(int hh) {
    hour = hh;
}

void Time::SetMin(int mm) {
    min = mm;
}

void Time::SetSec(int ss) {
    sec = ss;
}

void Time::SetTime(int hh, int mm, int ss) {
    hour = hh;
    min = mm;
    sec = ss;
}

/**
 * Prints the time.
 */
void Time::printTime() const {
    cout << "Time: " << hour << ":" << min << ":" << sec << endl;
}

/**
 * Overloads the input stream operator for Time objects.
 *
 * @param input The input stream.
 * @param T The Time object to input.
 * @return The input stream.
 */
istream &operator>>(istream &input, Time &T) {
    input >> T.hour >> T.min >> T.sec;
    return input;
}

/**
 * Overloads the output stream operator for Time objects.
 *
 * @param os The output stream.
 * @param T The Time object to output.
 * @return The output stream.
 */
ostream &operator<<(ostream &os, const Time &T) {
    os << T.hour << ":" << T.min << ":" << T.sec;
    return os;
}

