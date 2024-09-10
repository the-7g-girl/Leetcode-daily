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
    int gcd(int a, int b){
        if(a<b) swap(a,b);
        int r;
        while(a%b!=0){
            r=a%b;
            a=b;
            b=r;
        }
        return b;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* a=head;
        ListNode* b=head->next;
        while(b!=NULL){
            int g=gcd(a->val,b->val);
            ListNode* temp=new ListNode(g);
            a->next=temp;
            temp->next=b;
            a=b;
            b=b->next;
        }
        return head;
    }
};