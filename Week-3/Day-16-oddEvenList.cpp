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
    ListNode* oddEvenList(ListNode* head) {
        if(!head or !head->next)    return head;
        ListNode *odd = head, *even = head->next;
        ListNode *oddP = odd, *evenP = even;
        int count = 0;
        head = head->next->next;
        while(head) {
            if(count%2 == 1) {
                even->next = head;
                even = even->next;
            } else {
                odd->next = head;
                odd = odd->next;
            }
            head = head->next;
            count++;
        }
        odd->next = evenP;
        even->next = NULL;
        return oddP;
    }
};
