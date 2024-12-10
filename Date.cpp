#include "Date.h"
#include <string>
#include <iostream>

using namespace std;

/**
 * Default constructor that initializes the date to January 1, 2000.
 */
Date::Date(){
    day=1;
    month=1;
    year=2000;
}

/**
* Parameterized constructor that initializes the date with specific day, month, and year.
*
* @param dd The day component of the date.
* @param mm The month component of the date.
* @param yy The year component of the date.
*/
Date::Date(int dd, int mm, int yy){
    day=dd;
    month=mm;
    year=yy;
}

/**
 * Getters and setters
 * @return the component for the date.
 */
int Date::GetDay() const{
    return day;
}
void Date::SetDay(int dd){
    day=dd;
}
int Date::GetMonth() const{
    return month;
}
void Date::SetMonth(int mm){
    month=mm;
}
int Date::GetYear() const{
    return year;
}
void Date::SetYear(int yy){
    year=yy;
}
void Date::SetDate(int dd, int mm, int yy)
{
    day=dd;
    month=mm;
    year=yy;
}

/**
 * Prints the date.
 */
void Date::printDate() const {
    cout<<"Here  Date:  month: " << month <<" day: "<< day <<" "<<year<<'\n';
}

/**
 * Overloads the input stream operator for Date objects.
 *
 * @param input The input stream.
 * @param D The Date object to input.
 * @return The input stream.
 */
istream & operator >>( istream & input, Date & D )
{
    string stringdd, stringmm, stringyy;
    int dd,mm, yy;

    getline(input, stringdd, '/');
    getline(input, stringmm,'/');
    getline(input, stringyy,' ');

    dd=stoi(stringdd);
    mm=stoi(stringmm);
    yy=stoi(stringyy);

    D.SetDate(dd, mm, yy);

    return input;
}

/**
 * Overloads the output stream operator for Date objects.
 *
 * @param os The output stream.
 * @param D The Date object to output.
 * @return The output stream.
 */
ostream & operator <<( ostream & os, const Date & D )
{
    os << "  Date:  " << D.GetDay()<< "/" << D.GetMonth() << "/" <<D.GetYear()<<'\n';
    return os;
}
