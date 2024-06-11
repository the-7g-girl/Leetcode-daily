class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map <int,int> mp;
        for(int i=0;i<arr1.size();i++){
            mp[arr1[i]]++;
        }
        int ptr=0;
        for(int i=0;i<arr2.size();i++){
            while(mp[arr2[i]]){
                arr1[ptr]=arr2[i];
                mp[arr2[i]]--;
                ptr++;
            }
        }
        int key=ptr;
        for(auto it:mp){
            while(it.second){
                arr1[ptr]=it.first;
                it.second--;
                ptr++;
            }
        }
        sort(arr1.begin()+key, arr1.end());
        return arr1;
    }
};