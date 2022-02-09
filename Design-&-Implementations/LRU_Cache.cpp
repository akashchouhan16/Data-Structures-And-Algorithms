/*
Problem Statement:
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
Implement the LRUCache class -> LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key)
                Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value)
                 Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.
*/

#include <bits/stdc++.h>
#include <algorithm>

#define MOD 1e9 + 7
#define INF INT_MAX
#define nullptr NULL
#define ff first
#define ss second
#define ll long long
#define lb long double
#define g(x) greater<x>
#define loop(i, n) for (int i = 0; i < n; i++)
#define v(x) vector<x>
#define p(x, y) pair<x, y>
#define mp make_pair
#define pb(x) push_back(x)
#define pp() pop_back()
#define all(x) x.begin(), x.end()
#define tests \
    int t;    \
    cin >> t; \
    while (t--)
using namespace std;
// A Cache Block:
struct Block
{
    int _val;
    int _key;
    Block *next;
    Block *prev;

    Block(int key, int val) : _key(key), _val(val)
    {
        next = nullptr;
        prev = nullptr;
    }
};

// Required LRU Class w/ default Capacity as 1 Block.
class lru_cache
{
protected:
    int _capacity;
    Block *head = new Block(-1, -1);
    Block *tail = new Block(-1, -1);
    map<int, Block *> _map;

    void add_block(Block *newBlock)
    {
        Block *temporary = head->next;
        newBlock->next = temporary;
        newBlock->prev = head;

        head->next = newBlock;
        temporary->prev = newBlock;
        std::cout << "[*] Block" << newBlock->_key << "|" << newBlock->_val << " Added to Cache Memory.\n";
    }
    void delete_node(Block *block)
    {
        Block *nextNode = block->next;
        Block *prevNode = block->prev;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

public:
    lru_cache(int capacity = 1) : _capacity(capacity)
    {
        head->next = tail;
        tail->prev = head;
        /* Upon initialization: [head ptr| Block Data] <==> [tail ptr | Block Data] */
    }
    /* Both get(int) & put(int,int) should run in O(1) Average Time Complexity. -> Amortised O(1) */
    int get(int);
    void put(int, int);
};

inline int lru_cache::get(int key)
{

    if (_map.find(key) != _map.end())
    {
        Block *resultant_node = _map[key];
        int value = resultant_node->_val;

        // Update the position of the Block on the DLL for LRU Cache.
        _map.erase(key);
        delete_node(resultant_node);
        add_block(resultant_node);
        _map[key] = head->next;

        return value;
    }
    else
        return -1;
}

inline void lru_cache::put(int key, int value)
{
    if (_map.find(key) != _map.end())
    {
        Block *existing_node = _map[key];
        _map.erase(key);
        delete_node(existing_node);
    }

    if (_map.size() == this->_capacity)
    {
        _map.erase(tail->prev->_key); // least recently used is at the tail of the DLL.
        delete_node(tail->prev);
        std::cout << "[*] LRU Block removed from Cache.\n";
    }

    add_block(new Block(key, value));
    _map[key] = head->next;
    std::cout << "[*] Block [" << key << " | " << value << "] added to Cache.\n";
}
signed main()
{
    lru_cache cache_Obj(2);
    cache_Obj.put(1, 1);
    cache_Obj.put(2, 2);

    std::cout << cache_Obj.get(1) << std::endl;

    cache_Obj.put(3, 3);
    std::cout << cache_Obj.get(2) << std::endl;
    cache_Obj.put(4, 4);

    std::cout << cache_Obj.get(1) << std::endl;
    std::cout << cache_Obj.get(3) << std::endl;
    std::cout << cache_Obj.get(4) << std::endl;

    return 0;
}