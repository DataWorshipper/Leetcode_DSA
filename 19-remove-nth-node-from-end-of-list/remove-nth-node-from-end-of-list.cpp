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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL||head->next==NULL)
        {
            return NULL;
        }
        ListNode* temp=head;
        int cnt=0;
        while(temp!=NULL)
        {
            cnt++;
            temp=temp->next;

        }
        int k=cnt-n+1;
        ListNode* h=head;
        if(k==1)
        {   
            head=head->next;
            h->next=NULL;
            delete(h);
            return head;

        }

    int c=0;
    ListNode* curr=head;
    ListNode* prev=NULL;
    while(curr!=NULL)
    {
        c++;
        if(c==k)
        {
            prev->next=curr->next;
            delete(curr);
            return head;
        }
        prev=curr;
        curr=curr->next;
    }
    return NULL;
    



    }
};