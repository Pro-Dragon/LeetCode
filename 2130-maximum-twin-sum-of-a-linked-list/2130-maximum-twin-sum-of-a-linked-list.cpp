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
    int pairSum(ListNode* head) {
        int n, i = 0, maxi = 0;
        ListNode *fast = head, *temp = head, *next, *prv = NULL;
        while(fast) {
            fast = fast->next->next;
            n += 2;
        }
        cout<<n;
        fast = head;
        while(i < n / 2) {
            temp = fast;
            fast = fast->next;
            i++;
        }
        temp->next = NULL;
        while(fast) {
            next = fast->next;
            fast->next = prv;
            prv = fast;
            fast = next;
        }
        while(prv && head) {
            maxi = max(prv->val + head->val, maxi);
            prv = prv->next;
            head = head->next;
        }
        return maxi;
    }
};