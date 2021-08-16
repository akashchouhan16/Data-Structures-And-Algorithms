/* Problem Statement : A variation of the classical knapsack problem, where we are provided with an items' array containing n values and n corresponding item weights. Our thief has a sack of capacity W. We need to put in as much items as possible into the sack that will maximize our value but is within the sack's weight limit W.
In Fractional KnapSack -> we are allowed to take a portion of an item if the whole item's weight cannot be accomodated.
* struct item {int values; int weight};
Sample Test cases : 
ip1 : W = 20, items{values ={40 24 30 21}, weight={5,4,6,7,6}}      op1 : (40+24+30+15) = 109 ANS
      
ip-op2 :
INPUT ORDER : (W)capacity of sack | No Of Items (n) | (<values,weight> of n items)
50 3
60 10
100 20
120 30
val : 60 | weight : 10
val : 100 | weight : 20
val : 120 | weight : 30
Maximum value in KnapSack = 240 ANS
*/
#include <algorithm>
#include <bits/stdc++.h>

#define ll long long
#define pb(x) push_back(x);
#define pp() pop_back()
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pqq priority_queue
#define gi greater<int>
#define all(arr) arr.begin(), arr.end()
#define loop(i, n) for (int i = 0; i < n; i++)
#define MOD ll(1e9 + 7)
#define tests(t) \
    int t;       \
    cin >> t;    \
    while (t--)
using namespace std;
inline void IOS()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// Solution
struct items
{
    int value;
    int weight;
};
struct DATA
{
    int value;
    int wt;
    double ratio; //ratio = value/weight for every item.
};

class Solution
{
public:
    static bool compare(DATA d1, DATA d2)
    {
        double v1 = double(d1.value / d1.wt);
        double v2 = double(d2.value / d2.wt);

        return (v1 > v2); //to sort in descending order of val/wt ratios to mazimize profit from items.
    }

    double fractionalKnapSack(int W, items arr[], int n)
    {
        DATA DB[n];
        loop(i, n)
        {
            DB[i].value = arr[i].value;
            DB[i].wt = arr[i].weight;
            DB[i].ratio = double(arr[i].value / arr[i].weight);
        }
        // sort on the basis of ratio val/wt :
        sort(DB, DB + n, compare);
        double output = 0.0;
        loop(i, n)
        {
            if (W >= DB[i].wt)
            {
                //can be accomodated into the sack
                output += (DB[i].value);
                W -= DB[i].wt;
                continue;
            }
            //else if we cannot add the whole item into the sack, we need to add a portion of item which will add the max value to output :
            double ratio = double(DB[i].value / DB[i].wt);
            output += (ratio * W);
            W = 0; //capacity exhausted.
            break;
        }
        return output;
    }
    friend void display(items *X, int size);
};

void display(items *X, int size)
{
    loop(i, size)
    {
        cout << "val : " << X[i].value << " | weight : " << X[i].weight << endl;
    }
    return;
}
int main()
{
    IOS();
    tests(t)
    {
        system("CLS");
        cout << "INPUT ORDER : (W)capacity of sack | No Of Items (n) | (<values,weight> of n items)";
        cout << endl;
        int n, W;
        cin >> W >> n;
        items input[n];
        loop(i, n)
        {
            int val, wt;
            cin >> val >> wt;
            input[i].value = val;
            input[i].weight = wt;
        }
        display(input, n);

        Solution Obj;
        double answer = Obj.fractionalKnapSack(W, input, n);
        cout << "Maximum value in KnapSack = " << answer << endl;
    }
    return 0;
}