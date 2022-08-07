#include "Utilities.h"
#include "Node.h"
#include "BookData.h"

#include<fstream>
#include<iostream>
#include <sstream>

//seperate function to read lines?
bool openFile(std::fstream & file, std::string & fileName){
    //open
    file.open(fileName);
    //return false if can't be opened
    if(!file){
        file.close();
        return false;
    }
    else{
        return true;
    }
}

//BookData stream insertion operator
std::istream & operator >>(std::istream & input, BookData & bd){
    //string stream
    std::stringstream ss;
    //temp BookData
    std::string tempString;
    //get first value
    std::getline(input, tempString, ',');
    //wrap and send to primitive
    ss = std::stringstream(tempString);
    ss >> bd.year;

    //get second value
    std::getline(input, tempString,',');
    ss = std::stringstream(tempString);
    ss >> bd.isbn;

    //third value
    std::getline(input,tempString,',');
    ss = std::stringstream(tempString);
    if(tempString == ""){
        bd.edition = 0;
    }
    else{
        ss >> bd.edition;
    }

    //fourth value
    std::getline(input,tempString,',');
    ss = std::stringstream(tempString);
    //input to string stops at space
    //ss >> bd.bindFormat;
    bd.bindFormat = tempString;

    //fifth value
    std::getline(input, tempString, ',');
    ss = std::stringstream(tempString);
    ss >> bd.deweyClass;

    //sixth value
    std::getline(input, tempString,',');
    ss = std::stringstream(tempString);
    ss >> bd.price;

    return input;
}

//BookData stream extraction operator
std::ostream & operator<<(std::ostream & os, const BookData & bd){
    //output details of log as csv
    os << bd.year << ',';
    os << bd.isbn << ',';
    os << bd.edition << ',';
    os << bd.bindFormat << ',';
    os << bd.deweyClass << ',';
    os << bd.price << '\n';

    return os;
}

//Book data greater than opeartor
bool operator>(const BookData & callData, const BookData & otherData){
    //get number strings
    std::string tempStringOne;
    std::string tempStringTwo;
    numberString(callData.isbn, tempStringOne);
    numberString(otherData.isbn, tempStringTwo);
    //compare std::stoul
    if(std::stoul(tempStringOne) > std::stoul(tempStringTwo)){
        return true;
    }
    else{
        return false;
    }
}

//BookData less than operator
bool operator < (const BookData & callData, const BookData & otherData){
    //get number strings
    std::string tempStringOne;
    std::string tempStringTwo;
    numberString(callData.isbn, tempStringOne);
    numberString(otherData.isbn, tempStringTwo);
    //compare std::stoul
    if(std::stoul(tempStringOne) < std::stoul(tempStringTwo)){
        return true;
    }
    else{
        return false;
    }
}

//BookData comparison operator
bool operator == (const BookData & callData, const BookData & otherData){
    std::string tempOne;
    std::string tempTwo;
    //Get number strings
    numberString(callData.isbn, tempOne);
    numberString(otherData.isbn,tempTwo);
    //compare std::stoul
    if(std::stoul(tempOne) == std::stoul(tempTwo)){
        return true;
    }
    else{
        return false;
    }
}

//Call back function to display data at Bst
void displayInfo(const BookData & item) {
    //Calls T's output operator,
    std::cout << "ISBN/EAN: " << item.isbn << "\nBinding Format: "<< item.bindFormat << "\nPrice: $" << item.price << std::endl;
    //std::cout << item;
}

//menu routine
const std::string displayMenu(){
    std::string value = "a. Enter a ISBN/EAN to search\nb. Save to file data sorted by ISBN/EAN\nc. Quit\n";
    return value;
}

//build number string
void numberString(const std::string & stringVal, std::string & resultVal){
    //check each car for digits
    for(unsigned i=0;i<stringVal.size();i++){
        if(std::isdigit(stringVal[i])){
            resultVal += stringVal[i];
        }
    }
}
