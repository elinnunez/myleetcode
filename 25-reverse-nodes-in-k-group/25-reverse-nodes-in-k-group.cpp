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
    ListNode* getKth(ListNode* cur, int k) {
        while(cur != nullptr && k > 0) {
            cur = cur->next;
            k--;
        }
        return cur;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* groupPrev = dummy;
        
        while(true) {
            ListNode* kth = getKth(groupPrev,k);
            if(kth == nullptr) {
                break;
            }
            ListNode* groupNext = kth->next;
            
            // reverse group
            ListNode* prev = kth->next;
            ListNode* cur = groupPrev->next;
            
            while(cur != groupNext) {
                ListNode* temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;
            }
            
            ListNode* tmp = groupPrev->next;
            
            groupPrev->next = kth;
            groupPrev = tmp;
            
        }
        
        return dummy->next;
    }
};