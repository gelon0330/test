#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int getRand() 
{
        int randNum = 0;
        int fd = open("/dev/urandom", O_RDONLY);
        static int count = 0;
        count++;
        if(-1 == fd)
        {
                // handle error
                printf("error, %d\n", count);
                //exit(1)
        }

        read(fd, (char *)&randNum, sizeof(int));
        //close(fd); 
        return randNum;
}

int main()
{
        while(1)
        {
                getRand();
                sleep(1);
        }
}
