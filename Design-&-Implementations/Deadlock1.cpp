#include <iostream>
#include <ctime>
#include <cstdlib>

#include "userUtil.h"
using namespace std;

class MinimumResourceNeeded
{
protected:
    int noOfProcess;
    int TotalResource; //Minimum number of resouces need to avoid Deadlock in a system with p processes.
    int N;             //Number of resource units needed by each process in the system.
public:
    MinimumResourceNeeded()
    {
        noOfProcess = 0;
        TotalResource = 0;
        N = 0;
        MinimumResourceNeeded::input();
        Compute(TotalResource, noOfProcess, N); // Defined in UserUtil header.
    }
    void input()
    {
        try
        {
            cout << "Enter the Number of Processes in the System : ";
            cin >> noOfProcess;
            if (noOfProcess <= 0)
            {
                throw 101;
            }
            cout << "Enter the resource Requirement of Each Process : ";
            cin >> N;
            if (N <= 0)
            {
                throw 102;
            }
        }
        catch (int e)
        {
            if (e == 101)
            {
                cout << "Invalid Process Count!\n";
                exit(1);
            }
            else if (e == 102)
            {
                cout << "Invalid Resource req. count!\n";
                exit(2);
            }
        }
    }
    ~MinimumResourceNeeded()
    {
        cout << "Code terminated.";
    }
};

class MaxAllocationofR
{
    //To determine the maximum number of resources allocated to each process, still there is a deadlock.
protected:
    int *Processes;
    int noOfProcess;
    int *Resources;

public:
    MaxAllocationofR()
    {
        try
        {
            cout << "Enter the number of Processes in the System : ";
            cin >> this->noOfProcess;
            if (noOfProcess <= 0)
            {
                throw 101;
            }
            this->Processes = new int[this->noOfProcess];
            if (this->Processes == NULL)
            {
                throw 103;
            }
            MaxAllocationofR::InputR();
        }
        catch (int err)
        {
            if (err == 101)
            {
                cout << "Invalid Process Count!\n";
                exit(1);
            }
            if (err == 103)
            {
                cout << "Memory could not be allocated for Processes!\n";
                exit(3);
            }
        }
    }
    inline void InputR()
    {
        int x; //temporary var.
        cout << "Enter the Resource requirement for Each Process \n";
        this->Resources = new int[this->noOfProcess];
        for (int i = 0; i < this->noOfProcess; i++)
        {
            cout << "Enter Resource requirement for P" << i + 1 << " : ";
            cin >> x;
            Resources[i] = x;
        }
    }
    inline void ComputeMaxResource()
    {
        int maxAllocation = 0;
        for (int i = 0; i < this->noOfProcess; i++)
        {
            maxAllocation += Resources[i] - 1;
        }
        cout << "Maximum Resource to be allocated to the system for Deadlock to still persists : \n = "
             << maxAllocation;
        cout << endl;
        return;
    }
};
typedef struct ProgramDriver
{
    int Choice;
    string className;
    ProgramDriver(int Choice)
    {
        this->Choice = Choice;
        if (Choice == 1)
        {
            className = "Minimum Resource Needed : ";
            cout << "Class Invoked : " << className << endl;
            MinimumResourceNeeded object;
        }
        else
        {
            className = "MaxAllocationofR";
            cout << "Class Invoked : " << className << endl;
            MaxAllocationofR object2;
            object2.ComputeMaxResource();
        }
        cout << "=================================" << endl;
    }
} ProgramDriver;
int main()
{
    int choice;

    do
    {
        cout << "Enter 1 to Execute Minimum Resource Problem\nEnter 2 to execute MaxResource Problem\n\nEnter 0 to exit(0)\n";
        cout << "Enter choice : ";
        cin >> choice;
        ProgramDriver P1(choice);
    } while (true && choice);
    return 0;
}