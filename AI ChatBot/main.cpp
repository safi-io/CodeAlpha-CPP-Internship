#include <iostream>  
#include <ctime>  

using namespace std;

time_t now = time(0); 
tm* ltm = localtime(&now);  

void printDate(); // All Done
void printTime(); // All Done
void printName();

int main() {  
    // printTime();
    // printDate();
} 

void printDate() {

    int month = 1+ltm->tm_mon;
    string monthName;

    switch (month) {
        case 1:
            monthName = "January";
            break;
        case 2:
            monthName = "February";
            break;
        case 3:
            monthName = "March";
            break;
        case 4:
            monthName = "April";
            break;
        case 5:
            monthName = "May";
            break;
        case 6:
            monthName = "June";
            break;
        case 7:
            monthName = "July";
            break;
        case 8:
            monthName = "August";
            break;
        case 9:
            monthName = "September";
            break;
        case 10:
            monthName = "October";
            break;
        case 11:
            monthName = "November";
            break;
        case 12:
            monthName = "December";
            break;
        default:
            monthName = "Invalid month";
            break;
    }

    cout << "Date :: " << ltm->tm_mday << "-"
         << monthName << "-"
         << 1900 + ltm->tm_year << endl; 
  
}
void printTime() {
    int hours = ltm->tm_hour;
    string session;
    (hours>12) ? session="PM" : session="AM";
    (hours>12) ? hours-=12 : hours; 

    cout << "Time :: " << hours << ":"  
         << ltm->tm_min <<" " << session << endl;
}
void printName() {

}