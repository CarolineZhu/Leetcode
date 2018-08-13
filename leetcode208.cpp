#include <iostream>
#include <vector>

using namespace std;

class Trie {
public:
    struct Node
     {
        Node* next[26];
        bool isend;
     }; 
    /** Initialize your data structure here. */
    Node* T;
    Trie() {
        T = new Node();
        for (int i = 0; i < 26; i++)
            T -> next[i] = NULL;
        T -> isend = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* pre = T;
        for (int i = 0; i < word.length(); i++) {
            if (pre -> next[word[i] - 'a']) {
                pre = pre -> next[word[i] - 'a'];
            } else {
                Node* n = new Node();
                pre -> next[word[i] - 'a'] = n;
                pre = n;
            }
        }
        pre -> isend = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* p = T;
        for (int i = 0; i < word.length(); i++) {
            if (p -> next[word[i] - 'a'] == NULL) return false;
            else p = p -> next[word[i] - 'a'];
        }
        if (p -> isend) return true;
        else return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* p = T;
        for (int i = 0; i < prefix.length(); i++) {
            if (p -> next[prefix[i] - 'a'] == NULL) return false;
            else p = p -> next[prefix[i] - 'a'];
        }
        return true;
    }
};