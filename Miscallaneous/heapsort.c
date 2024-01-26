#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

//breathfirst
struct node* createtree(int n, const int arr[], int i = 0) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if(i < n) {
        newnode->data = arr[i];
        newnode->left = createtree(n, arr, i*2+1);
        newnode->right = createtree(n, arr, i*2+2);
    }
    else
        return NULL;
    return newnode;
}

void maxheap(struct node* root) {
    if(root->left->data > root->data) {
        //swap
        maxheap
    }

}

void preorder(struct node* temp) {
    if(temp != NULL) {
        printf("%d ", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

int main() {
    int temp[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    struct node* root = createtree(10, temp);
    preorder(root);
}