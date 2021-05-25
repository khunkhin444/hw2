struct node {
    int data;
    struct node *left;
    struct node *right;
};
void not_bs(int *arr_input, int *arr_queue, int tok1, int tok2);
void bst_find(struct node *parent, int num);
struct node *bst_insert(struct node *parent, int *num);
struct node *newNode(int num);
void rmTree(struct node *parent);