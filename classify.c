#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "classify.h"

void PrintAnswer(ListNode* head, ListNode* min1, ListNode* min2)
{
	ListNode* temp = head;
	int i;
	while(temp!=NULL)
	{
		i = 0;
		while(i < head -> treenode->dimension)
		{
			if(i == 0)
				printf("(%d, ", temp->treenode->data[i]);
			else if(i == head -> treenode->dimension-1)
				printf("%d)\n", temp->treenode->data[i]);
			else
				printf("%d, ", temp->treenode->data[i]);
			i+=1;

		}
		temp = temp->next;
    return;
	}

	i = 0;
	while(i < head -> treenode->dimension)
	{
		if(i == 0)
			printf("(%d, ", min1->treenode->data[i]);
		else if(i == head -> treenode->dimension-1)
			printf("%d) <-> ", min1->treenode->data[i]);
		else
			printf("%d, ", min1->treenode->data[i]);
		i+=1;
	}

	i = 0;
	while(i < head -> treenode->dimension)
	{
		if(i == 0)
			printf("(%d, ", min2->treenode->data[i]);
		else if(i == head -> treenode->dimension-1)
			printf("%d)\n", min2->treenode->data[i]);
		else
			printf("%d, ", min2->treenode->data[i]);
		i+=1;
	}
}

void FindMin(ListNode* head)
{
        ListNode * l1 = head;
        ListNode * l2 = head->next;
        ListNode * min1 = head;
        ListNode * min2 = head;
        int minDist = FindDist(l1->treenode, l2->treenode);
        int currDist;

        while (l1->next != NULL)
        {
          l2 = l1->next; 
          while (l2 != NULL)
          {
            currDist = FindDist(l1->treenode, l2->treenode);   
            if (currDist <= minDist)
            {
              minDist = currDist;
              int l = 0;
              while (l<(l1->treenode)->dimension)
              {
                if ((l1->treenode)->data[l] > (l2->treenode)->data[l]) 
                {
                  min1 = l2;
                  min2 = l1;
                  break;
                }
                else if ((l1->treenode)->data[l] < (l2->treenode)->data[l])
                {
                  min1 = l1;
                  min2 = l2;
                  break; 
                }
                else 
                {
                  l++;
                }          
              }             
            }
            l2 = l2->next;
          }
          l1 = l1->next;
        }

        PrintAnswer(head, min1, min2);
}

int FindDist(TreeNode* x, TreeNode* y)
{
	int sum = 0;
        int temp;
  	int lcv;
  	for (lcv=0 ;lcv< (x->dimension); lcv++)
  	{
          temp = (x->data[lcv])-(y->data[lcv]);
    	  sum+=temp*temp;
  	}
  	return sum;
}

ListNode* CreateNode(int n, int dim, int* arr)
{
        ListNode* list = malloc(sizeof(ListNode));
        TreeNode* tree = malloc(sizeof(TreeNode));
        tree->left=NULL;
        tree->right=NULL;
        tree->dimension=dim;
        tree->data = malloc(dim*sizeof(int));
        int j = 0;
        for (j=0; j<dim; j++)
        {
          tree->data[j] = arr[j]; 
        }
        list->treenode = tree;
        list->next = NULL;
        return list;       
}

void LinkedListCreate(ListNode ** head, int n, int dim, FILE* fptr)
{
        int *arr = malloc(sizeof(int)*dim);

        if (arr==NULL)
        {
           fprintf(stderr, "Error in allocating memory\n");
        }

        int index=0;
        for (index = 0; index < dim; index++)
        {
          fscanf(fptr, "%d", &arr[index]);
        }
        
        ListNode * temp = CreateNode(n, dim, arr);

        *head = temp; 

        for (int k = 0; k< n-1; k++)
        {
          for (index = 0; index < dim; index++)
          {
            fscanf(fptr, "%d", &arr[index]);
          }
          temp->next = CreateNode(n,dim,arr);
          temp = temp->next; 
        }
        free(arr);
}