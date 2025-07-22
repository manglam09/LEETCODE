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
    ListNode* reverse(ListNode* head){
      ListNode* curr=head;
      ListNode* prev=nullptr;
      while(curr!=nullptr){
        ListNode* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
      }
      return prev;
    }
      void push_back(ListNode* &head, int digit) {
        ListNode* newnode = new ListNode(digit);
        if (head == nullptr) {
            head=newnode; 
        } else {
            ListNode* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newnode; 
            
        }
    }
public:
    ListNode* add(ListNode* l1,ListNode* l2){
        ListNode* first=l1;
        ListNode* second=l2;
        ListNode* ans=nullptr;
        int carry=0;
        while(first!=nullptr&&second!=nullptr){
            int digit=first->val+second->val+carry;
            int sum=digit%10;
            carry=digit/10;
            push_back(ans,sum);
            first=first->next;
            second=second->next;
        }
        while(first!=nullptr){
            int digit=first->val+carry;
            int sum=digit%10;
            carry=digit/10;
            push_back(ans,sum);
            first=first->next;
        }
        while(second!=nullptr){
            int digit=second->val+carry;
            int sum=digit%10;
            carry=digit/10;
            push_back(ans,sum);
            second=second->next;
        }
        while(carry!=0){
            int digit=carry;
            int sum=digit%10;
            carry=digit/10;
            push_back(ans,sum);
            
        }
        return ans;
    }
    ListNode* addTwoNumbers(ListNode* first,ListNode* second)
    {
        
        ListNode* ans=add(first,second);
        return ans;
    }
};