class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next == NULL)
            return head;
        ListNode* node = head->next;
        head->next = swapPairs(node->next);
        node->next=head;
        return node;
    }
};