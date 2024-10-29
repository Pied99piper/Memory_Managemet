#include <stdio.h>
#include <stdlib.h>  
#include <stdint.h> 

int global_var1 = 10;
int global_var2 = 20;
int global_var3;

void stack_function(int depth) {
    int local_var = depth;
    printf("Stack frame at depth %d, address of local_var: %p (int: %lu)\n", 
           depth, (void*)&local_var, (uintptr_t)&local_var);

    if (depth < 3) {
        stack_function(depth + 1); 
    }
}

void heap_function() {
    int *heap_var1 = (int *)malloc(sizeof(int));
    int *heap_var2 = (int *)malloc(sizeof(int));
    int *heap_var3 = (int *)malloc(sizeof(int));

    printf("Heap variable 1 address: %p (int: %lu)\n", (void *)heap_var1, (uintptr_t)heap_var1);
    printf("Heap variable 2 address: %p (int: %lu)\n", (void *)heap_var2, (uintptr_t)heap_var2);
    printf("Heap variable 3 address: %p (int: %lu)\n", (void *)heap_var3, (uintptr_t)heap_var3);

    free(heap_var1);
    free(heap_var2);
    free(heap_var3);
}

int main() {
    printf("Global variable 1 address: %p (int: %lu)\n", (void *)&global_var1, (uintptr_t)&global_var1);
    printf("Global variable 2 address: %p (int: %lu)\n", (void *)&global_var2, (uintptr_t)&global_var2);
    printf("Global variable 3 address: %p (int: %lu)\n", (void *)&global_var3, (uintptr_t)&global_var3);

    printf("\n=== Stack Growth ===\n");
    stack_function(1);

    printf("\n=== Heap Growth ===\n");
    heap_function();

    return 0;
}
