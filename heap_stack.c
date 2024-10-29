#include <stdio.h>
#include <stdlib.h>  
#include <stdint.h> 

int global_test1 = 10;
int global_test2 = 20;
int global_test3;

void show_stack(int depth) {
    int local_var = depth;
    printf("Stack at depth %d, address of local_var: %p\n", 
           depth, (void*)&local_var);

    if (depth < 3) {
        show_stack(depth + 1); 
    }
}

void show_heap() {
    int *heap_var1 = (int *)malloc(sizeof(int));
    int *heap_var2 = (int *)malloc(sizeof(int));
    int *heap_var3 = (int *)malloc(sizeof(int));

    printf("Heap variable 1 address: %p\n", (void *)heap_var1);
    printf("Heap variable 2 address: %p\n", (void *)heap_var2);
    printf("Heap variable 3 address: %p\n", (void *)heap_var3);

    free(heap_var1);
    free(heap_var2);
    free(heap_var3);
}

int main() {
    printf("\n=================== Global variable ===================\n");
    printf("Global variable 1 address: %p\n", (void *)&global_test1);
    printf("Global variable 2 address: %p\n", (void *)&global_test2);
    printf("Global variable 3 address: %p\n", (void *)&global_test3);

    printf("\n=================== Stack Growth ===================\n");
    show_stack(1);

    printf("\n=================== Heap Growth ====================\n");
    show_heap();
    printf("=======================================================\n");
    return 0;
}
