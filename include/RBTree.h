#ifndef RB_TREE_
#define RB_TREE_

#include <stdlib.h>

enum RBT_color { 
	RBT_BLACK, RBT_RED 
};

typedef struct RBT_NODE {
	enum RBT_color color;
	int key;
	void *data;
	struct RBT_NODE *left;
	struct RBT_NODE *right;
	struct RBT_NODE *parent;
} RBT_NODE;

typedef struct RBT_TREE {
	struct RBT_NODE *root;
	size_t node_count;
} RBT_TREE;

RBT_TREE *RBT_init_tree(void);

void RBT_destroy_tree(RBT_TREE *);

void *RBT_add(RBT_TREE *, int, void *);

int RBT_delete(RBT_TREE *, int);

void *RBT_find(RBT_TREE *, int);

void *RBT_get_maximum(RBT_TREE *);

void *RBT_get_minimum(RBT_TREE *);

void RBT_pretty_printer(RBT_NODE *);

#define RBT_PRETTY_PRINT(tree) RBT_pretty_printer(tree->root)
#define RBT_IS_RED(node) (node != NULL && node->color == RBT_RED)
#define RBT_IS_BLACK(node) (node == NULL || node->color == RBT_BLACK)
#define RBT_NODE_COUNT(tree) ( tree->node_count )

#endif
