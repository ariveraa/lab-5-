//
// Created by Adrian Rivera on 10/27/18.
//

#include "QS.h"

int numCheck  = 0 ;
string emptystring = "";

QS :: QS(){
    array = NULL;
    counter = 0;
}


void QS ::sortAll() {

}

int QS :: medianOfThree(int left, int right){
    int temp = 0;

    bool empty = true;
    for (int i = 0; i < maxCapacity +1 ; i++){
        if(array[i] != 0 ){
            empty = false;
        }
    }
    if(empty){
        numCheck = 0 ;
        return -1;
    }
    if (left > right){
        return -1;
    }
    if(left < 0 || right  < 0 ){
        return -1;
    }
    if(left > maxCapacity +1 || right > maxCapacity +1 ){
        return -1;
    }

    middle = (left + right)/2;
    if(array[middle] < array[left] ){
        temp = array[left];
        array[left] = array[middle];
        array[middle]  = temp;
    }
    if(array[middle] > array[right]){
        temp = array[right];
        array[right] = array[middle];
        array[middle]  = temp;
    }
    return middle;
}

int QS :: partition(int left, int right, int pivotIndex) {
    int temp = 0;
    temp = array[pivotIndex];
    array[pivotIndex] = array[left];
    array[left] = temp;

    int up = left + 1;
    int down  = right;

    do {
        while ((up != right) && (array[up] <= array[left])) {
            cout << "up:"  << up << "right:" << right <<   array[up] << array[left] << endl ;
            up++;

        }
        while((array[left] < array[down]) && (down != left )  ){
            down --;
            cout << "down"  << endl;
        }
        if(up < down){
            temp = array[up];
            array[up] = array[down];
            array[down] = temp;
        }
    }while (up<down);
       temp = array[left];
       array[left] = array[down];
       array[down] = temp;
       return down;


}

//int* quicksort(int *array) {

//    partitioned = partition(array);
//    left = getLeftHalf
//    right = getRightHalf
//    INT [SIZE/2] left = array[]
//    quicksort(left);
//    quicksort(right);
//    return array;

}

string QS :: getArray() const {

    if(array == NULL){

        return emptystring;
    }
    for (int i = 0; i < maxCapacity +1 ; i++){
        if(array[i] == 0 ){
            numCheck++;
        }
    }
    if(numCheck == maxCapacity +1 ){
        numCheck = 0 ;
        return emptystring;
    }

    stringstream arrayString;
    for(int i = 0; i < counter; i++){
        if (i < counter-1 ){
            arrayString << array[i]<< ",";
        }
        else {
            arrayString << array[i];
        }
    }
    return arrayString.str();
}

int QS :: getSize() const {
    cout << counter << endl;
    return counter;
}

bool QS ::  addToArray(int value){
    if(counter > maxCapacity){
        return false;
    }
    array[counter] = value;
    counter++ ;
    return true;
}

bool QS :: createArray(int capacity){
    if (capacity < 0 ){
        return false;
    }
    if(array != NULL){
        delete array;
    }
    counter = 0 ;
   array = new int [capacity];
    for (int i = 0; i < capacity ; i++){
        array[i] = 0;
    }

    maxCapacity = capacity-1;
    return true;
}

void QS :: clear() {
    counter = 0;
}