#include <stdlib.h>

void *realloc(void *ptr, size_t old_size, size_t new_size)
{

    if (ptr == NULL)
        return malloc(new_size);
    if (new_size == 0)
    {
        free(ptr);
        return NULL;
    }

    char *old = (char *)ptr;
    char *new = (char *)malloc(new_size);

    for (int i = 0; i < old_size && i < new_size; ++i)
    {
        new[i] = old[i];
    }

    free(ptr);
    return (void *)new;
}
