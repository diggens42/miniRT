#include "../include/miniRT.h"

int main(int argc, char *argv[])
{
    if (argv != NULL) {
        argc = 1;
    }
    printf("Hello world!");
    t_rt rt;
    hardcode_data(&rt);
    printf("%f", rt.alight.ratio);
    free_shape_lst(&rt);
    return 0;
}