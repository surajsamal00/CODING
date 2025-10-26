#include <bits/stdc++.h>
using namespace std;
// 212. Word Search II
// https://leetcode.com/problems/word-search-ii/description/
struct TrieNode {
    bool isEnd;
    TrieNode* child[26];
    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};
/*
Two ways to do this
1. Store all words in a trie by backtracking in the grid. (Too slow as to many possibilities).
2. Store all the search words in a trie and then do dfs from each cell and if the cell or
   its corresponding next cell donot match with any entry in trie prune that branch and save time
   which gets wasted if you check all possibilities in that invalid branch(case 1).
*/
class Trie {
public:
    TrieNode* root;
    Trie(){
        root = new TrieNode();
    }

    void add_word(string s) {
        TrieNode* curr = root;
        for(auto c : s) {
            if(curr->child[c - 'a'] == nullptr) {
                curr->child[c - 'a'] = new TrieNode();
            }
            curr = curr->child[c - 'a'];
        }
        curr->isEnd = true;
    }

    bool search_word(string s) {
        TrieNode* curr = root;
        for(auto c : s) {
            if(curr->child[c - 'a'] == nullptr) {
                return false;
            }
            curr = curr->child[c - 'a'];
        }
        return (curr->isEnd);
    }
};

class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;
    vector<string> ans;
    int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    Trie dict;
    void solve(int idx, string& curr, TrieNode* node, vector<vector<char>>& grid) {
        int i = idx / n;
        int j = idx % n;
        curr.push_back(grid[i][j]);
        if(node->isEnd) {
            node->isEnd = false; // can be removed but then hashmap is required to avoid duplicates.
            ans.push_back(curr);
        }
        for(int k = 0; k < 4; k++) {
            int ni = i + dir[k][0], nj = j + dir[k][1];
            if(ni >= 0 && nj >= 0 && ni < m && nj < n) {
                char c = grid[ni][nj];
                if(visited[ni][nj] == false && node->child[c - 'a'] != nullptr) {
                    visited[ni][nj] = true;
                    solve(ni*n + nj, curr,  node->child[c - 'a'], grid);
                    visited[ni][nj] = false;
                }
            }
        }
        curr.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        dict = Trie();
        visited.assign(m, vector<bool>(n, 0));
        string curr = "";
        for(auto word : words) {
            dict.add_word(word);
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                char c = board[i][j];
                if(dict.root->child[c - 'a'] != nullptr) {
                    visited[i][j] = true;
                    solve(i*n + j, curr, dict.root->child[c - 'a'],  board);
                    visited[i][j] = false;
                }
            }
        }
        return ans;
    }
};