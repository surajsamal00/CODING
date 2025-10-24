#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        for(int i=0; i<strs.size(); i++){
            string word = strs[i];

            int l = 0, r = 0;
            if(word.size()==0){
                s += "# 0# -1";
                continue;
            }
            while(r<word.size()){
                if(r!=word.size()-1){
                    while(r+1<word.size() && word[r+1]==word[l]) r++;
                }
                s += "#";
                s += word[l];
                int num = r-l+1;
                s += to_string(num); 
                r++;
                l=r;
            }
            s += "# -1";
        }
        // cout << s << endl;
        return s;
    }

    vector<string> decode(string s) {
        s += '#';
        vector<string> ans;
        string word = "";
        for(int i=0; i<s.size()-1; i++){
            if(s[i]=='#'){
                i++;
                char c = s[i];
                i++;
                string cnt = "";
                while(s[i]!='#'){
                    cnt+= s[i++];
                }
                int num = stoi(cnt);
                // cout << num<< " " << c << " ";
                if(num==-1){
                    // cout << word << endl;
                    ans.push_back(word);
                    word = "";
                }
                else{
                    while(num--){
                        word+=c;
                    }
                    // cout << word << endl;
                }
                i--;
            }

        }
        return ans;
    }
};


int main(){
    Solution obj = Solution();
    vector<string> v{"we","say",":", "#-1k", "-1", "#","yes"};
    string s = obj.encode(v);

    vector<string> ans = obj.decode(s);

    for(auto a:ans){
        cout << a << " ";
    }

}