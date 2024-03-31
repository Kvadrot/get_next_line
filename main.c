

#include "get_next_line.h"

int main(int argc, char *argv[])
{
	int fd;
    // Open the file for reading
    fd = open("example.txt", O_RDONLY);
	if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }


	for (int a = 7; a > 0; a--)
	{
		char *test1 = get_next_line(fd);
		printf("nextlen = %s", test1);
	}

	// char *test1 = get_next_line(fd);
	// printf("nextlen = %s", test1);
	// char *test2 = get_next_line(fd);
	// printf("nextlen = %s", test2);
    // Close the file descriptor
    if (close(fd) == -1) {
        perror("Error closing file");
        exit(EXIT_FAILURE);
    }

	if (argc == 10)
	{
		printf("dd  %s \n", argv[1]);
	}

    return 0;

}

