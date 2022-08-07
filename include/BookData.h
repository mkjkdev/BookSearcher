#ifndef BOOKDATA_H
#define BOOKDATA_H

    /**
    * @struct BookData
    * @brief Represents the Data for a Book
    * Holds data according to BookData.csv
    *
    *
    *
    * @author Mitchel King
    * @version 01
    * @date 17/5/21
    */

typedef struct BookData{
    int year; ///< year
    std::string isbn; ///< ISBN number
    int edition; ///< edition
    std::string bindFormat; ///< Binding Format
    float deweyClass; ///< Dewey Class
    float price; ///< price

    BookData(): year(1900),isbn(""),edition(0),bindFormat(""),deweyClass(0),price(0){} ///< default constructor
} BookData;

#endif // BOOKDATA_H
