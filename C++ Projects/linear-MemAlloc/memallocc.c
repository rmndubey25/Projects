
#include <stdio.h>
#include <stddef.h>

#define total_MemorySize_we_have 64

static unsigned char array_where_allocated_data_is_stored[total_MemorySize_we_have];
static size_t offset = 0; //im using 0 here to save the starting and how much is left for next call and from hwere to call it 

//new offset= old offset + offset

//Operation	        Offset	Bytes remaining
//Initial state	      0	        64
//Allocate 16 bytes	  16	    48
//Allocate 8 bytes	  24	    40
//Allocate 20 bytes	  44	    20 and so on 

void *linear_alloc(size_t size)
{
    if (size == 0)
        return NULL;

    if (size > total_MemorySize_we_have - offset)
        return NULL;

    void *ptr = array_where_allocated_data_is_stored + offset;
    offset += size;

    return ptr;
}

int main(void)
{
    int *a = linear_alloc(sizeof(int));
    int *b = linear_alloc(sizeof(int));

    if (a == NULL || b == NULL) {
        printf("allocation failed\n");
        return 1;
    }

    *a = 100;
    *b = 200;

    printf("a = %d\n", *a);
    printf("b = %d\n", *b);

    printf("pool address: %p\n", (void *)array_where_allocated_data_is_stored);
    printf("a address:    %p\n", (void *)a);
    printf("b address:    %p\n", (void *)b);

    return 0;
}

