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
    bool wordEnd;
    TrieNode *child[26];
    TrieNode() : data('$'), wordEnd(false)
    {
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

class Auto_Complete
{
    TrieNode nodePool[1000];
    TrieNode *root;
    int poolCount;

protected:
    TrieNode *createNode(char ch)
    {
        TrieNode *node = &nodePool[poolCount++];
        node->data = ch;
        return node;
    }
    bool isLastNode(TrieNode *node)
    {
        if (node)
        {
            for (int i = 0; i < 26; i++)
            {
                if (node->child[i] != NULL)
                    return false;
            }
            return true;
        }
        return false;
    }

    void generateSuggestions(TrieNode *current, string prefix)
    {
        if (current->wordEnd)
            cout << prefix << endl;

        if (isLastNode(current))
            return;

        // preOrder on not-null child nodes from the current (at prefix end)
        for (int i = 0; i < 26; i++)
        {
            if (current->child[i])
            {
                prefix.push_back(i + 'a');
                generateSuggestions(current->child[i], prefix);
                prefix[prefix.size() - 1] = '\0';
            }
        }
        return;
    }

public:
    Auto_Complete() { init(); }
    void init()
    {
        this->poolCount = 0;
        this->root = &nodePool[poolCount++];
        root->data = '$';
        cout << "[*]Trie DS Initialized.\n";
    }
    void insert(string);
    bool search(string);
    void printAutoSuggestion(const string); // query is passed to generate auto complete suggestions.
};

void Auto_Complete::insert(string word)
{
    int index = 0;
    TrieNode *current = root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        index = word[i] - 'a';
        if (current->child[index] == NULL)
            current->child[index] = createNode(word[i]);

        if (i == word.size() - 1)
            current->child[index]->wordEnd = true;

        current = current->child[index];
    }
    return;
}

bool Auto_Complete::search(string word)
{
    int index = 0;
    TrieNode *current = root;
    for (int i = 0; word[i] != '\0'; i++)
    {
        index = word[i] - 'a';
        if (current->child[index] == NULL)
            return 0;

        current = current->child[index];
    }
    return (current and current->wordEnd);
}

// Auto Complete Feature Implementation:
void Auto_Complete::printAutoSuggestion(const string query)
{
    TrieNode *current = root;
    for (int i = 0; query[i] != '\0'; i++)
    {
        int index = query[i] - 'a';
        if (current->child[index] == NULL)
            return;
        current = current->child[index];
    }

    bool doesWordExist = (current and current->wordEnd);
    bool isLast = isLastNode(current);

    // Case 1: Word Exists in the Trie DS, but the there is no subtree to auto complete:
    if (doesWordExist and isLast)
    {
        cout << query << endl;
        return;
    }
    // Case 2: Words exist below the current node:
    if (not isLast)
    {
        string prefix = query;
        generateSuggestions(current, prefix);
        return;
    }

    return;
}

signed main()
{
    Auto_Complete object;
    object.insert("hello");
    object.insert("dog");
    object.insert("hell");
    object.insert("cat");
    object.insert("a");
    object.insert("hel");
    object.insert("help");
    object.insert("helps");
    object.insert("helping");

    cout << "=========================================================" << endl;
    cout << "\t\tInsert to Dictionary\n[*]Enter words to insert query or type exit() to terminate...\n";
    while (true)
    {
        string word;
        cout << "[*]Enter word to insert: ";
        cin >> word;
        if (word == "exit" or word == "exit()")
            break;
        object.insert(word);
    }
    cout << "=========================================================" << endl;
    cout << "\t\tAuto Complete Search Querying\nEnter search query or type exit() to terminate code...\n";

    while (true)
    {
        string query;
        cout << "[*]Enter query...: ";
        cin >> query;
        if (query == "exit" || query == "exit()")
            break;
        object.printAutoSuggestion(query);
    }

    return 0;
}