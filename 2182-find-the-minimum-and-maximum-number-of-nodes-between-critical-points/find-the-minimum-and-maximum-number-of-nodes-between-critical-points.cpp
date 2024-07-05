/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ok,peak;
        while(head!=NULL){
            ok.push_back(head->val);
            head=head->next;
        }
        //cout<<ok.size();
        if(ok.size()<=2) return {-1,-1};
        else{
            for(int i=1;i<ok.size()-1;i++){
                if(ok[i]>ok[i-1] && ok[i]>ok[i+1]) peak.push_back(i);
                if(ok[i]<ok[i-1] && ok[i]<ok[i+1]) peak.push_back(i);
            }
            if(peak.size()<2) return {-1,-1};
            int small=INT_MAX,big;
            int k=peak.size();
            
            for(int i=0;i<peak.size()-1;i++){
                cout<<peak[i]<<endl;
                small=min(peak[i+1]-peak[i],small);
            }
            big=peak[k-1]-peak[0];
            return {small,big};
        }
    }
};