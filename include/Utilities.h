#ifndef UTILITIES_H
#define UTILITIES_H

#include<istream>
#include "Node.h"
#include "BookData.h"

    /**
    * @brief Utility routines
    * Non class member overloads
    *
    *
    *
    *
    * @author Mitchel King
    * @version 01
    * @date 17/5/2021
    */

    /**
    * @brief open file
    * @return boolean if file opening succesful
    * @param file file object
    * @param fileName file name to open
    */
bool openFile(std::fstream & file, std::string & fileName);

    /**
    * @brief callback function to display BookData from Bst
    * @param item const BookData reference
    */
void displayInfo(const BookData & item);

   /**
    * @brief WeatherLog operator overloads
    * @param inStream input stream
    * @param wt WeatherLog
    *
    * @pre inStream must have contents
    * @post values extracted and assigned to wt
    */
std::istream & operator >>(std::istream & inStream, BookData & bd);
    /**
    * @param os output stream
    * @param wt WeatherLog
    * @pre wt must exist with member values
    * @post wt details output to os
    */
std::ostream & operator <<(std::ostream & os, const BookData & bd);

    /**
    * @brief BookData greater than operator
    * @param callData calling BookData
    * @param otherData BookData to compare
    * @return bool
    */
bool operator >(const BookData & callData, const BookData & otherData);

    /**
    * @brief BookData less than operator
    * @param callData calling BookData
    * @param otherData BookData to compare
    * @return bool
    */
bool operator <(const BookData & callData, const BookData & otherData);

    /**
    * @brief BookData comparison operator overload
    * @param callData calling BookData
    * @param otherData BookData to compare
    * @return bool
    */
bool operator == (const BookData & callData, const BookData & otherData);

    /**
    * @brief displays menu
    * @return menu string
    */
const std::string displayMenu();

    /**
    * @brief takes non numbers out of string
    * @param stringVal string to check
    * @param resultVal string to build
    */
void numberString(const std::string & stringVal, std::string & resultVal);
#endif // UTILITIES_H
