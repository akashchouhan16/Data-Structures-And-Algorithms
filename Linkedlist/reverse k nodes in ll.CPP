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
    ListNode*reverse(ListNode*head, ListNode*tail) {
        if (head == tail)
            return head;
        ListNode * temp = reverse(head->next, tail);
        ListNode*loc = head->next;
        loc->next = head;

        head->next = NULL;
        return temp;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1)
            return head;

        ListNode*templ = head;
        ListNode*tail = NULL;
        int c = 1;
        while (templ != NULL) {
            int j = k - 1;
            ListNode*temp = templ;
            while (j && temp->next != NULL) {
                temp = temp->next;
                j--;

            }
            if (temp->next == NULL && j > 0) {
                tail->next = templ;
                cout << 1;
                break;
            }

            ListNode*temp1 = temp->next;
            ListNode*temp2 = reverse(templ, temp);
            templ = temp1;
            ListNode*temp3 = temp2;
            while (temp3->next != NULL) {
                temp3 = temp3->next;
            }
            temp3->next = temp1;
            if (c != 1) {

                tail->next = temp2;
                tail = temp3;
            }
            if (c == 1) {
                head = temp2;
            }
            c++;
            tail = temp3;
        }
        return head;



    }
};