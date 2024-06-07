class Solution {

public:
    string replaceWords(vector<string>& dictionary, string s) {
        string ans="";
        string word="";
        unordered_set<string> dictSet;
        for(int i=0;i<dictionary.size();i++){
            dictSet.insert(dictionary[i]);
        }
        for(int i=0;i<s.size();i++){
            if(s[i]!=' ') word=word+s[i];
            else {
                if(word!="") {
                    ans=ans+makeroot(word,dictSet)+" ";
                    word="";
                }
            }
        }
        if(word!="") {
                    ans=ans+makeroot(word,dictSet)+" ";
                    word="";
                }
        ans.pop_back();
        return ans;
        }
private:
    string makeroot(string word,unordered_set<string> dictSet){
        for(int i=1;i<=word.size();i++){
            string root=word.substr(0,i);
            if (dictSet.contains(root)) {
                return root;
            }
            }
            return word;
        }
    

    

    
};