

//-----------------------------------------------------------------------------------------------------------------  Tech Dose implementation
//CODE TO Count_Number_Of_Strings_With_Given_Prefix
//Assumption: All characters are in lowercase
#include<iostream>
using namespace std;
//#define NULL 0

struct Trienode
{
    char data;
    int wc;  //wc:word_count
    Trienode *child[26];
};
Trienode nodepool[100000];  //Pool of 100K Trienodes
Trienode *root;    //Root of Trie
int poolcount;  //Always points to next free Trienode

void init() //Initializer function
{
    poolcount = 0;
    root = &nodepool[poolcount++];
    root->data = '/';
    for( int i=0;i<26;++i)
        root->child[i] = NULL;
}

Trienode *getNode(char c)
{
    Trienode *newnode = &nodepool[poolcount++];
    newnode->data = c;
    for( int i=0;i<26;++i)
        newnode->child[i] = NULL;
    newnode->wc=0;
    return newnode;
}

void insert(char *s)
{
    Trienode *curr = root;
    int index;
    for(int i=0; s[i]!='\0'; ++i)
    {
        index = s[i]-'a';
        if(curr->child[index]==NULL)
            curr->child[index] = getNode(s[i]);
        curr->child[index]->wc += 1;
        curr = curr->child[index];
    }
}

bool search(char *s)
{
    Trienode *curr = root;
    int index;
    for(int i=0; s[i]!='\0'; ++i)
    {
        index = s[i]-'a';
        if(curr->child[index]==NULL || curr->child[index]->wc == 0)
            return false;
        curr = curr->child[index];
    }
    return true;
}

bool Triedelete(char *s)
{
    if(search(s))
    {
        Trienode *curr = root;
        int index;
        for(int i=0; s[i]!='\0'; ++i)
        {
            index = s[i]-'a';
            curr->child[index]->wc -=1;
            curr = curr->child[index];
        }
    }
}

int countPrefix(string s)
{
    Trienode *curr = root;
    int index;
    for(int i=0; s[i]!='\0'; ++i)
    {
        index = s[i]-'a';
        if(curr->child[index]==NULL || curr->child[index]->wc == 0)
            return 0;   //No string with given prefix is present
        curr = curr->child[index];
    }
    return curr->wc;
}

int main()
{
    init();
    char a[5] = {'a','r','m','y'};
    char b[5] = {'a','r','m'};
    char c[5] = {'a','r','m','s'};
    char d[5] = {'a','r','y'};
    char e[5] = {'a','m','y'};
    char f[5] = {'a','p','i'};


    insert(a);
    insert(b);
    insert(c);
    insert(d);
    insert(e);
    insert(f);

    //cout<<search(b)<<"\n";

    printf("No of strings with given prefix = %d\n",countPrefix("a"));
    printf("No of strings with given prefix = %d\n",countPrefix("ar"));
    printf("No of strings with given prefix = %d\n",countPrefix("arm"));
    printf("No of strings with given prefix = %d\n",countPrefix("army"));
    printf("No of strings with given prefix = %d\n",countPrefix("armi"));
    printf("No of strings with given prefix = %d\n",countPrefix("ary"));

    cout<<"Deletion...STARTED\n";
    Triedelete(a);
    Triedelete(d);
    cout<<"DONE...\n\n";


    printf("No of strings with given prefix = %d\n",countPrefix("a"));
    printf("No of strings with given prefix = %d\n",countPrefix("ar"));
    printf("No of strings with given prefix = %d\n",countPrefix("arm"));
    printf("No of strings with given prefix = %d\n",countPrefix("army"));
    printf("No of strings with given prefix = %d\n",countPrefix("armi"));
    printf("No of strings with given prefix = %d\n",countPrefix("ary"));

    return 0;
}











// //-----------------------------------------------------------------------------------------------------------------  GFG implementation

// // C++ implementation of delete
// // operations on Trie
// #include <bits/stdc++.h>
// using namespace std;

// const int ALPHABET_SIZE = 26;

// // trie node
// struct TrieNode {
// 	struct TrieNode* children[ALPHABET_SIZE];

// 	// isEndOfWord is true if the node represents
// 	// end of a word
// 	bool isEndOfWord;
// };

// // Returns new trie node (initialized to NULLs)
// struct TrieNode* getNode(void)
// {
// 	struct TrieNode* pNode = new TrieNode;

// 	pNode->isEndOfWord = false;

// 	for (int i = 0; i < ALPHABET_SIZE; i++)
// 		pNode->children[i] = NULL;

// 	return pNode;
// }

// // If not present, inserts key into trie
// // If the key is prefix of trie node, just
// // marks leaf node
// void insert(struct TrieNode* root, string key)
// {
// 	struct TrieNode* pCrawl = root;

// 	for (int i = 0; i < key.length(); i++) {
// 		int index = key[i] - 'a';
// 		if (!pCrawl->children[index])
// 			pCrawl->children[index] = getNode();

// 		pCrawl = pCrawl->children[index];
// 	}

// 	// mark last node as leaf
// 	pCrawl->isEndOfWord = true;
// }

// // Returns true if key presents in trie, else
// // false
// bool search(struct TrieNode* root, string key)
// {
// 	struct TrieNode* pCrawl = root;

// 	for (int i = 0; i < key.length(); i++) {
// 		int index = key[i] - 'a';
// 		if (!pCrawl->children[index])
// 			return false;

// 		pCrawl = pCrawl->children[index];
// 	}

// 	return (pCrawl != NULL && pCrawl->isEndOfWord);
// }

// // Returns true if root has no children, else false
// bool isEmpty(TrieNode* root)
// {
// 	for (int i = 0; i < ALPHABET_SIZE; i++)
// 		if (root->children[i])
// 			return false;
// 	return true;
// }

// // Recursive function to delete a key from given Trie
// TrieNode* remove(TrieNode* root, string key, int depth = 0)
// {
// 	// If tree is empty
// 	if (!root)
// 		return NULL;

// 	// If last character of key is being processed
// 	if (depth == key.size()) {

// 		// This node is no more end of word after
// 		// removal of given key
// 		if (root->isEndOfWord)
// 			root->isEndOfWord = false;

// 		// If given is not prefix of any other word
// 		if (isEmpty(root)) {
// 			delete (root);
// 			root = NULL;
// 		}

// 		return root;
// 	}

// 	// If not last character, recur for the child
// 	// obtained using ASCII value
// 	int index = key[depth] - 'a';
// 	root->children[index] =
// 		remove(root->children[index], key, depth + 1);

// 	// If root does not have any child (its only child got
// 	// deleted), and it is not end of another word.
// 	if (isEmpty(root) && root->isEndOfWord == false) {
// 		delete (root);
// 		root = NULL;
// 	}

// 	return root;
// }

// // Driver
// int main()
// {
// 	// Input keys (use only 'a' through 'z'
// 	// and lower case)
// 	string keys[] = { "the", "a", "there",
// 					"answer", "any", "by",
// 					"bye", "their", "hero", "heroplane" };
// 	int n = sizeof(keys) / sizeof(keys[0]);

// 	struct TrieNode* root = getNode();

// 	// Construct trie
// 	for (int i = 0; i < n; i++)
// 		insert(root, keys[i]);

// 	// Search for different keys
// 	search(root, "the") ? cout << "Yes\n" : cout << "No\n";
// 	search(root, "these") ? cout << "Yes\n" : cout << "No\n";

// 	remove(root, "heroplane");
// 	search(root, "hero") ? cout << "Yes\n" : cout << "No\n";
// 	return 0;
// }











