#include <bits/stdc++.h>
using namespace std;


// 208. Implement Trie (Prefix Tree)
// https://leetcode.com/problems/implement-trie-prefix-tree/description/

/*
Basically dictionary as a tree where letters are nodes and each 
node like has two attributes 
a) whether word/words end at this node and
b) what is the next letter/letters available stored as nodes in child vectors.  

*/
struct TrieNode {
    bool isEnd = false;
    vector<TrieNode*> child = vector<TrieNode*>(26, nullptr);
    // can not construct inside class or struct only declare
    // or use = vector... 
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode;
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++) {
            char c = word[i];
            if(curr->child[c - 'a'] == nullptr) {
                curr->child[c - 'a'] = new TrieNode;
            }
            curr = curr->child[c - 'a'];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        for(int i = 0; i < word.size(); i++) {
            char c = word[i];
            if(curr->child[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->child[c-'a'];
        }
        return (curr->isEnd == true);
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for(int i = 0; i < prefix.size(); i++) {
            char c = prefix[i];
            if(curr->child[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->child[c-'a'];
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