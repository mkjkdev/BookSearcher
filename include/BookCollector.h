#ifndef  BOOKCOLLECTOR_H
#define BOOKCOLLECTOR_H

#include "Vector.h"
#include "Utilities.h"
#include "BookData.h"

#include<iostream>

    /**
    * @class BookCollector
    * @brief Provides a static Vector<BookDate> instance to store traversed items
    *
    *
    *
    *
    * @author Mitchel King
    * @version 01
    * @date 17/5/21
    */

class BookCollector
{
    public:
            /**
            * @brief constructor
            *
            */
        BookCollector();

            /**
            * @brief deconstructor
            *
            */
        virtual ~BookCollector();

            /**
            * @brief callback routine adds data to static Vector
            * @param data Date value to collect
            */
        template<class T>
        static void callBackFunc(T & data);

            /***
            * @brief counter getter
            *
            */
        static int getCounter();

            /**
            * @brief array index operator
            * @param index of array element
            */
        BookData & operator[](int index){
            return results[index];
        }
    private:
        static Vector<BookData> results; ///< Vector of Date results, static, one per instance to store values
        static int counter; ///< Track creations
};

template<class T>
void BookCollector::callBackFunc(T & data){
            //add to vector
            results.insert(data);
            counter++;
}
#endif // DATECOLLECTOR_H
