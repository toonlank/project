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
#include <queue>


using namespace std;

int main()
{
        //Step 1
    double GPA;
    double highestGPA;
    string name;
    queue<string> q1;

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
            while (!q1.empty()) {
                q1.pop();
            }

            q1.push(name);

            highestGPA = GPA;                   //Step 7.1.3
        }
        else if (GPA == highestGPA)             //Step 7.2
            q1.push(name);
        infile >> GPA >> name;                  //Step 7.3
    }

    cout << "Highest GPA = " << highestGPA
         << endl;                               //Step 8
    cout << "The students holding the "
         << "highest GPA are:" << endl;

    while (!q1.empty())               //Step 9
    {
        cout << q1.front() << endl;
        q1.pop();
    }

    cout << endl;

    return 0;
}