#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<stdlib.h>
#define ALPHABET_SIZE 128 //you can instead reduce the alphabet size and create
// your own mapping of character to index in array
int CHAR_TO_INDEX(char c)
{
    return (int)c;
}

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
// isEndOfWord is true if the node represents
// end of a word
bool isEndOfWord;
// void* data; //instead of checking for the presence or absence of a string,
// if we wish to assign some value with the key as a pair, then this could be
// uncommented
};
// Returns new trie node (initialized to NULLs)
struct TrieNode *getNode(void)
{
    struct TrieNode *pNode = NULL;
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    if (pNode)
    {
        int i;
        pNode->isEndOfWord = false;
        for (i = 0; i < ALPHABET_SIZE; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
}
// If not present, inserts key into trie
// If the key is prefix of trie node, just marks leaf node
void insert(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;
    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}
// Returns true if key presents in trie, else false
bool search(struct TrieNode *root, const char *key)
{
    int level;
    int length = strlen(key);
    int index;
    struct TrieNode *pCrawl = root;
    for (level = 0; level < length; level++)
    {
        index = CHAR_TO_INDEX(key[level]);
        if (!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl->isEndOfWord);
}
bool isEmpty(struct TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}
bool mdelete(struct TrieNode* root, char* key,int depth)
{
    if(depth == 0)
    {
    if(!search(root,key))
    {
        printf("enter valid array\n");
        return root;
    }
    }
    if(depth == strlen(key))
    {
         for (int i = 0; i < ALPHABET_SIZE; i++)
         {
            if(root->children[i]!=NULL)
            {
            root->isEndOfWord = false;
                return false;
            }
         }
        //  if(root->isEndOfWord)
        //  {
        //     root->isEndOfWord = false;
        //  }
         root = NULL;
         free(root);
         return true;
              
    }
    bool x = mdelete(root->children[key[depth]],key,depth+1);
    if(!x)
    {
        return false;
    }
    return true;
}

void FreeTrieRecursive(struct TrieNode* root,int depth)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if(root->children[i] == NULL)
        {
            continue;
        }
        FreeTrieRecursive(root->children[i],depth+1);
    }
    free(root);
    
}

// Driver
int main()
{
// Input keys (use only 'a' through 'z' and lower case)
char keys[][8] = {"the", "a", "there", "answer", "any",
"by", "bye", "their"};
char output[][32] = {"Not present in trie", "Present in trie"};
struct TrieNode *root = getNode();
// Construct trie
int i;
for (i = 0; i < sizeof(keys)/sizeof(keys[0]); i++)
    insert(root, keys[i]);
// Search for different keys
printf("%s --- %s\n", "the", output[search(root, "the")] );
printf("%s --- %s\n", "these", output[search(root, "these")] );
printf("%s --- %s\n", "their", output[search(root, "their")] );
printf("%s --- %s\n", "thaw", output[search(root, "thaw")] );
        // printf("YES\n");
// root = mdelete(root,"the",0);
mdelete(root,"the",0);
        // printf("YES\n");
printf("%s --- %s\n", "the", output[search(root, "the")] );

FreeTrieRecursive(root,0);
// printf("%s --- %s\n", "the", output[search(root, "their")] );

return 0;
}
// int main()
// {
//     FILE* fp;
//     fp = fopen("names1000.csv","r");
//     char s[100];
//     struct TrieNode * root = getNode(); 
//     while(fgets(s,100,fp))
//     {
    
//         insert(root,s);
//         // printf("%d",(int)s[strlen(s)-1]);
//     }
// char output[][32] = {"Not present in trie", "Present in trie"};
// printf("%s --- %s\n", "Levi Maier", output[search(root, "Levi Maier\r\n")] );
// root = delete(root,"Levi Maier\r\n",0);
// printf("%s --- %s\n", "Levi Maier", output[search(root, "Levi Maier\r\n")] );
//     fclose(fp);


// }