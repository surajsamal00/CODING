#include <bits/stdc++.h>
using namespace std;

/*
1. postorder traversal dfs stack
2. reverse all edges
3. dfs from unvisited nodes (top to bottom) of stack each dfs is one component 
*/

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void dfs(int node, vector<bool> &explored, vector<vector<int>> &adj, stack<int> &s){
	    explored[node]=true;
	    
	    for(auto nbr:adj[node]){
	        if(!explored[nbr]){
	            dfs(nbr,explored,adj,s);
	        }
	    }
	    
	    s.push(node);
	}
	
	void dfs_scc(int node,vector<bool> &explored, vector<vector<int>> &transpose,vector<int> &a){
	    
	    explored[node]=true;
	    a.push_back(node);
	    for(auto nbr:transpose[node]){
	        if(!explored[nbr]){
	            dfs_scc(nbr,explored,transpose,a);
	        }
	    }
	}

    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //step 1 create stack with topological sort
        stack<int> s;
        
        vector<bool> explored(V,false);
        
        for(int i=0;i<V;i++){
            if(!explored[i]){
                
                dfs(i,explored,adj,s);
            }
        }

        

        
        vector<vector<int>> transpose(V);
        for(int i=0;i<V;i++)
        {   
            explored[i]=false;
            for(auto j:adj[i]){
                transpose[j].push_back(i);
            }
        }
        int count=0;
        vector<vector<int>> ans;
        while(!s.empty())
        {
            int node=s.top();
            s.pop();
            
            if(!explored[node]){
                count++;
                vector<int> a;
                dfs_scc(node,explored,transpose,a);
                
                ans.push_back(a);
            }
        }
        
        return count;
    }
};

int main(){
    return 0;
}