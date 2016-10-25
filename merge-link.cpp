/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * 归并排序算法 
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        //ListNode* merge( ListNode *leftPtr, ListNode *rightPtr );
          
          
        if( !head || !head->next ) return head;
        else
        {
            ListNode *midPtr,  *rightPtr, *leftPtr ;
            ListNode *newHead ;
            ListNode *slowPtr, *fastPtr ;
            slowPtr = fastPtr = head ;

           //如果只有一个结点，并不会有fast->next->next
           while(  fastPtr->next && fastPtr->next->next )
            {
                slowPtr = slowPtr->next ;
                fastPtr = fastPtr->next->next ;
            }
            midPtr = slowPtr ;
            rightPtr = midPtr->next ;
            midPtr->next = NULL ;
            leftPtr = head ;  

            leftPtr = sortList( leftPtr)  ;//排左边
            rightPtr = sortList( rightPtr  ) ;//排右边
            newHead = merge(  leftPtr , rightPtr  ) ;//合并为新链表

            return newHead ;         
        }
      }
    
    
    ListNode* merge( ListNode *leftPtr, ListNode *rightPtr )
    {

        ListNode *newPtr = NULL , *newHead = NULL ;

        if( leftPtr->val < rightPtr->val )
        {
            newPtr = leftPtr ;
            leftPtr = leftPtr->next ;   
        }
        else
        {
            newPtr = rightPtr ;
            rightPtr = rightPtr->next ;
        }
        newHead = newPtr ;

        //起始的leftPtr，rightPtr一定不为空
        while( leftPtr && rightPtr )
        {
            if(  leftPtr->val < rightPtr->val  )
            {
                 newPtr->next = leftPtr ;
                 leftPtr = leftPtr->next ;
            }
            else
            {
                newPtr->next = rightPtr ;
                rightPtr = rightPtr->next ;               
            }
            newPtr = newPtr->next ;
        }

        if(  leftPtr   )//左边链表还有剩余节点
        {
            newPtr->next = leftPtr ;    
        }
        if( rightPtr )
        {
            newPtr->next = rightPtr ;
        }
        return newHead ;  
    }
    
};
