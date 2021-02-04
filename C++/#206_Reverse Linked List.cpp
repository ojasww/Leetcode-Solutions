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
        //iterative
        if(head==NULL) return head;
        ListNode *p=NULL, *n=head->next, *tempNext=NULL;
        if(n==NULL) return head;
        while(head!=NULL){
            tempNext = head->next;
            head->next = p;
            p = head;
            head = tempNext;
        }
        return p;
    }
};