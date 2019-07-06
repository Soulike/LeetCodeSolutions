/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (38.53%)
 * Likes:    1650
 * Dislikes: 34
 * Total Accepted:    185.4K
 * Total Submissions: 474.1K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Example:
 * 
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");   
 * trie.search("app");     // returns true
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 * 
 * 
 */
#include <string>
#include <vector>

using namespace std;

class Node
{
private:
    char c; // '\0' 代表分割符，代表两个单词的间隔或末尾
    vector<Node *> children;

public:
    static const char SEPRATOR = '\0';

    Node(char c)
    {
        this->c = c;
    }

    ~Node() 
    {
        for(Node* child : children)
        {
            delete child;
        }
    }

    char getChar() const
    {
        return c;
    }

    // 找不到时返回 NULL
    Node *getChildrenWithChar(char c) const
    {
        for (Node *node : children)
        {
            if (node->c == c)
            {
                return node;
            }
        }
        return NULL;
    }

    Node* addChildren(char c)
    {
        Node *newNode = new Node(c);
        children.push_back(newNode);
        return newNode;
    }

    const vector<Node *> &getChildren() const
    {
        return this->children;
    }
};

class Trie
{
private:
    Node *root;

public:
    /** Initialize your data structure here. */
    Trie()
    {
        root = new Node(Node::SEPRATOR);
    }

    ~Trie()
    {
        delete root;
    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        Node *currentNode = root;
        Node *nextNode = NULL;
        for (char c : word)
        {
            nextNode = currentNode->getChildrenWithChar(c);
            if (nextNode == NULL)
            {
                currentNode = currentNode->addChildren(c);
            }
            else
            {
                currentNode = nextNode;
            }
        }

        currentNode->addChildren(Node::SEPRATOR);
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        Node *currentNode = root;
        Node *nextNode = NULL;
        for (char c : word)
        {
            nextNode = currentNode->getChildrenWithChar(c);
            if (nextNode == NULL)
            {
                return false;
            }
            else
            {
                currentNode = nextNode;
            }
        }

        return currentNode->getChildrenWithChar(Node::SEPRATOR) != NULL;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        Node *currentNode = root;
        Node *nextNode = NULL;
        for (char c : prefix)
        {
            nextNode = currentNode->getChildrenWithChar(c);
            if (nextNode == NULL)
            {
                return false;
            }
            else
            {
                currentNode = nextNode;
            }
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
