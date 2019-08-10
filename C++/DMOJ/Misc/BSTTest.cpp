#include <bits/stdc++.h>

using namespace std;
struct node
{
    int key;
    struct node *left, *right;
    int dupli, less, more, height;
};
int getNum(struct node *n)
{
    return n == NULL ? 0 : (n->more + n->less + n->dupli);
}
int getHeight(struct node *n)
{
    return n == NULL ? 0 : n->height;
}

int findDiff(struct node* at){
    if(at==NULL)return 0;
    return getHeight(at->left)-getHeight(at->right);
}
struct node *init(int val)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = val;
    temp->left = temp->right = NULL;
    temp->less = temp->more = 0;
    temp->dupli = 1;
    temp->height = 1;
    return temp;
}
struct node *rotateLeft(struct node *at)
{
    struct node *temp = at->right;
    at->right = temp->left;
    temp->left = at;
    at->more = getNum(at->right);
    temp->less = getNum(at);
    at->height = max(getHeight(at->left), getHeight(at->right)) + 1;
    temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
    return temp;
}
struct node *rotateRight(struct node *at)
{

    struct node *temp = at->left;
    at->left = temp->right;
    temp->right = at;
    at->less = getNum(at->left);
    temp->more = getNum(at);
    at->height = max(getHeight(at->left), getHeight(at->right)) + 1;
    temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1;
    return temp;
}
struct node *smallest(struct node *at)
{
    struct node *temp = at;
    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}
bool found = false;
struct node *deleteNode(struct node *at, int val, int amount)
{
    if (at == NULL)
        return at;
    if (at->key < val)
    {
        at->right = deleteNode(at->right, val,amount);
        at->more = getNum(at->right);
    }
    else if (at->key > val)
    {
        at->left = deleteNode(at->left, val,amount);
        at->less = getNum(at->left);
    }
    else
    {
        at->dupli-=amount;
        if (at->dupli == 0)
        {
            if (at->left == NULL)
            {
                struct node *temp = at->right;
                free(at);
                return temp;
            }
            if (at->right == NULL)
            {
                struct node *temp = at->left;
                free(at);
                return temp;
            }
            struct node *replacer = smallest(at->right);
            at->key = replacer->key;
            at->dupli = replacer->dupli;
            at->right = deleteNode(at->right, at->key, at->dupli);
            at->more = getNum(at->right);
        }
    }
    int leftHeight = getHeight(at->left);
    int rightHeight = getHeight(at->right);
    at->height = max(leftHeight, rightHeight) + 1;
    int balance = leftHeight - rightHeight;
    if (abs(balance) < 2)
    {
        return at;
    }
    if (balance > 1 && findDiff(at->left)>=0)
    {
        return rotateRight(at);
    }
    else if (balance < -1 && findDiff(at->right)<=0)
    {
        return rotateLeft(at);
    }
    else if (balance > 1 && findDiff(at->left)<0)
    {
        at->left = rotateLeft(at->left);
        return rotateRight(at);
    }
    else
    {
        at->right = rotateRight(at->right);
        return rotateLeft(at);
    }
    return at;
}
struct node *push(struct node *at, int val)
{
    if (at == NULL)
        return init(val);
    if (val == at->key)
    {
        at->dupli++;
        return at;
    }
    else if (val > at->key)
    {
        at->more++;
        at->right = push(at->right, val);
    }
    else
    {
        at->less++;
        at->left = push(at->left, val);
    }
    int leftHeight = getHeight(at->left);
    int rightHeight = getHeight(at->right);
    at->height = max(leftHeight, rightHeight) + 1;
    int balance = leftHeight - rightHeight;
    if (abs(balance) < 2)
    {
        return at;
    }
    if (balance > 1 && val < at->left->key)
    {
        return rotateRight(at);
    }
    else if (balance < -1 && val > at->right->key)
    {
        return rotateLeft(at);
    }
    else if (balance > 1 && val > at->left->key)
    {
        at->left = rotateLeft(at->left);
        return rotateRight(at);
    }
    else
    {
        at->right = rotateRight(at->right);
        return rotateLeft(at);
    }
}
bool type=false;
void output(struct node *at)
{
    if (at == NULL)
        return;
    output(at->left);
    for(int count=0;count<at->dupli;count++){

    if(type){
        printf(" ");
    }
    type=true;
    printf("%d", at->key);
    }
    
    output(at->right);
    // printf(" UP");
}
int valAt(struct node *at, int order)
{
    return order <= at->less ? valAt(at->left, order) : order > (at->less + at->dupli) ? valAt(at->right, order - (at->less + at->dupli)) : at->key;
    // if(order>at->less&&order<=(at->less+at->dupli)){
    //     return at->key;
    // }
    // if(order<=at->less){
    //     return valAt(at->left,order);
    // }
    // else{
    //     return valAt(at->right,order-(at->less+at->dupli));
    // }
}
int indexOf(struct node *at, int target, int order)
{
    if (at == NULL)
        return -1;
    if (at->key == target)
    {
        return order + at->less + 1;
    }
    if (at->key < target)
    {
        return indexOf(at->right, target, order + at->dupli + at->less);
    }
    return indexOf(at->left, target, order);
}
int main(){
    int max, q;
    struct node *root = NULL;
    cin>>max>>q;
    for (int count = 0; count < max; count++)
    {
        int next;
        cin>>next;
        root = push(root, next);
    }
    int prev=0;
    for (int count = 0; count < q; count++)
    {
        char com;
        int next;
        cin>>com>>next;
        // next=(next^prev);
        int out;
        // printf("%c %d\n", com, next);
        switch (com)
        {
        case 'I':
            root = push(root, next);
            break;
        case 'R':
            root = deleteNode(root, next,1);
            break;
        case 'S':
        out=valAt(root,next);
            printf("%d\n", out);
            prev=out;
            break;
        case 'L':
        out=indexOf(root,next,0);
           printf("%d\n",out);
            prev=out;
            break;
        }
    }
    output(root);
    printf("\n");
}