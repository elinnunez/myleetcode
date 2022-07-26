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
    bool hasCycle(ListNode *head) {
        
        //if head is empty or the next node is nullptr, not a cycle
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }
        
        ListNode *walker = head;
        ListNode *runner = head;
        
        while (runner != nullptr)
        {
            //if runner points at nullptr, not a linked list cycle
            if (runner->next == nullptr)
            {
                return false;
            }

            //runner goes twice as far twice as fast
            runner = runner->next->next;
            walker = walker->next;

            //if at some point, runner outlaps walker and they are equal, this means that the list loops
            if (runner == walker)
            {
                return true;
            }
        }
        //only returns false if runner gets to a nullptr meaning not a ll cycle
        return false;
    }
};