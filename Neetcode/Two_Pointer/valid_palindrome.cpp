#include <bits/stdc++.h>
using namespace std;

// 125. Valid Palindrome
// https://leetcode.com/problems/valid-palindrome/description/
class Solution {
public:
    bool isPalindrome(string s) {
        string res = "";
        for(auto c : s) {
            if(c >= 'a' && c <= 'z') {
                res += c;
            }
            else if(c >= '0' && c <= '9') {
                res += c;
            }
            else if(c >= 'A' && c <= 'Z') { // only trick here
                res += ((c - 'A') + 'a');
            }
        }

        int n = res.size();
        for(int i = 0; i < n/2; i++) {  
            if(res[i] != res[n - 1 - i]) { // these are kind of two pointer ig??
                return false;
            }
        }
        return true;
    }
};