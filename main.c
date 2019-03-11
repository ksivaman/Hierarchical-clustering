#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "classify.h"

void deleteTreeNode(TreeNode* node)  
{ 
    if (node == NULL) return; 
  
    deleteTreeNode(node->left); 
    deleteTreeNode(node->right); 
    free(node->data); 
    free(node); 
}

int main(int argc, char * * argv)
{
	// check for input error
        if (argc < 2)
        {
          fprintf(stderr, "Wrong input arguments\n");
          return EXIT_FAILURE;
        }

        FILE *fptr = fopen(argv[1], "r");

        fseek(fptr, 0, SEEK_SET);

        int n, dim;
        fscanf(fptr, "%d", &n);
        fscanf(fptr, "%d", &dim);
        
        ListNode * list = NULL;

        LinkedListCreate(&list, n, dim, fptr);
        FindMin(list);
        fclose(fptr);
         
        ListNode* current = list; 
        ListNode* next; 
  
        while (current != NULL)  
        {   
          next = current->next; 
          deleteTreeNode(current->treenode);
          free(current); 
          current = next; 
        }       
}
