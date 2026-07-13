
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode*>st;
        ListNode* curr1 = headA, *curr2 = headB;
        while(curr1){
            st.insert(curr1);
            curr1=curr1->next;
        }
        while(curr2){
            if(st.count(curr2)) return curr2;
            curr2 = curr2->next;
        }
        return NULL;
        
    }
};