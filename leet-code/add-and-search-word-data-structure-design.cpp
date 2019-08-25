#include <iostream>

#include <bits/stdc++.h>

using namespace std;

class Trie
{
private:
    char val;
    bool isWordEnd;
    vector<Trie *> children;

public:
    Trie(char _val, bool _isWordEnd = false)
    {
        val = _val;
        isWordEnd = _isWordEnd;
    }

    void addWord(string word)
    {
        if (word.size() == 0)
        {
            this->isWordEnd = true;
            return;
        }

        for (int i = 0; i < this->children.size(); i++)
        {
            if (this->children[i]->val == word[0])
            {
                this->children[i]->addWord(word.substr(1));
                return;
            }
        }

        Trie *newNode = new Trie(word[0]);
        this->children.push_back(newNode);
        newNode->addWord(word.substr(1));
    }

    bool search(string word)
    {
        if (word.size() == 0 && this->isWordEnd)
            return true;

        for (int i = 0; i < this->children.size(); i++)
        {
            if (this->children[i]->val == word[0])
            {
                return this->children[i]->search(word.substr(1));
            }
            else if (word[0] == '.')
            {
                if (this->children[i]->search(word.substr(1)))
                {
                    return true;
                }
            }
        }

        return false;
    }
};

class WordDictionary
{
private:
    Trie *root;

public:
    /** Initialize your data structure here. */
    WordDictionary()
    {
        root = new Trie('#', false);
    }

    /** Adds a word into the data structure. */
    void addWord(string word)
    {
        root->addWord(word);
    }

    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word)
    {
        return root->search(word);
    }
};

int main(int argc, char const *argv[])
{
    WordDictionary *dictObj = new WordDictionary();

    while (true)
    {
        char inputType;
        cout << "type : add(a) or search(s)" << endl;
        cin >> inputType;
        if (inputType == 'a')
        {
            string word;
            cin >> word;
            dictObj->addWord(word);
        }
        else if (inputType == 's')
        {
            string word;
            cin >> word;
            cout << dictObj->search(word) << endl;
        }
    }

    return 0;
}
