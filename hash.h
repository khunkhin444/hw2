#define max_hash (1<<20)

struct h_node {
    int data;
    struct h_node *link;
};
int hash0(char *data);
char *myitoa(int n, char *s);
char  *reverse(char *s);
void l_find(struct h_node *ptr, int num);
void hash_find(struct h_node **hash_tab, int num);
struct h_node *l_insert(struct h_node *ptr, int num);
void hash_insert(struct h_node **hash_tab, int num);
void hash(int *arr_input, int *arr_queue, int tok1, int tok2);