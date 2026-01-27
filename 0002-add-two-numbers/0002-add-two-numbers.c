/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    if (!l1 && !l2)
        return l1;
    if (!l1 && l2)
        return l2;
    if (l1 && !l2)
        return l1;
    int i = 0, b = 0;
    struct ListNode *temp1 = l1, *temp2 = l2, *head = NULL, *prv = NULL;
    while (temp1 && temp2) {
        struct ListNode* Nn = (struct ListNode*)malloc(sizeof(struct ListNode));
        Nn->next = NULL;
        if (head == NULL) {
            head = Nn;
        } else {
            prv->next = Nn;
        }
        Nn->val = (temp1->val + temp2->val + b) % 10;
        b = (temp1->val + temp2->val + b) / 10;
        temp1 = temp1->next;
        temp2 = temp2->next;
        prv = Nn;
    }
    while (temp1) {
        struct ListNode* Nn = (struct ListNode*)malloc(sizeof(struct ListNode));
        Nn->next = NULL;
        prv->next = Nn;
        Nn->val = (temp1->val + b) % 10;
        b = (temp1->val + b) / 10;
        temp1 = temp1->next;
        prv = Nn;
    }
    while (temp2) {
        struct ListNode* Nn = (struct ListNode*)malloc(sizeof(struct ListNode));
        Nn->next = NULL;
        Nn->val = (temp2->val + b) % 10;
        b = (temp2->val + b) / 10;
        temp2 = temp2->next;
        prv->next = Nn;
        prv = Nn;
    }
    if(b!=0){
        struct ListNode* Nn = (struct ListNode*)malloc(sizeof(struct ListNode));
        prv->next=Nn;
        Nn->next=NULL;
        Nn->val=b;
    }
    return head;
}