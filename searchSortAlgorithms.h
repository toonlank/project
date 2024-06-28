#ifndef H_searchSortAlgorithms
#define H_searchsortAlgorithms
#include <iostream>
#include <ctime>

using namespace std;
template <class elemType>
void recQuickSort(elemType[], int, int);
template <class elemType>
int partition(elemType[], int, int);

template <class elemType>
int seqSearch(const elemType list[], int length, const elemType& item)
{
    int loc = 0;
    bool found = false;

    while (loc < length && !found)
    {
        cout << "cycle: " << loc << " ";
        if (list[loc] == item)
            found = true;
        else
            loc++;
    }
    cout << endl;
    if (found)
        return loc;
    else
        return -1;
} //end seqSearch


template <class elemType>
int binarySearch(const elemType list[], int length, const elemType& item)
{
    int first = 0;
    int last = length - 1;
    int mid = int();

    bool found = false;

    while (first <= last && !found)
    {
        mid = (first + last) / 2;
        //cout << "mid: " << mid << endl;

        if (list[mid] == item)
            found = true;
        else if (list[mid] > item)
            last = mid - 1;
        else
            first = mid + 1;
    }

    if (found)
        return mid;
    else
        return -1;
} //end binarySearch

template <class elemType>
void bubbleSort(elemType list[], int length)
{
    for (int i = 1; i < length; i++)
    {
        for (int index = 0; index < length - i; index++)
        {
            if (list[index] > list[index + 1])
            {
                //swap them
                elemType temp = list[index];
                list[index] = list[index + 1];
                list[index + 1] = temp;
            }
        }
    }
} //end bubbleSort

template <class elemType>
void selectionSort(elemType list[], int length)
{
    int minIndex = 0;

    for (int loc = 0; loc < length; loc++)
    {
        minIndex = minLocation(list, loc, length - 1);
        //cout << "minIndex :" << minIndex << " ";
        //swap(list, loc, minIndex);
        elemType temp = list[loc];
        list[loc] = list[minIndex];
        list[minIndex] = temp;
    }
} //end selectionSort

template <class elemType>
void swap(elemType list[], int first, int second)
{
    elemType temp;
    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
} //end swap

template <class elemType>
int minLocation(elemType list[], int first, int last)
{
    int minIndex = first;

    for (int loc = first + 1; loc <= last; loc++)
    {
        if (list[loc] < list[minIndex])
        {
            minIndex = loc;
        }
    }
    return minIndex;
} //end minLocation

template <class elemType>
void insertionSort(elemType list[], int length)
{
    for (int firstOutOfOrder = 1; firstOutOfOrder < length; firstOutOfOrder++)
    {
        if (list[firstOutOfOrder] < list[firstOutOfOrder - 1])
        {
            elemType temp = list[firstOutOfOrder];
            int location = firstOutOfOrder;

            do
            {
                list[location] = list[location - 1];
                location--;
            } while (location > 0 && list[location - 1] > temp);

            list[location] = temp;
        }
    }
} //end insertionSort

template <class elemType>
void quickSort(elemType list[], int length)
{
    
    recQuickSort(list, 0, length - 1);
    
} //end quickSort

template <class elemType>
void recQuickSort(elemType list[], int first, int last)
{
    int pivotLocation = 0;
    if (first < last)
    {
        pivotLocation = partition(list, first, last);
        if ((pivotLocation - 1) - first < 20) {
            insertionSort(list, ((pivotLocation - 1) - first) + 1);
        }
        else {
            recQuickSort(list, first, pivotLocation - 1);
        }
        if (last - (pivotLocation + 1) < 20) {
            insertionSort(list, last - (pivotLocation + 1));
        }
        else {
            recQuickSort(list, pivotLocation + 1, last);
        }
    }
} //end recQuickSort

template <class elemType>
int partition(elemType list[], int first, int last)
{
    elemType pivot;

    int index, smallIndex;

    swap(list, first, (first + last) / 2);

    pivot = list[first];
    smallIndex = first;

    for (index = first + 1; index <= last; index++)
    {
        if (list[index] < pivot)
        {
            smallIndex++;
            swap(list, smallIndex, index);
        }
    }
    swap(list, first, smallIndex);

    return smallIndex;
} //end partition
#endif