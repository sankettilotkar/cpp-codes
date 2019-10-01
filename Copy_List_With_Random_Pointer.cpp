/*
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or NULL.

Return a deep copy of the list.

Example

Given list

   1 -> 2 -> 3
with random pointers going from

  1 -> 3
  2 -> 1
  3 -> 1
You should return a deep copy of the list. The returned answer should not contain the same node as the original list, but a copy of them. The pointers in the returned list should not link to any node in the original input list.
*/

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    RandomListNode * head=NULL , *cur=A,* cur_a=NULL ,*next;
    while(cur){
        if(head==NULL){
            head=new RandomListNode(cur->label);
            cur_a=head;
        }else{
            cur_a->next=new RandomListNode(cur->label);
            cur_a=cur_a->next;
        }
        cur_a->random=cur;
        cur=cur->next;
    }
    cur=A;
    cur_a=head;
    while(cur){
        next=cur->next;
        cur->next=cur_a;
        cur_a=cur_a->next;
        cur=next;
    }
    cur_a=head;
    while(cur_a){
        cur_a->random=cur_a->random->random?cur_a->random->random->next:NULL;
        cur_a=cur_a->next;
    }
    return head;
}

