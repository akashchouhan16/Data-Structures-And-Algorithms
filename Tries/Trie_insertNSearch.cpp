#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define ll long long
#define nullptr NULL
#define all(x) x.begin(), x.end()
#define MOD int(1e9 + 7)
#define tests \
    int t;    \
    cin >> t; \
    while (t--)

struct TrieNode
{
    char data;
    int wordCount; // Utilized to count words with a given prefix.
    int wordEnd;   // Utilized to implement search functionality for words.
    TrieNode *child[26];
    TrieNode() : data('$'), wordCount(0), wordEnd(0) {} // default construct.
};

class Trie
{
    TrieNode nodePool[1000]; // A default reserved node Pool of 1000 trie nodes.
    int poolCount;
    TrieNode *root;

protected:
    TrieNode *getNode(char ch)
    {
        TrieNode *newNode = &nodePool[poolCount++];
        for (int i = 0; i < 26; i++)
            newNode->child[i] = NULL;
        newNode->data = ch;
    }

public:
    Trie() {}
    void initialize()
    {
        poolCount = 0;
        root = &nodePool[poolCount++];
        root->data = '$';
        for (int i = 0; i < 26; i++)
            root->child[i] = NULL;
    }

    void insert(string input);
    bool search(string input);
};

// Implementation:
void Trie::insert(string input)
{
    TrieNode *current = root;
    int index = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        index = input[i] - 'a';
        if (current->child[index] == NULL)
            current->child[index] = getNode(input[i]);
        current->child[index]->wordCount += 1;
        if (i == input.size() - 1)
            current->child[index]->wordEnd = 1; // flag true for a word completion.

        current = current->child[index];
    }
    cout << "[*]" << input << ": Inserted.\n";
    return;
}

bool Trie::search(string input)
{
    int n = input.size(), index = 0;
    TrieNode *current = root;

    for (int i = 0; input[i] != '\0'; i++)
    {
        index = input[i] - 'a';
        if (current->child[index] == NULL || current->child[index]->wordCount == 0)
            return false;
        current = current->child[index];
    }
    return current->wordEnd >= 1;
}

signed main()
{
    Trie object;
    object.initialize();

    cout << "Enter 1 to insert()\nEnter 2 to search\nEnter 0 to exit()\n";
    int choice = 0;
    while (true)
    {
        cout << "Enter Choice: ";
        cin >> choice;
        if (choice == 0)
        {
            cout << "[*]Code Terminated.\n";
            break;
        }
        else if (choice == 1)
        {
            string input;
            cin >> input;
            object.insert(input);
        }
        else if (choice == 2)
        {
            string input;
            cin >> input;
            bool result = object.search(input);
            cout << "[*]";
            result ? (cout << input << " : Found!\n") : (cout << input << " : Not Found!\n");
        }
        else
            cout << "[*]Invalid choice.\n";
    }
    return 0;
}