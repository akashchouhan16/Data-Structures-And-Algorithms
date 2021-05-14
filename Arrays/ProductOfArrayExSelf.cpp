// Product of Array Elements except SELF. LEETCODE : 238
#include "MaxSumSubarray.cpp"

class LeetCode238 : public Kadanes
{
public:
    LeetCode238() {}
    vector<int> getProductArray()
    {
        vector<int> output;
        int currProd = 1;
        int n = D.db.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                currProd = currProd * D.db[j];
            }
            output.push_back(currProd);
            currProd = 1;
        }
        return output;
    }
    vector<int> OptimisedV1()
    {
        vector<int> output2;
        int NetProd = 1;
        for (int i = 0; i < D.maxCap; i++)
            NetProd = NetProd * D.db[i];

        for (int i = 0; i < D.db.size(); i++)
        {
            output2.push_back(NetProd / D.db[i]);
        }
        return output2;
    }
    vector<int> MostOptimised()
    {
        vector<int> temp;
        int res = 1;
        int *arr = new int[D.maxCap];
        arr[0] = 1;
        for (int i = 1; i < D.maxCap; i++)
        {
            arr[i] = arr[i - 1] * D.db[i - 1];
        }
        for (int i = D.maxCap - 1; i >= 0; i--)
        {
            arr[i] = arr[i] * res;
            res = res * D.db[i];
        }
        for (int i = 0; i < D.maxCap; i++)
            temp.push_back(arr[i]);
        return temp;
    }
    void setData()
    {
        int x1, x2;
        cout << "Enter the Range : ";
        cin >> x1 >> x2;
        srand(time(nullptr));
        for (int i = 0; i < D.maxCap; i++)
        {
            D.db.push_back(1 + rand() % (x2 - x1 + 1));
        }
        return;
    }
};

int main()
{
    LeetCode238 obj;
    // obj.fillData(); // Linked to Max Sub Subarray Problem, in Kadances Class. Range : [-2,3]
    obj.setData();
    cout << "INPUT : ";
    obj.Display();
    vector<int> output = obj.getProductArray();
    cout << "OUTPUT : (TC = O(n^2) Space : O(1)) ";
    for (auto &x : output)
        cout << x << " ";
    cout << endl;
    // output.clear();
    // output.erase();
    vector<int> output2 = obj.OptimisedV1();
    cout << "OUTPUT2 : (TC = O(n) Space : O(2n)) ";
    for (auto &x : output2)
        cout << x << " ";
    cout << endl;
    cout << "OUTPUT3 : (TC = O(n), Space : O(1)) ";
    vector<int> output3 = obj.MostOptimised();
    for (auto &x : output3)
        cout << x << " ";
    cout << endl;
    return 0;
}