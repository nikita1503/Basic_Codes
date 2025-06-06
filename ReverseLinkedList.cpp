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
  ListNode* reverseBetween(ListNode* head, int left, int right) {
      ListNode dummyNode = ListNode(0,head);

      ListNode * dummy = &dummyNode;

      ListNode * preList=dummy;
      for(int i=1;i<left;i++)preList=(preList->next);

      ListNode *start=(preList->next);
      ListNode *curr=(start->next);
      ListNode *tail = start;

      for(int i=left+1; i<=right; i++){
          (preList->next)=curr;
          (tail->next) = (curr->next);
          (curr->next)=start;
          start=curr;
          curr=(tail->next);
      }

      return (dummy->next);
  }

//Create a Node 
 ListNode node = ListNode(value,nextPointer);

//reverse from node 3 to 6 (1-indexed)
head = reverseBetween(head, 3, 6);
