/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeZeroSumSublists(struct ListNode* head) {
    struct ListNode *temp = head, *temp2 = head, *temp3 = head;
    int i = 0, b = 0,c = 0,m;
    while (temp != NULL) {
        temp = temp->next;
        i++;
    }
    int a[i], k = 0, j;
    while (temp2 != NULL) {
        a[k++] = temp2->val;
        temp2 = temp2->next;
    }
    c=0;
    for (i = 0; i < k; i++) {
        c=a[i];
        for (j = i+1; j < k; j++) {
           c+=a[j];
           if(c==0)
           {
             for(m=i;m<=j;m++)
             {
                a[m]=0;
             }
           }
        }
    }
    j = 0;
    for (i = 0; i < k; i++) {
        // printf("%d ", a[i]);
        if (a[i] != 0) {
            j++;
        }
    }
    if(j==0)return NULL;
    int arr[j];
    for (i = 0; i < k; i++) {
        if (a[i] != 0) {
            arr[b++] = a[i];
        }
    }
    j = 0;
    while (temp3!=NULL) {
      temp3->val = arr[j++];
        if (j == b) {
            temp3->next = NULL;
            break;
        }
        temp3 = temp3->next;
    }
    return head;
}