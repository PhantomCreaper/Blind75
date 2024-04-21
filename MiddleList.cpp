// 876. Middle Of Linked List
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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp = head;
        int length = 0;

        while (temp != nullptr) {
            temp = temp->next;
            length++;
        }

        int middleIndex = length / 2;
        temp = head;

        while (middleIndex > 0) {
            temp = temp->next;
            middleIndex--;
        }

        return temp;
    }
};
