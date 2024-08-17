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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *temp1 = l1;
    ListNode *temp2 = l2;
    ListNode *head = NULL;
    ListNode *tail = NULL;
    int carry =0;    
    int r;
    while(temp1 != NULL && temp2 != NULL){
        r = temp1->val + temp2->val +carry;
        carry = r/10;
        r = r%10;
        ListNode *node = new ListNode(r);
        if(head == NULL){
            head = node;
            tail = head;
        }
        else{
            tail ->next = node;
            tail = node;
        }
        temp1 = temp1 -> next ;
        temp2 = temp2 -> next;
    }
    while(temp1 != NULL){
        r = temp1 -> val + carry;
        carry = r/10;
        r = r%10;
        ListNode *node = new ListNode(r);
        tail -> next = node;
        tail = node;
        temp1 = temp1 -> next;      
    }
    while(temp2 != NULL){
        r = temp2 -> val + carry;
        carry = r/10;
        r = r%10;
        ListNode *node = new ListNode(r);
        tail -> next = node;
        tail = node;
        temp2 = temp2 -> next;      
    }
    if(carry!=0){
        ListNode *node = new ListNode(carry);
        tail->next = node;
        tail = node;
    }
    return head;
    }   
};
