//
// Created by Adrian Rivera on 10/27/18.
//

#ifndef INC_235_QS_QS_H
#define INC_235_QS_QS_H

#include "QSInterface.h"
#include <sstream>

class QS : public QSInterface {
protected:
    int* array;
    int counter;
    int maxCapacity;
    int middle;
public:
    QS();
    void sortAll();
    int medianOfThree(int left, int right);
    int partition(int left, int right, int pivotIndex);
    string getArray() const;
    int getSize() const;
    bool addToArray(int value);
    bool createArray(int capacity);
    void clear();
};


#endif //INC_235_QS_QS_H
