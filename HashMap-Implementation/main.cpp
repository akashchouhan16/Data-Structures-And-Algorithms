#include <ctime>
#include <iterator>
#include <cstdlib>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>
// #include "Hash.hpp"
/* Need changes */
using namespace std;

class Hash
{
private:
    static const int LIMIT = 20;
    list<pair<int, string>> HashMap[LIMIT];

public:
    bool isEmpty() const;
    inline int hashFunc(int key);
    void insertValue(int key, string data);
    void removeValue(int key);
    string searchTable(int key);
    void printTable();
};

bool Hash::isEmpty() const
{
    int collectiveSize = 0;
    for (int i = 0; i < LIMIT; i++)
    {
        collectiveSize += HashMap[i].size();
    }
    if (!collectiveSize)
        return true;
    else
        return false;
}
inline int Hash::hashFunc(int key) { return key % LIMIT; }

void Hash::insertValue(int key, string data)
{
    int hashValue = hashFunc(key);
    list<pair<int, string>> &cell = HashMap[hashValue];
    auto bitr = begin(cell);
    bool keyExists = false;

    for (; bitr != end(cell); bitr++)
    {
        if (bitr->first == key)
        {
            keyExists = true;
            bitr->second = data;
            printf("[WARNING] Key Exists. The value has been replaced.\n");
            break;
        }
    }
    if (!keyExists)
    {
        // cell.emplace_back({key, data});
        pair<int, string> temp;
        temp.first = key;
        temp.second = data;
        HashMap[hashValue].push_back(temp);
    }
    return;
}

void Hash::removeValue(int key)
{
    int hashValue = hashFunc(key);
    auto &cell = HashMap[hashValue];
    auto bitr = begin(cell);
    bool keyExists = false;

    for (; bitr != end(cell); bitr++)
    {
        if (bitr->first == key)
        {
            keyExists = true;
            bitr = cell.erase(bitr);
            printf("[INFO] Key-Item removed Successfully.\n");
            break;
        }
    }
    if (!keyExists)
        printf("[WARNING] Item Couldn't be removed!. Key Not Found.\n");
    return;
}
void Hash::printTable()
{
    for (int i = 0; i < this->LIMIT; i++)
    {
        if (HashMap[i].size() == 0)
            continue;

        auto x = HashMap[i].begin();

        for (; x != HashMap[i].end(); x++)
        {
            printf("[INFO] Key : %d | Value : %s\n", x->first, x->second);
        }
    }
    return;
}

int main()
{
    Hash HT;
    if (HT.isEmpty())
    {
        cout << "Hash Table is Currenty Empty.\n";
    }
    else
        cout << "Invaid Hash Table initiation. NON-EMPTY Hash Table Created.\n";

    //Insertion :
    long long phoneNumber, counter = 1;
    string Name;
    do
    {
        counter++;
        counter %= 5;
        cout << "Enter Phone Number & Name : ";
        // cin >> phoneNumber;
        scanf("%ld", &phoneNumber);
        // Invalid digit to be fixed.

        //Infinite loop Bug for large phone no, input.
        //Fix 2:
        phoneNumber %= 100;
        if (phoneNumber <= 0)
            break;
        cin >> Name;
        HT.insertValue(int(phoneNumber), Name);
        HT.printTable();
    } while (true);
    //Test Remove.
    HT.removeValue(100);
    HT.removeValue(23);

    if (HT.isEmpty())
    {
        cout << "[INFO] Hash Table is Currenty Empty.\n";
    }
    else
        cout << "[INFO] NON-EMPTY Hash Table Created.\n";
    return 0;
}