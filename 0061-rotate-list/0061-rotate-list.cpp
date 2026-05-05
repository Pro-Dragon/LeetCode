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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        ListNode *ptr = head, *fast = head, *prv;
        int n = 0, ptr1 = 0, ptr2 = 0;
        while(fast && fast->next) {
            fast = fast->next->next;
            n += 2;
        }
        if(fast) n++;
        k %= n;
        fast = head;
        while(k--) ptr = ptr->next;
        while(ptr->next) {
            fast = fast->next;
            ptr = ptr->next;
        }
        ptr->next = head;
        ptr = fast->next;
        fast->next = NULL;
        return ptr;
    }
};