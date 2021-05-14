// To Search an Element in an Infinite(Max Index Unknown, size not known) Sorted Container in O(log N)

#include "BinarySearchRecur.cpp"

class SearchInfiniteContainer : public RecurriveBinary
{
public:
    SearchInfiniteContainer() {}
    void GetRange(int key)
    {
        int low = 0, high = 1;
        while (vec[high] < key)
        {
            low = high;
            high *= 2; //Inc Exponentially.
        }
        cout << "Computed Range : [" << low << "," << high << "]\n";
        RecurriveBinary::BinSearch(low, high, key);
        return;
    }
    bool BinSearch(int low, int high, int key)
    {
        int mid;
        while (low < high)
        {
            mid = low + (high - low) / 2;
            if (vec[mid] == key)
            {
                cout << "Element" << key << " Found at Index : " << mid << endl;
                return true;
            }
            else if (vec[mid] > key)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        cout << "Element " << key << " Not Found!\n";
        return false;
    }
};

int main()
{
    SearchInfiniteContainer obj;
    obj.fillData();
    cout << "INPUT : ";
    obj.Display();
    cout << "Enter the key to Search in the Infinite Sorted Array : ";
    int key;
    cin >> key;
    obj.GetRange(key);
    return 0;
}