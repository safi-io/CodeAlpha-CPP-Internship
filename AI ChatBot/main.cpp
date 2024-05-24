#include <iostream>  
#include <ctime>  
#include <string>
#include <windows.h>

using namespace std;

// Global variables to store current time
time_t now = time(0); 
tm* ltm = localtime(&now);  

// Array of month names
string monthNames[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

// Function prototypes
void printDate(); // Function to print the current date
void printTime(); // Function to print the current time
void printName(string userName); // Function to print the user's name
void printFact(); // Function to print a random fact
void openWebsite(); // Function to open a website

int main() {  
    // Variables for user input and name tracking
    string question, userName;
    bool nameBool = false;

    // Instructions for the user
    cout << "--Press Space and then Enter to stop Talking with Bot---" << endl;

    // Main loop for interacting with the user
    do {
        cout << "How can I help you ??" << endl;
        cin.ignore();
        getline(cin, question);

        // Check if the user wants to exit
        if(question=="") {
            cout << "Thanks for using me. A Bot Developed by Safi!";
            return 0;
        }

        // Check user input for different commands
        string nameStr = "name";
        string timeStr = "time";
        string dateStr = "date";
        string factStr = "fact";
        string webStr = "website";
    
        size_t nameStrBool = question.find(nameStr);
        size_t timeStrBool = question.find(timeStr);
        size_t dateStrBool = question.find(dateStr);
        size_t factStrBool = question.find(factStr);
        size_t webStrBool = question.find(webStr);

        // Perform corresponding action based on user input
        if(nameStrBool != string::npos) {
            // If user asks about name, either ask for it or print it
            if(nameBool==false) {
                cout << "First, Please tell your name, I will remember it :: " << endl;
                cin >> userName;
                cout << "Nice meeting with you " << userName << endl;
                nameBool = true;
            } else {
                printName(userName);
            }
        } else if(timeStrBool != string::npos) {
            printTime();
        } else if(dateStrBool != string::npos) {
            printDate();
        } else if(factStrBool != string::npos) {
            printFact();
        } else if(webStrBool != string::npos) {
            openWebsite();
        } else {
            cout << "I am unable to understand you, Please Try Again.." << endl;
        }

    }while(true); // Loop indefinitely until user exits
} 

// Function to print the current date
void printDate() {
    int month = 1+ltm->tm_mon;
    string monthName;

    monthName = monthNames[month - 1]; // Subtract 1 because arrays are zero-indexed

    // Print the date
    cout << "Date :: " << ltm->tm_mday << "-" << monthName << "-" << 1900 + ltm->tm_year << endl; 
}

// Function to print the current time
void printTime() {
    int hours = ltm->tm_hour;
    string session;
    // Convert 24-hour time to 12-hour time
    (hours>12) ? session="PM" : session="AM";
    (hours>12) ? hours-=12 : hours; 

    // Print the time
    cout << "Time :: " << hours << ":"  
         << ltm->tm_min <<" " << session << endl;
}

// Function to print the user's name
void printName(string userName) {
    cout << "Your beautiful name is :: " << userName << endl; 
}

// Function to print a random fact
void printFact() {
    string facts[5] = {"Tomatoes are a fruit, not a vegetable.", "On average, the human heart beats 100,000 times a day.", "Your brain is constantly eating itself.", "Ants take rest for around 8 Minutes in 12-hour period.", "AB negative is the rarest blood type."};

    // Generate a random number between 0 to 4
    int randomInteger = rand() % 5;

    // Print the random fact
    cout << facts[randomInteger] << endl;
}

// Function to open a website
void openWebsite() {
    cout << "Which Website do you want me to open for you?" << endl;
    string webName, url;
    cin >> webName;

    // Open corresponding website based on user input
    if(webName=="google") {
        wstring url = L"https://www.google.com";
        ShellExecuteW(0, L"open", url.c_str(), 0, 0, SW_SHOW);
    }else if(webName=="portfolio") {
        wstring url = L"https://safi-thecoder.github.io/Portfolio";
        ShellExecuteW(0, L"open", url.c_str(), 0, 0, SW_SHOW);
    }else {
        cout << "Unable to open" << endl;
    }
}
