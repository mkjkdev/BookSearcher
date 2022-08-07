#include <iostream>
#include <fstream>
#include <sstream>

#include "Node.h"
#include "Utilities.h"
#include "bst.h"
#include "BookCollector.h"
#include "BookData.h"

    /**
    *
    *
    * @author Mitchel King
    * @version 01
    * @date 17/4/21
    */

int main()
{
    BookCollector collector;
    //get file and input into int tree
    std::string fileName = "BookData.csv";
    std::string outFileName = "sortedData.csv";
    std::fstream inFile;

    if(!openFile(inFile,fileName)){
        std::cout <<"Cannot open file, exiting..";

        return 0;
    }

    //tree declared
    Bst<BookData> bookTree = Bst<BookData>();
    std::string temp;

    //discard first line
    std::getline(inFile, temp);
    BookData tempBD;
    //while getline, get the whole line
    while(std::getline(inFile, temp)){
        if(!std::isspace(inFile.peek())){
            //wrap date obbject andto date object
            std::stringstream ss(temp);
            ss >> tempBD;
            //insert into tree
            bookTree.insert(tempBD);
        }
    }
    //close file
    inFile.close();
    //Collect data sorted by ISBN
    //Use collector routine to collect returned data
    bookTree.inOrder(BookCollector::callBackFunc);

    char userResult;
    //menu loop
    do{
        std::cout << displayMenu();
        std::cin >> userResult;

        BookData tempBook;
        switch(userResult){
            //a case
            case 'a':
                std::cout <<"Please enter an ISBN/EAN to search for\n";
                std::cin >> temp;
                //create book to search
                tempBook.isbn = temp;
                //if no result error, otherwise callback routine
                if(!bookTree.search(tempBook, displayInfo)){
                    std::cout << "Data not found.\n";
                }

            break;
            //b case
            case 'b':
                    //open output file for writing
                    if(!openFile(inFile,outFileName)){
                        std::cout <<"Cannot open output file.\n";
                    }
                    //write from collector
                    for(int i=0;i<collector.getCounter();i++){
                        inFile << collector[i];
                    }
                break;
            //c case
            case 'c':
                std::cout << "Exiting...";
                break;
            //default case
            default:
                std::cout <<"Incorrect option.\n";
                userResult = 'm';
                break;
        }
    }
    while(userResult!='c');

    return 0;
}
