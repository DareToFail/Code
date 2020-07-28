/*Given a singly linked list of N nodes. The task is to find middle of the linked list. For example, if given linked list is 1->2->3->4->5 then 
output should be 3.If there are even nodes, then there would be two middle nodes, we need to print second middle element. For example, if given linked 
list is 1->2->3->4->5->6 then output should be 4.
Input:
First line of input contains number of testcases T. For each testcase, first line of input contains length of linked list and next line contains data of 
nodes of linked list.
Output:
For each testcase, there will be a single line of output containing data of middle element of linked list.
User Task:
The task is to complete the function getMiddle() which takes head reference as the only argument and should return the data at the middle node of linked list.*/
struct Node {
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
int getMiddle(Node *head)
{
   // Your code here
   Node *slow=head,*fast=head;
   while(fast->next !=NULL){
       if(fast->next->next== NULL){
           slow = slow->next;
           break;
       }
       else{
           slow = slow->next;
           fast = fast->next->next;
       }
   }
   return slow->data;
}
