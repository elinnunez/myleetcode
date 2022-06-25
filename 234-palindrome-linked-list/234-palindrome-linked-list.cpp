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
    int getLength(ListNode* head) {
        int size = 0;
        
        ListNode* cur = head;
        
        while(cur != nullptr) {
            size+=1;
            cur = cur->next;
        }
        
        return size;
    }
    
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) {
            return true;
        }
        
        int size = getLength(head);
        
        stack<int> firstHalf;
        
        ListNode* cur = head;
        
        int count = 0;
        while(count < size/2) {
            firstHalf.push(cur->val);
            cur = cur->next;
            count++;
        }
        
        if(size % 2 == 1) {
            cur = cur->next;
        }
        
        while(count > 0) {
            if(firstHalf.top() != cur->val) {
                return false;
            }
            firstHalf.pop();
            cur = cur->next;
            count--;
        }
        
        return true;
    }
};