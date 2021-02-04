/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        //floyd
        ListNode *slow = head, *fast = head;
        while(slow && fast && fast->next){
            slow=slow->next;
            fast = fast->next->next;
            // cout<<slow->val<<" "<<fast->val<<endl;
            if(slow==fast){
                while(head!=slow){
                    head=head->next;
                    slow=slow->next;
                }
                return head;
            }
        }
        return NULL;
    }
};