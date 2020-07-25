#include<stdio.h>

/*
16bit111
AVL tree
*/
#include<stdlib.h>
struct sNode{
    int iKey,iHeight;
    struct sNode *sLeft,*sRight;
};
struct sNode *spRoot1 = NULL;
struct sNode *spRoot2 = NULL;

struct sNode *newNode(int iNum)
{
    struct sNode *pTemp =  (struct sNode *)malloc(sizeof(struct sNode));
    pTemp->iKey = iNum;
    pTemp->iHeight=1;
    pTemp->sLeft = pTemp->sRight = NULL;
    return pTemp;
}


void BST_preorder(struct sNode *root){
    if(root!=NULL){
        printf("%d   ",root->iKey);
        BST_preorder(root->sLeft);
        BST_preorder(root->sRight);
    }
}
void BST_postorder(struct sNode *root){
    if(root!=NULL){
        BST_postorder(root->sLeft);
        BST_postorder(root->sRight);
        printf("%d   ",root->iKey);
    }
}
void BST_inorder(struct sNode *root)
{
    if (root != NULL)
    {
        BST_inorder(root->sLeft);
        printf("%d   ", root->iKey);
        BST_inorder(root->sRight);
    }
}
struct Node *rightRotate(struct sNode *sNodey)
{
    struct sNode *sNodex = sNodey->sLeft;
    struct sNode *T2 = sNodex->sRight;

    sNodex->sRight = sNodey;               // Perform rotation
    sNodey->sLeft = T2;

    sNodey->iHeight = max(height(sNodey->sLeft), height(sNodey->sRight))+1;
    sNodex->iHeight = max(height(sNodex->sLeft), height(sNodex->sRight))+1;

    return sNodex;
}

struct Node *leftRotate(struct sNode *sNodex)
{
    struct sNode *sNodey = sNodex->sRight;
    struct sNode *T2 = sNodey->sLeft;

    sNodey->sLeft = sNodex;
    sNodex->sRight = T2;

    sNodex->iHeight = max(height(sNodex->sLeft), height(sNodex->sRight))+1;
    sNodey->iHeight = max(height(sNodey->sLeft), height(sNodey->sRight))+1;

    return sNodey;
}

int getBalance(struct Node *s1pNode)
{
    struct sNode *spNode=s1pNode;
    if (spNode == NULL)
        return 0;
    return (height(spNode->sLeft) - height(spNode->sRight));
}

int max(int iIndexa, int iIndexb)
{
    if(iIndexa>iIndexb)
        return iIndexa;
    else
       return iIndexb;
}
int height(struct sNode *sNew)
{
    if (sNew == NULL)
        return 0;
    return sNew->iHeight;
}

struct sNode * minValueNode(struct sNode* node)
{
    struct sNode* current = node;
    while (current->sLeft != NULL)
        current = current->sLeft;
    return current;
}

struct sNode* insert(struct sNode* spTemp, int key)
{
    if (spTemp == NULL)
        return(newNode(key));

    if (key < spTemp->iKey)
        spTemp->sLeft  = insert(spTemp->sLeft, key);

    else if (key > spTemp->iKey)
        spTemp->sRight = insert(spTemp->sRight, key);

    else
        return spTemp;

    spTemp->iHeight = 1 + max(height(spTemp->sLeft),height(spTemp->sRight));

    int balance = getBalance(spTemp);

    if (balance > 1 && key < spTemp->sLeft->iKey)       //LL
        return rightRotate(spTemp);
    if (balance < -1 && key > spTemp->sRight->iKey)     //RR
        return leftRotate(spTemp);
    if (balance > 1 && key > spTemp->sLeft->iKey)       //Lr
    {
        spTemp->sLeft =  leftRotate(spTemp->sLeft);
        return rightRotate(spTemp);
    }
    if (balance < -1 && key < spTemp->sRight->iKey)     //Rl
    {
        spTemp->sRight = rightRotate(spTemp->sRight);
        return leftRotate(spTemp);
    }
    return spTemp;
}

struct sNode* deleteNode(struct sNode* root, int key)
{
    if (root == NULL)
        return root;
    if ( key < root->iKey )
        root->sLeft = deleteNode(root->sLeft, key);
    else if( key > root->iKey )
        root->sRight = deleteNode(root->sRight, key);
    else
    {
        if( (root->sLeft == NULL) || (root->sRight == NULL) )
        {
            struct sNode *temp = root->sLeft ? root->sLeft : root->sRight;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
             *root = *temp;
            free(temp);
        }
        else
        {
            struct sNode* temp = minValueNode(root->sRight);
            root->iKey = temp->iKey;
            root->sRight = deleteNode(root->sRight, temp->iKey);
        }
    }
    if (root == NULL)
      return root;
    root->iHeight = 1 + max(height(root->sLeft),
                           height(root->sRight));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->sLeft) >= 0)
        return rightRotate(root);
    if (balance > 1 && getBalance(root->sLeft) < 0)
    {
        root->sLeft =  leftRotate(root->sLeft);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->sRight) <= 0)
        return leftRotate(root);
    if (balance < -1 && getBalance(root->sRight) > 0)
    {
        root->sRight = rightRotate(root->sRight);
        return leftRotate(root);
    }
    return root;
}

int check(struct sNode *sRoot,int iNum)
{
    struct sNode* spTemp=sRoot;

    while(spTemp->sLeft!=NULL || spTemp->sRight!=NULL)
    {

        if(iNum==spTemp->iKey)
            return 0;

        else if(iNum<spTemp->iKey)
        {
            if(spTemp->sLeft==NULL)
                return 1;

            spTemp=spTemp->sLeft;
        }
        else if(iNum>spTemp->iKey)
        {
            if(spTemp->sRight==NULL)
                return 1;

            spTemp=spTemp->sRight;
        }
    }
    if(iNum==spTemp->iKey)
        return 0;

    return 1;
}

void inorder(struct sNode *root,int iIndexy)
                    {
                        if (root != NULL)
                        {
                            inorder(root->sLeft,iIndexy);
                            if(root->iKey<=iIndexy)
                                spRoot1 = insert(spRoot1, root->iKey);
                            else
                                spRoot2 = insert(spRoot2, root->iKey);
                                inorder(root->sRight,iIndexy);
                        }
                    }
int main()
{
  struct sNode *spRoot = NULL;

  int iIndex,iSize,iIndexy,iChoice,iNum,iTemp;



   while(1)
    {
        printf("\n1.Insert \n2.Inorder traversal \n3.Preorder Traversal\n4.Postorder Traversal\n5.Delete Element\n6.Split tree\n7.Exit\n");
        scanf("%d",&iChoice);

        switch(iChoice)
        {
            case 1:
                printf("\nEnter Number to be Inserted:-\n");
                scanf("%d",&iNum);
                spRoot=insert(spRoot,iNum);
                break;
            case 2:
                if(spRoot==NULL){
                    printf("Tree Empty");
                }
                else{
                    printf("\nInorder traversal:\n");
                    printf("ROOT Element: %d\n",spRoot->iKey);
                    BST_inorder(spRoot);
                }

                break;
            case 3:
                if(spRoot==NULL){
                    printf("Tree Empty");
                }
                else{
                printf("\nPreorder traversal\n");
                printf("ROOT Element: %d\n",spRoot->iKey);
                BST_preorder(spRoot);
                }
                break;
            case 4:
                if(spRoot==NULL){
                    printf("Tree Empty");
                }
                else{
                printf("\nPostorder traversal\n");
                printf("ROOT Element: %d\n",spRoot->iKey);
                BST_postorder(spRoot);
                }
                break;
            case 5:
                if(spRoot==NULL){
                    printf("Binary Search tree Empty\n");
                    break;
                }
                printf("\nEnter element to be deleted:\n");
                scanf("%d",&iNum);
                iTemp=check(spRoot,iNum);
                if(iTemp==1){
                    printf("Node Not Found\n");
                }
                else{
                    printf("Element deleted: %d\n",iNum);
                    spRoot=deleteNode(spRoot,iNum);
                }

                break;
            case 6:
                spRoot1=NULL;
                spRoot2=NULL;
                if(spRoot==NULL){
                    printf("Tree Empty Cannot Split tree\n");
                    break;
                }
                printf("\nEnter the splitting value: \n");
                scanf("%d",&iIndexy);
                iIndex=check(spRoot,iIndexy);
                if(iIndex==1)
                    printf("Element not found cannot split tree");

                else{
                        inorder(spRoot,iIndexy);
                        printf("\nPreorder traversal of the constructed AVL tree 1 is \n ");
                        BST_preorder(spRoot1);
                        printf("\nInorder traversal of the constructed AVL tree 1 is \n");
                        BST_inorder(spRoot1);
                        printf("\nPostorder traversal of the constructed AVL tree 1 is \n");
                        BST_postorder(spRoot1);

                        printf("\n");
                         printf("\nPreorder traversal of the constructed AVL tree 2 is \n ");
                        BST_preorder(spRoot2);
                        printf("\nInorder traversal of the constructed AVL tree 2 is \n");
                        BST_inorder(spRoot2);
                        printf("\nPostorder traversal of the constructed AVL tree 2 is \n");
                        BST_postorder(spRoot2);

                }
                break;

            case 7:
                return 0;
            default:
                printf("Enter Proper Choice\n");

        }
    }


    return 0;
}

