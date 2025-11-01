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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        map<int,int> mg;
        ListNode *temp = head, *prv = NULL;
        for(int i = 0; i < nums.size(); i++)mg[nums[i]]++;
        while(temp){
            if(mg[temp->val]){
                if(!prv){
                    head = temp->next;
                    temp = temp->next;
                }
                else{
                    prv->next = temp->next;
                    temp = temp->next;
                }
            }
            else {
                prv = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};