#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int getRand() 
{
        int randNum = 0;
        int fd = open("/dev/urandom", O_RDONLY);
        if(-1 == fd)
        {
                // handle error
        }

        read(fd, (char *)&randNum, sizeof(int));
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
