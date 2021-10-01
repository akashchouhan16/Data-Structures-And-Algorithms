/*
Given a 2D array,find the row with the maximum number of 1s. 

eg:                 {{0, 0, 0, 1},
                    {0, 1, 1, 1},
                    {1, 1, 1, 1},
                    {0, 0, 0, 0}};
                    
Output: 2
*/
#include <iostream>
using namespace std;
int main()
{
    int a[4][4];
    a={{1,1,0,0},{1,1,1,1},{1,1,0,0},{1,1,1,0}};
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
 int c=0;
 int mr;
 int mc=-32000;
 for(int i=0;i<4;i++)
    {
        c=0;
        for(int j=0;j<4;j++)
        {
            if(a[i][j]==1)
            {
                c++;
            }
           if(mc<c)
           {
               mc=c;
               mr=i;
           }
        }
    }
    cout<<" ROW "<<mr<<"has"<<mc<<" 1s \n";
    return 0;
}

