#include <stdio.h>
#include <stdlib.h>

struct node

{

    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;
struct node *create_node(int data)

{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {

        printf("\nMemory for new node can't be allocated");
        return NULL;

    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;

}

 

void insert(int data)

{
    struct node *new_node = create_node(data);
    if (new_node != NULL)
    {
        if (root == NULL)
        {
            root = new_node;
            printf("\n* node having data %d was inserted\n", data);
            return;
        }

        struct node *temp = root;
        struct node *prev = NULL;

        while (temp != NULL)

        {
            prev = temp;
            if (data > temp->data)
            {
                temp = temp->right;
            }
           else

            {
                temp = temp->left;
            }

        }

        if (data > prev->data)

        {
            prev->right = new_node;
        }

        else

        {
            prev->left = new_node;
        }
        printf("\n* node having data %d was inserted\n", data);

    }

}

struct node *smallest_node(struct node *root)

{

    struct node *curr = root;
    while (curr != NULL && curr->left != NULL)

   {

        curr = curr->left;

    }

    return curr;

}


 struct node *delete (struct node *root, int key)

{

    if (root == NULL)
    {
        return root;
    }

    if (key < root->data)

    {
        root->left = delete (root->left, key);
    }
    else if (key > root->data)

    {
        root->right = delete (root->right, key);
    }

    else

    {

        if (root->left == NULL)

        {

            struct node *temp = root->right;
            free(root);
            return temp;

        }

        else if (root->right == NULL)

        {

            struct node *temp = root->left;

            free(root);

            return temp;

        }

        struct node *temp = smallest_node(root->right);

        root->data = temp->data;

        root->right = delete (root->right, temp->data);

    }

    return root;

 

}

 



int search(int key)

{

    struct node *temp = root;

 

    while (temp != NULL)

    {

        if (key == temp->data)

       {
            return 1;
        }
        else if (key > temp->data)

        {
            temp = temp->right;
        }

        else

        {
            temp = temp->left;
        }

    }

    return 0;

}
 
void inorder(struct node *root)

{

    if (root == NULL)

    {

        return;

    }

    inorder(root->left);

    printf("%d ",  root->data);

    inorder(root->right);

}

int get_data()

{

    int data;

    printf("\nEnter Data: ");

    scanf("%d", &data);

    return data;

}


int main()

{

    int userChoice;

    int userActive = 'Y';

    int data;

    struct node* result = NULL;

 

	do

    {


        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Inorder ");
        printf("\n4. Exit");


        printf("\n\nEnter Your Choice: ");

        scanf("%d", &userChoice);

        printf("\n");

 

        switch(userChoice)

        {

            case 1:

                data = get_data();

                insert(data);

                break;

 

            case 2:

                data = get_data();

                root = delete(root, data);

                break;

            case 3:

                inorder(root);

                break;
 

            case 4:

                printf("\n\nProgram was terminated\n");

                break;

            default:

                printf("\n\tInvalid Choice\n");

                break;

        }

  

    }
while(userChoice!=4);
 

    return 0;
}











 


