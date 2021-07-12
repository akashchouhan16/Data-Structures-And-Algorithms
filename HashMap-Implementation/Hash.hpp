//Hash Map Struture & methods.
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>
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