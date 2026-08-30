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
    ListNode* sortList(ListNode* head) {
        vector<int>num;
        ListNode* temp = head;
        while(temp != NULL){
            num.push_back(temp->val);
            temp = temp->next;
        }
        sort(num.begin(), num.end());
        int i = 0;
        temp = head;
        while(temp != NULL){
            temp->val = num[i];
            i++;
            temp = temp->next;
        }
        return head;
    }
};