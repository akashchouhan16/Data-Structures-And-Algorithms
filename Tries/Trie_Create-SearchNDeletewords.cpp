/*
Sample Tests:
[*] Trie DS Initialized.
Enter 1 to insert(word)
Enter 2 to search(word)
Enter 3 to delete(word)
Enter 0 to exit()
Enter Choice: 1
aba
Enter Choice: 1
abc
Enter Choice: 2
abc
[*]abc : Found!
Enter Choice: 2
ab
[*]ab : Not Found!
Enter Choice: 1
ab
Enter Choice: 2
ab
[*]ab : Found!
Enter Choice: 3
ab
[*]ab deleted from Trie DS.
Enter Choice: 2
ab
[*]ab : Not Found!
Enter Choice: 0
[*]Code Terminated.
*/
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

class Trie_2
{
    TrieNode *root;
    TrieNode nodePool[100];
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
    Trie_2() {}
    void initialize()
    {
        poolCount = 0;
        root = &nodePool[poolCount++];
        for (int i = 0; i < 26; i++)
            root->child[i] = NULL;
        cout << "[*] Trie DS Initialized.\n";
    }
    void insert(string);
    bool search(string);
    void delete_trie(string);
};

void Trie_2::insert(string word)
{
    TrieNode *current = root;
    int index;
    for (int i = 0; word[i] != '\0'; i++)
    {
        index = word[i] - 'a';
        if (current->child[index] == NULL)
            current->child[index] = createNode(word[i]);
        current->child[index]->wordCount += 1; // prefix counter.
        if (i == word.size() - 1)
            current->child[index]->wordEnd = 1;

        current = current->child[index];
    }
    return;
}
bool Trie_2::search(string word)
{
    int n = word.size(), index = 0;
    TrieNode *current = root;

    for (int i = 0; word[i] != '\0'; i++)
    {
        index = word[i] - 'a';
        if (current->child[index] == NULL || current->child[index]->wordCount == 0)
            return false;
        current = current->child[index];
    }
    return current->wordEnd >= 1;
}
void Trie_2::delete_trie(string word)
{
    if (search(word))
    {
        TrieNode *current = root;
        int index;
        for (int i = 0; word[i] != '\0'; i++)
        {
            index = word[i] - 'a';
            current->child[index]->wordCount -= 1;
            if (i == word.size() - 1)
                current->child[index]->wordEnd = 0; // set to word not present.
            current = current->child[index];
        }
        cout << "[*]" << word << " deleted from Trie DS.\n";
    }
    else
        cout << "[*]" << word << " does not exist in Trie DS.\n";
    return;
}

signed main()
{
    Trie_2 object;
    object.initialize();

    int choice;
    cout << "Enter 1 to insert(word)\nEnter 2 to search(word)\nEnter 3 to delete(word)\nEnter 0 to exit()\n";
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
        else if (choice == 3)
        {
            string input;
            cin >> input;
            object.delete_trie(input);
        }
        else
            cout << "[*]Invalid choice.\n";
    }

    return 0;
}