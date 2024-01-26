#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

//creates a new node, proceeds for new connections, alas returns it's pointer
//binary tree creation, depth first
struct node* create() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL) {
        printf("Memory allocation failed.");
        exit(1);
    }
    printf("Input value (enter -1 if no node): ");
    int x; scanf("%d", &x);
    if(x == -1)
        return NULL;
    else {
        newnode->data = x;
        printf("Left node of %d\n", x);
        newnode->left = create();
        printf("Right node of %d\n", x);
        newnode->right = create();
    }
    return newnode;
}

//Tree traversal
void preorder(struct node* temp) {
    if(temp != NULL) {
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void inorder(struct node* temp) {
    if(temp != NULL) {
        inorder(temp->left);
        printf("%d ", temp->data);
        inorder(temp->right);
    }
}

void postorder(struct node* temp) {
    if(temp != NULL) {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d ", temp->data);
    }
}

//Tree removal
void destroy_tree(struct node* leaf) {
    if(leaf != NULL) {
        destroy_tree(leaf->left);
        destroy_tree(leaf->right);
        free(leaf);
    }
}

int main() {
    struct node* root = create();
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);

    return 0;
}