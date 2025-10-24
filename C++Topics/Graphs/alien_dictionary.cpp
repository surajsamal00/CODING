#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


/*
Alien Dictionary

1.  Pairwise comparison to create edges then cycle detection then toposort order
    IF AND ONLY IF tie breaker not possible ensure |word[i]| <= |word[j]| where (i<j) else false.
    Also maintain a seen chars list.

2.  Use normal cycle detection using dfs (and post order reversal technique) but carefully
    only call dfs when(colour[i]==0 && seen[i]==1) from main (inside its fine as edge existence also verifies 
    seen existence) this check prevents inclusion of out of vocab chars.

3.  After dfs we would have an topological order (reversed already) string now go through all your words and for any character not in string order
    add it to the string (anywhere is fine as they are of undecided order).

*/
class Solution {
  public:
    int adj[26][26] = {};
    bool flg = 0;
    string order;
    void isCycle(int node, vector<int>& colour){
        colour[node] = 1;
        for(int nbr=0; nbr<26 && (!flg); nbr++){
            if(adj[node][nbr]==0 || node==nbr) continue;
            if(colour[nbr]==0){
                isCycle(nbr, colour);
            }
            else if(colour[nbr]==1){
                flg = 1;
                return;
            }
        }
        colour[node] = 2;
        order += (node + 'a');
    }
    string findOrder(vector<string> &words) {
        // code here
        string w1,w2;
        vector<int> present(26,0);
        order = "";
        for(int i=0; i<words.size(); i++){
            for(int j=i+1; j<words.size(); j++){
                w1 = words[i];
                w2 = words[j];
                
                int l=0,r=0;
                while(l<w1.size() && r<w2.size()){
                    present[w1[l]-'a'] = 1;
                    present[w2[r]-'a'] = 1;
                    if(w1[l]!=w2[r]){
                        adj[w1[l]-'a'][w2[r]-'a'] = 1;
                        break;
                    }
                    else{
                        l++;
                        r++;
                    }
                    
                }
                if(r==w2.size() && l!=w1.size()){
                    cout << "False";
                    return "";
                }
            }
        }
        
        vector<int> colour(26,0);
        for(int i=0; i<26 && !flg; i++){
            if(colour[i]==0 && present[i]){
                isCycle(i,colour);
            }
        }
        
        if(flg){
            cout << "False";
            return "";
        }
        else{
            reverse(order.begin(), order.end());
            present.assign(26,0);
            for(auto c:order){
                present[c-'a'] = 1;
            }
            for(auto word:words){
                for(auto c:word){
                    if(present[c-'a']==0){
                        present[c-'a']=1;
                        order += c;
                    }
                }
            }
            // return "edabc";  
            // return "dabce";  chars not included in graph(['e']) can be placed anywhere in topological order;
            // return "deabc";
            cout << order << endl;
            return order;
        }
        
    }
};


int main(){
    Solution obj = Solution();
    vector<string> words = {"dddc", "a," "ad", "ab", "b", "be", "cd", "cded"};
    string temp = obj.findOrder(words);
    return 0;
}