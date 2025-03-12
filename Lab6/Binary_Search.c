#include <stdio.h>
#include <stdlib.h>
struct BST{
    int data;
    struct BST *left;
    struct BST *right;
};
void inorder(struct BST *root)
{
    if (root != NULL)
    {
        inorder(root -> left);
        printf("%d ", root->data);
        inorder(root -> right);
    }
}
void preorder(struct BST *root)
{
    if (root != NULL)
    {
        printf("%d ",root -> data);
        preorder(root->left);
        preorder(root -> right);
    }
}
void postorder(struct BST *root)
{
    if (root != NULL)
    {
        postorder(root -> left);
        preorder(root->right);
        printf("%d ", root -> data);
    }
}
struct BST* search(struct BST *root, int key){
    if (root == NULL || key == root -> data)
        return root;
    else if (key < root -> data)
        return search(root ->left, key);
    else
    return search(root -> right, key);
}
struct BST* findMax(struct BST *root)
{
    while(root-> right != NULL)
        root = root -> right;
        return root;
}
struct BST* findMin(struct BST *root)
{
    while(root-> left != NULL)
    root = root -> left;
    return root;
}
struct BST* insert(struct BST *root, int element)
{
    if(root == NULL)
    {
        root = (struct BST*)malloc(sizeof(struct BST));
        root -> left = NULL;
        root -> right = NULL;
        root -> data = element;
    }
    else if(element < root->data)
    {
        root->left = insert(root->left, element);
    }
    else
    {
        root->right = insert(root->right, element);
    }
    return root;
}
struct BST* deleteNode(struct BST *root, int element)
{
    if(root == NULL)
        return root;
    else if (element < root->data)    
        root->left = deleteNode(root->left, element);
    else
    {
        if (root ->left == NULL)
        {
            struct BST *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct BST *temp = root->left;
            free(root);
            return temp;
        }
        //CASE 3
        else
        {
            struct BST *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}
int main()
{
    struct BST *root = NULL, *temp=NULL;
    int choice, element;
    while(1)
    {
        printf("1.Insert\n2.Delete\n3.Search\n");
        printf("4.Find Max\n5.Find Min\n");
        printf("6.Inorder\n7.Preorder\n8.Postorder\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Element: ");
                scanf("%d", &element);
                root = insert(root, element);
                printf("%d INSERTED\n\n", element);
                break;
            case 2:
                printf("Element: ");
                scanf("%d", &element);
                root = deleteNode(root,element);
                break;
            case 3:
                printf("Element: ");
                scanf("%d", &element);
                temp = search(root,element);
                if(temp)
                    printf("%d FOUND\n", temp->data);
                else
                    printf("SEARCH UNSUCCESSFUL\n");
                break;
            case 4:
                temp = findMax(root);
                if(temp)
                    printf("%d is MAXIMUM\n", temp->data);
                else
                    printf("EMPTY TREE \n");
                break;
            case 5:
                temp = findMin(root);
                if(temp)
                    printf("%d is MINIMUM\n", temp->data);
                else
                    printf("EMPTY TREE \n");
                break;
            case 6:
                inorder(root);
                printf("\n ");
                break;
            case 7:
                preorder(root);
                printf("\n ");
                break;
            case 8:
                postorder(root);
                printf("\n ");
                break;
        }
    }
    return 0;
}