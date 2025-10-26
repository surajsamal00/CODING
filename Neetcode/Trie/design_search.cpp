#include <bits/stdc++.h>
using namespace std;
// 211. Design Add and Search Words Data Structure
// https://leetcode.com/problems/design-add-and-search-words-data-structure/
struct TrieNode {
    bool isEnd = false;
    TrieNode* child[26] = {nullptr};
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode;
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for(auto c : word) {
            if(curr->child[c - 'a'] == nullptr) {
                curr->child[c - 'a'] = new TrieNode;
            }
            curr = curr->child[c - 'a'];
        }
        curr->isEnd = true;
    }
    
    /*
    The edge case when the word ends with a '.' if so additionally
    we need to check the '.' candidate whatever letter it might be, also is 
    a terminal letter as well.
    */
    bool func(int i, TrieNode* curr, string& word) {
        if(i == word.size()) return true;
        for(i; i < word.size(); i++) {
            char c = word[i];
            if(c == '.') {
                for(int j = 0; j < 26; j++) {
                    if(curr->child[j] != nullptr && func(i + 1, curr->child[j], word)) {
                        if(i == word.size() - 1 && curr->child[j]->isEnd) {
                            return true;
                        }
                        else if(i != word.size() - 1) {
                            return true;
                        }
                    }
                }
                return false;
            }
            else {
                if(curr->child[c - 'a'] == nullptr) {
                    return false;
                }
                curr = curr->child[c - 'a'];
            }
        }
        return (curr->isEnd == true);
    }
    bool search(string word) {
        TrieNode* curr = root;
        return func(0, curr, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */