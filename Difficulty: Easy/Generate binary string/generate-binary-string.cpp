//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	    void helper(vector<string> &ans, vector<int> sym, string s, int i, int n){
	        if(i == n){
	            ans.push_back(s);
	            return;
	        }
	        s[sym[i]]='0';
	        helper(ans, sym, s, i+1, n);
	        s[sym[i]]='1';
	        helper(ans, sym, s, i+1, n);
	        
	    }
		vector<string> generate_binary_string(string s)
		{
		    int n = 0;
		    vector<int> sym;
		    for(int i = 0; i < s.size(); i++) {
		        if(s[i] == '?') 
		            sym.push_back(i);
		        
		    }
		    vector<string> ans;
	        helper(ans, sym, s, 0, sym.size());
	       // sort(ans.begin(), ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string s;
	    cin >> s;
	    Solution ob;
	    vector<string> ans = ob.generate_binary_string(s);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends