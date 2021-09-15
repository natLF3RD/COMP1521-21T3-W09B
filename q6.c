#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    int id;
    char* name;
    double d;
    char c;
    // double arr[100000];
};


int main() {
    struct node *a, *b, *c, *d;
    a = NULL;
    b = malloc(sizeof *b);
    b->d = 10;
    b->c = 'a';
    b->id = 10000;
    c = malloc(sizeof (struct node) );
    d = malloc(8); // bad style
    c = a;
    d.data = 42; // fails because d is a pointer
    // (will still fail because c is NULL)
    c->data = 42; // does not fail because c is a pointer
    (*c).data = 42; // same as line above
    
    return 0;
}


void declaring_structs() {
    // using pointer
    struct node *p;
    // need to malloc
    p = malloc (sizeof *p);
    // to access fields within need to dereference the variable
    p->data = 3;
    // or 
    (*p).data = 3;
    
    // no pointer
    struct node x;
    // no need to malloc
    // use . to access fields
    x.data = 3;
}