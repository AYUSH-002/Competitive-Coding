#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ONLINE_JUDGE
#define DEBUG_CODE

#ifdef DEBUG_CODE
#define TRACE(msg, ...) printTrace(__LINE__, __FILE__, msg, __VA_ARGS__)
#define PRINT_ARRAY(arr, n, type) myPrint<type>(arr, n)
#else
#define TRACE(msg, ...)
#define PRINT_ARRAY(arr, n, type)
#endif

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct TrieNode *getNode()
{
    struct TrieNode *parentNode = new TrieNode;

    parentNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        parentNode->children[i] = NULL;
    }

    return parentNode;
}

void insert(struct TrieNode *root, vector<int> word)
{
    
    struct TrieNode *node = root;

    
    for (int i = 0; i < word.size(); i++)
    {
        
        if (!node->children[word[i]])
        {
            node->children[word[i]] = getNode();
        }

        
        node = node->children[word[i]];
    }

    
    node->isEndOfWord = true;
}

int search(struct TrieNode *root, vector<int> word)
{
    int res = 0;
    struct TrieNode *node = root;

    for (int i = 0; i < word.size(); i++)
    {
        if (!node->children[word[i]])
        {
            return res;
        }
        res++;

        node = node->children[word[i]];
    }

    return res;
}

template <typename T1>
void myPrint(T1 *arr, int n)
{
    cout << "myPrint Function output is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void printTrace(int line, const char *fileName, const char *msg, ...)
{
    va_list args;
    char buffer[1024 + 2] = {0};
    snprintf(buffer, sizeof(buffer), "%s(%d) : ", fileName, line);
    int stringLength = strnlen(buffer, 1024);
    int remainingBufferSize = 1024 - stringLength;
    va_start(args, msg);
    vsnprintf(buffer + stringLength, remainingBufferSize, msg, args);
    va_end(args);
    cout << buffer << "\n"
         << flush;
}

void getMinSteps()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> vec1(n, vector<int>(m));
    vector<vector<int>> vec2;

    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int num;
            cin >> num;
            vec1[i][j] = num - 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        
        vector<int> tempVec(m);

        
        for (int j = 0; j < m; j++)
        {
            
            int idx = vec1[i][j];

            
            tempVec[idx] = j;
        }

        
        vec2.push_back(tempVec);
    }

    struct TrieNode *root = getNode();
    for (int i = 0; i < n; i++)
    {
        insert(root, vec2[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int res = search(root, vec1[i]);
        cout << res << " ";
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    while (t--)
    {
        getMinSteps();
    }
    return 0;
}
