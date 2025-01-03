#include <stdio.h>

// MIN and MAX are defined by default
#ifndef MIN
#define MIN -100
#endif

#ifndef MAX
#define MAX 100
#endif

// NBR of iterations, overrided by MAX and MIN
#ifndef NBR
#define NBR MAX - MIN
#endif

int main(void)
{
    int n;
    size_t i;

    n = MAX;
    while (n > MIN && i++ < NBR)
        printf("%d ", n--);
}
