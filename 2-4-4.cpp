#include <bits/stdc++.h>
using namespace std;

struct node {
	int v;
	node *l, *r;
};

node *insert(node *p, int x) {
	if (p == NULL) {
		node *q = new node;
		q->v = x;
		q->l = q->r = NULL;
		return q;
	}
	if (x < p->v) p->l = insert(p->l, x);
	else p->r = insert(p->r, x);
	return p;
}

bool find(node *p, int x) {
	if (p == NULL) return false;
	else if (x == p->v) return true;
	else if (x < p->v) return find(p->l, x);
	else return find(p->r, x);
}

node *remove(node *p, int x) {
	if (p == NULL) return NULL;
	else if (x < p->v) p->l = remove(p->l, x);
	else if (x > p->v) p->r = remove(p->r, x);
	else if (p->l == NULL) {
		node *q = p->r;
		delete p;
		return q;
	} else if (p->l->r == NULL) {
		node *q = p->l;
		q->r = p->r;
		delete p;
		return q;
	} else {
		node *q;
		for (q = p->l; q->r->r != NULL; q = q->r);
		node *r = q->r;
		q->r = r->l;
		r->l = p->l;
		r->r = p->r;
		delete p;
		return r;
	}
}


int main() {
	return 0;
}