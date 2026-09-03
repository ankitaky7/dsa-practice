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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* head1, ListNode* head2){
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        ListNode* t1 = head1;
        ListNode* t2 = head2;
        while(t1 != NULL && t2 != NULL){
            if(t1->val < t2->val){
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }else{
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }
        if(t1){
            temp->next = t1;
        }else{
            temp->next = t2;
        }
        return dummyNode->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* left = head;
        ListNode* mid = findMiddle(head);
        ListNode* right = mid->next;
        mid->next = NULL;
        left = sortList(left);
        right = sortList(right);
        return merge(left, right);
    }
};