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
    int wordCount;
    int wordEnd;
    TrieNode *child[26];
    TrieNode() : data('$'), wordCount(0), wordEnd(0) {}
};

class Trie
{
    TrieNode *root;
    TrieNode nodePool[1000];
    int poolCount;

protected:
    TrieNode *createNode(char ch)
    {
        TrieNode *newNode = &nodePool[poolCount++];
        newNode->data = ch;
        for (int i = 0; i < 26; i++)
            newNode->child[i] = NULL;
        return newNode;
    }

public:
    Trie() {}
    void initialize()
    {
        poolCount = 0;
        root = &nodePool[poolCount++];
        for (int i = 0; i < 26; i++)
            root->child[i] = NULL;
    }
    void insert(string);
    int countPrefix(string);
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
            current->child[index] = createNode(input[i]);
        current->child[index]->wordCount += 1;
        if (i == input.size() - 1)
            current->child[index]->wordEnd = 1; // flag true for a word completion.

        current = current->child[index];
    }
    cout << "[*]" << input << ": Inserted.\n";
    return;
}

int Trie::countPrefix(string word)
{
    int index = 0;
    TrieNode *current = root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        index = word[i] - 'a';
        if (current->child[index]->wordCount == 0 || current->child[index] == NULL)
            return 0;
        current = current->child[index];
    }

    return current->wordCount;
}

signed main()
{
    Trie object;
    object.initialize();

    cout << "Enter 1 to insert()\nEnter 2 to count word with input prefix\nEnter 0 to exit()\n";
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
            cout << "[*]Number Of words with prefix {" << input << "}: " << object.countPrefix(input) << endl;
        }
        else
            cout << "[*]Invalid choice.\n";
    }
    return 0;
}