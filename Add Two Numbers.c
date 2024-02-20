/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {


    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode)); 

    struct ListNode* head = dummy; 

    struct ListNode* tail = dummy; 

    int carry = 0; 

  

    while (l1 != NULL || l2 != NULL || carry != 0) { 

        int digit1 = (l1 != NULL) ? l1->val : 0; 

        int digit2 = (l2 != NULL) ? l2->val : 0; 

        int sum = digit1 + digit2 + carry; 

        int digit = sum % 10; // calculates unit of digit 

        carry = sum / 10; 

  

        struct ListNode* res = (struct ListNode*)malloc(sizeof(struct ListNode)); 

        res->val = digit; 

        res->next = NULL; 

        tail->next = res; 

        tail = tail->next; 

  

        l1 = (l1 != NULL) ? l1->next : NULL; 

        l2 = (l2 != NULL) ? l2->next : NULL; 

    } 


    head = dummy->next; 

    free(dummy); 

    return head; 
