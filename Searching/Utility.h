#ifndef UTILITY
#define UTILITY

class Utility
{
protected:
    int n;
    int *arr;

public:
    Utility(int s = 5) : n(s)
    {
        arr = new int[n];
        randomInput();
    }
    void randomInput()
    {
        int n1, n2;
        std::cout << "Enter Element range : ";
        std::cin >> n1 >> n2;
        for (int i = 0; i < n; i++)
            arr[i] = n1 + rand() % (n2 - n1 + 1);
        std::sort(arr + 0, arr + n);
        return;
    }
    int getFirstOcc(int element)
    {
        int l = 0, mid, h = n - 1, res = -1;
        while (l <= h)
        {
            mid = l + (h - l) / 2;
            if (arr[mid] == element)
            {
                res = mid;
                h = mid - 1;
            }
            else if (arr[mid] > element)
            {
                h = mid - 1;
            }
            else if (arr[mid] < element)
            {
                l = mid + 1;
            }
        }

        return (res != -1) ? res : -999;
    }
    int getLastOcc(int element)
    {
        int l = 0, mid, h = n - 1, res = -1;
        while (l <= h)
        {
            mid = l + (h - l) / 2;
            if (arr[mid] == element)
            {
                res = mid;
                l = mid + 1;
            }
            else if (arr[mid] > element)
            {
                h = mid - 1;
            }
            else if (arr[mid] < element)
            {
                l = mid + 1;
            }
        }
        return (res != -1) ? res : -999;
    }
    ~Utility()
    {
        delete[] arr;
        std::cout << "Code Terminated!\n";
    }
};
#endif
