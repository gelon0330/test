#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define BLOCK_SIZE (10*1024*1024)


/*
 *      每次申请10M内存，循环执行的次数为申请内存的次数,比如参数为50,则意味着申请500M
 *      */


int main(int argc, char **argv)
{

        int thr, i;
        char *p1;

        if (argc != 2) {
                printf("Usage: mem_alloc <num (MB)>\n");
                exit(0);
        }

        thr = atoi(argv[1]);

        printf("Allocating," "set to %d Mbytes\n", thr*10);
        sleep(30);
        for (i = 0; i < thr; i++) {
                p1 = malloc(BLOCK_SIZE);
                sleep(1);
                memset(p1, 0x00, BLOCK_SIZE);
        }

        sleep(600);

        return 0;
}