#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    char *line;

    line = get_next_line(fd);
    printf("Line 1: %s", line);
    free(line);

    line = get_next_line(fd);
    printf("Line 2: %s", line);
    free(line);

    line = get_next_line(fd);
    printf("Line 3: %s", line);
    free(line);

    line = get_next_line(fd);
    printf("Line 4: %s", line);
    free(line);

    printf("\n");

    close(fd);
    return 0;
}
