//*********************************************************
// Author: D.S. Malik
//
// This program uses the class myStack to determine the 
// highest GPA from a list of students with their GPA.
// The program also outputs the names of the students
// who received the highest GPA.
//*********************************************************
//Chapter 17, page 1184

#include <iostream>  
#include <iomanip>
#include <fstream>
#include <string>
#include <list>
#include <iterator>


using namespace std;

int main()
{
        //Step 1
    double GPA;
    double highestGPA;
    string name;
    list<string> l1;
    ostream_iterator<string> screen(cout, " ");
    ifstream infile;

    infile.open("HighestGPAData.txt");          //Step 2

    if (!infile)                                //Step 3
    {
        cout << "The input file does not "
             << "exist. Program terminates!"
             << endl;
        return 1;
    }

    cout << fixed << showpoint;                 //Step 4
    cout << setprecision(2);                    //Step 4

    infile >> GPA >> name;                      //Step 5

    highestGPA = GPA;                           //Step 6

    while (infile)                              //Step 7
    {
        if (GPA > highestGPA)                   //Step 7.1
        {
            if (!l1.empty()) {
                l1.clear();
            }

            l1.push_back(name);

            highestGPA = GPA;                   //Step 7.1.3
        }
        else if (GPA == highestGPA)             //Step 7.2
            l1.push_back(name);
        infile >> GPA >> name;                  //Step 7.3
    }

    cout << "Highest GPA = " << highestGPA
         << endl;                               //Step 8
    cout << "The students holding the "
         << "highest GPA are:" << endl;

    copy(l1.begin(), l1.end(), screen);

    cout << endl;

    return 0;
}