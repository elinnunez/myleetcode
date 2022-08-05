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
    ListNode* reverseKGroup(ListNode* head, int k) {
        vector<int> bag;
        int count = 0;
        
        while(head != nullptr) {
            bag.push_back(head->val);
            head = head->next;
            count++;
            
            if(count % k == 0) {
                reverse(bag.begin()+count-k,bag.end());
            }
        }
        
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        
        for(int i = 0; i < bag.size(); i++) {
            ListNode* temp = new ListNode(bag[i]);
            cur->next = temp;
            cur = cur->next;
        }
        
        return dummy->next;
    }
};