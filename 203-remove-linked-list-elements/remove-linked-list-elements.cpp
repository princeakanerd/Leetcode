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

 void f(ListNode* &head, int target){
    if( head == nullptr || head->next == nullptr){
        return ;
    }
    if(head -> next -> val == target ){
        head-> next = head -> next -> next ;
        f(head , target) ;
    } else{
        f(head->next , target) ;
    }

    

 }
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        int target = val ;

        while(head != nullptr && head ->val == target ) head = head -> next ;
        if(head == nullptr){
            return nullptr ;
        }

        f(head , target) ;

        return head ;

    }
};