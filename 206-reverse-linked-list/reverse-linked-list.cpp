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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return head;
        stack<int> st;
        while (head->next != NULL) {
            int temp = head->val;
            st.push(temp);
            head = head->next;
        }
        ListNode* copy = head;
        while (!st.empty()) {
            ListNode* temp = new ListNode(st.top());
            head->next = temp;
            head = head->next;
            st.pop();
        }
        return copy;
    }
};