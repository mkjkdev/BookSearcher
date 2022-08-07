#include "BookCollector.h"
#include "Utilities.h"
#include "Vector.h"

//initialization of static members
Vector<BookData> BookCollector::results = Vector<BookData>();
int BookCollector::counter = 0;

//Constructor
BookCollector::BookCollector(){
    counter =0;
    results = Vector<BookData>();
}
//deconstructor
BookCollector::~BookCollector(){
    results.clear();
}
//counter getter
int BookCollector::getCounter(){
    return counter;
}
