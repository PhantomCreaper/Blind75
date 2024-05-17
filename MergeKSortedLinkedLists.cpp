// 23. Merge K Sorted linked lists
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
    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return nullptr;
        }
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        for(auto list:lists){
            if(list) pq.push(list);
        }

        ListNode* dummy = new ListNode();
        ListNode* current = dummy;

        while(!pq.empty()){
            ListNode* node = pq.top();
            pq.pop();
            current->next = node;
            current = current->next;
            if(node->next) pq.push(node->next);
        }
        return dummy->next;
    }
};
