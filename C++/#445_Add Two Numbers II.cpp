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
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        stack<int> num1, num2;
        while(l1 != NULL){
            num1.push(l1->val);
            l1=l1->next;
        }
        while(l2 != NULL){
            num2.push(l2->val);
            l2=l2->next;
        }
        int carry = 0;
        stack<int> result;
        while(!num1.empty() && !num2.empty()){
            result.push((num1.top() + num2.top() + carry)%10);
            carry = (num1.top() + num2.top() + carry)/10;
            num1.pop(); num2.pop();
        }
        if(!num1.empty() && num2.empty()){
            while(!num1.empty()){
                result.push((num1.top()+carry)%10);
                carry=(num1.top()+carry)/10;
                num1.pop();
            }
        }
        else if(num1.empty() && !num2.empty()){
            while(!num2.empty()){
                result.push((num2.top()+carry)%10);
                carry=(num2.top()+carry)/10;
                num2.pop();
            }
        }
        if(carry!=0) result.push(carry);
        ListNode* first = new ListNode(result.top());
        result.pop();
        ListNode* prev = first;
        while(!result.empty()){
            ListNode* node = new ListNode(result.top()); 
            result.pop();
            prev->next = node;
            prev = node;
        }
        return first;
    }
};