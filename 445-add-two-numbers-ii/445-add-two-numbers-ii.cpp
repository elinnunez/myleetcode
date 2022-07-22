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
        stack<int> stk1;
        stack<int> stk2;
        stack<ListNode*> finalStk;
        
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        
        while(l1 || l2) {
            if(l1) {
                stk1.push(l1->val);
                l1 = l1->next;
            }
            
            if(l2) {
                stk2.push(l2->val);
                l2 = l2->next;
            }
        }
        
        int carry = 0;
        
        while(!stk1.empty() || !stk2.empty() || carry != 0) {
            ListNode* temp = new ListNode();
            int x = 0;
            int y = 0;
            
            if(!stk1.empty() && !stk2.empty()) {
                x = stk1.top();
                y = stk2.top();
                stk1.pop();
                stk2.pop();
            } else if (!stk1.empty()) {
                x = stk1.top();
                stk1.pop();
            } else if (!stk2.empty()) {
                y = stk2.top();
                stk2.pop();
            }
            
            temp->val = (x+y+carry) % 10;
            carry = (x+y+carry) / 10;
            
            finalStk.push(temp);
        }
        
        while(!finalStk.empty()) {
            cur->next = finalStk.top();
            finalStk.pop();
            cur = cur->next;
        }
        
        return dummy->next;
        
    }
};