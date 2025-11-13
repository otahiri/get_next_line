#include "get_next_line.h"
#include "stdio.h"
#include <fcntl.h>

int main()
{
	int fd = open("read_error.txt", O_RDONLY);
	int i = 0;

	while (i < 10)
	{
		printf("%s", get_next_line(fd));
		i++;
	}
}
