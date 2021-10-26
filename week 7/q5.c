#include <stdio.h>
// a 
struct _coord {
    double x;
    double y;
};
// b
typedef struct _node Node;
struct _node {
    int value;
    Node *next;
};
// c
struct _enrolment {
    int stu_id;         // e.g. 5012345
    char course[9];     // e.g. "COMP1521"
    char term[5];       // e.g. "17s2"
    char grade[3];      // e.g. "HD"
    double mark;        // e.g. 87.3
};
// d
typedef struct Item {
    int value;
} Item;
struct _queue {
    int nitems;     // # items currently in queue
    int head;       // index of oldest item added
    int tail;       // index of most recent item added
    int maxitems;   // size of array
    Item *items;    // malloc'd array of Items
};

int main () {
    printf("a: %lu\n", sizeof(struct _coord));
    printf("b: %lu\n", sizeof(struct _node));
    printf("c: %lu\n", sizeof(struct _enrolment));
    printf("d: %lu\n", sizeof(struct _queue));
}