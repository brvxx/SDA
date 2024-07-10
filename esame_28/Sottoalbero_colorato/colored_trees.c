#include <stdbool.h>

#include "tree.h"

struct tree_info {
	const Node* tree; 
	char color; 
	int n; 
	int depth; 
};

typedef struct tree_info TreeInfo; 

static void TreeIsSameColor(const Node* t, TreeInfo* info, int depth) {
	if (TreeIsEmpty(t)) {
		if (depth > info->depth) {
			info->depth = depth; 
		}
		return; 
	}
	if (t->value != info->color) {
		info->n = -1; 
		return;
	}
	if (info->n == -1) { // per evitare venga sovrascritto il valore -1 in n
		return;
	}

	info->n++; 
	TreeIsSameColor(TreeLeft(t), info, depth + 1);
	TreeIsSameColor(TreeRight(t), info, depth + 1);

}

static void BiggestColoredTreeRec(const Node* t, TreeInfo* info_best) {
	
	if (TreeIsEmpty(t)) {
		return; 
	}

	TreeInfo info = {
		.tree = t, 
		.color = t->value, 
		.n = 0, 
		.depth = 0
	};

	TreeIsSameColor(t, &info, 0); 
	if (info.n > -1) {
		if (info.n > info_best->n) { *info_best = info; }
		if (info.n == info_best->n && info.depth > info_best->depth) { *info_best = info; }
		return;
	}

	BiggestColoredTreeRec(TreeLeft(t), info_best);
	BiggestColoredTreeRec(TreeRight(t), info_best); 
}

const Node* BiggestColoredTree(const Node* t) {
	if (TreeIsEmpty(t)) {
		return NULL; 
	}
	TreeInfo res = {0}; 
	BiggestColoredTreeRec(t, &res); 

	return res.tree; 
}