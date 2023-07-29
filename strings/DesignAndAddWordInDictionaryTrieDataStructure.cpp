/**
 * Design a data structure that supports adding new words and finding if a string matches any previously added string.
 *
 * Implement the WordDictionary class:
 *
 * WordDictionary() Initializes the object.
 * void addWord(word) Adds word to the data structure, it can be matched later.
 *
 * bool search(word) Returns true if there is any string in the data structure
 * that matches word or false otherwise. word may contain dots '.' where dots
 * can be matched with any letter.
 *
 */
class TrieNode
{
public:
    char ch;
    TrieNode *children[26];
    bool isTerminal;
    TrieNode(char c)
    {
        ch = c;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
class WordDictionary
{
public:
    TrieNode *root;
    WordDictionary()
    {
        root = new TrieNode('\0');
    }

    void addWordUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }
        int index = word[0] - 'a';
        TrieNode *child;
        // no element is present on that location
        if (root->children[index] == NULL)
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        else
        {
            child = root->children[index];
        }
        // substr(1) will take str from location 1 to end
        addWordUtil(child, word.substr(1));
    }
    void addWord(string word)
    {
        return addWordUtil(root, word);
    }

    bool searchUtil(TrieNode *curr, int idx, string word)
    {
        if (word.size() == idx)
        {
            return curr->isTerminal;
        }
        // . can be matched with any letter.
        if (word[idx] == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                // if any child of root is true then return true
                if (curr->children[i] && searchUtil(curr->children[i], idx + 1, word))
                    return true;
            }
        }
        else
        {
            int i = word[idx] - 'a';
            if (curr->children[i] && searchUtil(curr->children[i], idx + 1, word))
                return true;
        }
        return false;
    }
    bool search(string word)
    {
        TrieNode *curr = root;
        return searchUtil(curr, 0, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */