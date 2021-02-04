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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0) return NULL;
        ListNode* root = new ListNode(0);
        ListNode* head = root;
        priority_queue<ListNode*, vector<ListNode*>, decltype(&lambda)> pq(lambda);
        for(auto list : lists)
            if(list!=NULL)
                pq.push(list);
        if(pq.empty()) return NULL;
        while(pq.size()>1){
            ListNode* node = pq.top();
            pq.pop();
            head->next = node;
            head = head->next;
            if(node->next != NULL)
                pq.push(node->next);
        }
        head->next = pq.top();
        return root->next;
    }
    static bool lambda(const ListNode* l1,  const ListNode* l2){
        return l1->val > l2->val;
    }
};