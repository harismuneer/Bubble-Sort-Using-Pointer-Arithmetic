#include <iostream>
using namespace std;

void getArrayFromUser (int* startingAddress , int* endingAddress)
{
   while(startingAddress != endingAddress)
    {
        cout << "Enter the element : ";
        cin >> *startingAddress;
        startingAddress ++;
    }

    cout << endl;
}

void allocateArray (int* & myArray , int &size)
{
    cout << "Enter the size of the Array : ";
    cin  >> size;
    cout << endl;

    while (size <= 0)
    {
        cout << "The size , that you entered , is not valid . " <<endl;
        cout << "Enter a valid size : ";
        cin  >> size;
    }

    myArray = new int[size];
}

void swapByPointers (int* a , int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort (int* startingAddress , int* endingAddress)
 {
    int* endPtr = endingAddress;

    for (int* startPtr = startingAddress ; startPtr != endPtr; startPtr++)
    {
       for (int* i = startingAddress ; i != (endPtr - 1) ; i++)
       {
            if (*i >= *(i + 1))
            {
               swapByPointers (i , (i + 1));
            }
        }
    }

 }

void displaySortedArray (int* startingAddress , int* endingAddress)
{
  for (int* i = startingAddress ; i != endingAddress ; i++ )
          cout <<"Element of the sorted array : " << *i << endl;

  cout << endl;
}

void deAllocateArray (int* myArray)
{
    delete [] myArray ;

    cout << "The array has successfully been de-allocated .";
}


int main ()
{
    int* myArray = NULL;
    int size = 0;

    allocateArray(myArray , size);

    int* startingAddress = myArray;
    int* endingAddress = (myArray + size);

    getArrayFromUser (startingAddress , endingAddress);
    bubbleSort (startingAddress , endingAddress);
    displaySortedArray (startingAddress , endingAddress);
    deAllocateArray (myArray);

    return 0;
}
