#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main()
{
	int fd;
	char *str;
    fd = open("41_no_nl", O_RDONLY);
    str = get_next_line(fd);
    while (str != NULL)
    {
        printf("Linea: %s",str);
        str = get_next_line(fd);
    }
}
