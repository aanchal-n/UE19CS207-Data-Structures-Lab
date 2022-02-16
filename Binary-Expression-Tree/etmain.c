#include "et.h"

int main()
{
  char postfix[100];
  int len;
  Node *root;
  int loop = 1,code;
  while(loop)
  {
    scanf("%d",&code);
    switch(code)
    {
        case 1:
            scanf("%s",postfix);
            len=strlen(postfix);
            root = createExpressionTree(postfix,len);
            break;

        case 2:
            inorder(root);
            printf("\n");
            break;

        case 3:
            Preorder(root);
            printf("\n");
            break;

        case 4:
            Postorder(root);
            printf("\n");    
            break;

        default:
            loop = 0;
            break;
        
    }
    
  }
 freeTree(root);
    return 0;
}

