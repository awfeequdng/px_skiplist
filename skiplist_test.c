#include <stdio.h>
#include <assert.h>
#include <time.h>

#include "skiplist.h"

#define NODE   10 * 1024

int main(void) {
    int i;
    int *key = malloc(NODE * sizeof(int));
    if (key == NULL) {
        exit(-1);
    }

    SkipList *list = skiplist_new();
    if (list == NULL) {
        exit(-1);
    }

    printf("Test skiplist start!\n");
    printf("Add %d node.\n", NODE);

    // insert skiplist
    int start_time = time(NULL);
    srand(start_time);
    for (i = 0; i < NODE; i++) {
        int val = key[i] = (int)rand();
        skiplist_insert(list, key[i], val);
    }
    printf("spend %d s\n", time(NULL) - start_time);
    // skiplist_dump(list);

    // search skiplist
    printf("Search skiplist node.\n");
    start_time = time(NULL);
    for (i = 0; i < NODE; i++) {
        SkipListNode *node = skiplist_search(list, key[i]);
        assert(node != NULL);
        // if (node != NULL) {
        //     printf("key:0x%08x val:0x%08x\n", node->key, node->val);
        // } else {
        //     printf("Not found:0x%08x\n", key[i]);
        // }
    }
    printf("spend %d S\n", time(NULL) - start_time);

    // delete skiplist
    printf("Delete skiplist node.\n");
    start_time = time(NULL);
    for (i = 0; i < NODE; i++) {
        skiplist_remove(list, key[i]);
    }
    assert(list->count == 0);
    printf("spend %d S\n", time(NULL) - start_time);
    // skiplist_dump(list);


    printf("End skiplist test.\n");
    skiplist_del(list);

    free(key);
}