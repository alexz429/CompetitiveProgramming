#include <bits/stdc++.h>
#define ll long long
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
    at->more=getNum(at->right);
    temp->less=getNum(at);
    at->height=max(getHeight(at->left), getHeight(at->right))+1;
    temp->height=max(getHeight(temp->left), getHeight(temp->right))+1;
    return temp;
}
struct node *rotateRight(struct node *at)
{
    struct node *temp = at->left;
    at->left = temp->right;
    temp->right = at;
    at->less=getNum(at->left);
    temp->more=getNum(at);
    at->height=max(getHeight(at->left), getHeight(at->right))+1;
    temp->height=max(getHeight(temp->left), getHeight(temp->right))+1;
    return temp;
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
    int leftHeight=getHeight(at->left);
    int rightHeight=getHeight(at->right);
    at->height=max(leftHeight,rightHeight)+1;
    int balance=leftHeight-rightHeight;
    if(abs(balance)<2) {
				return at;
			}
			if(balance>1&&val<at->left->key) {
				return rotateRight(at);
			}
			else if(balance<-1&&val>at->right->key) {
				return rotateLeft(at);
			}
			else if(balance>1&&val>at->left->key) {
				at->left=rotateLeft(at->left);
				return rotateRight(at);
			}
			else {
				at->right=rotateRight(at->right);
				return rotateLeft(at);
			}
};
int query(struct node *at, int val)
{
    if (at == NULL)
        return 0;
    if (at->key == val)
        return at->dupli + at->less;
    if (at->key < val)
        return at->dupli + at->less + query(at->right, val);
    return query(at->left, val);
};
int main()
{
    int max, limit;
    scanf("%d %d", &max, &limit);
    int sum = 0;

    ll tally = 0;
    struct node *tree = NULL;
    tree = push(tree, sum);
    for (int count = 0; count < max; count++)
    {
        int next;
        scanf("%d", &next);
        // printf("%d", next);
        if (next >= limit)
        {
            sum++;
        }
        else
        {
            sum--;
        }
        tally += query(tree, sum);
        tree = push(tree, sum);
        // printf("%d\n", tally);
    }
    printf("%lld", tally);
}