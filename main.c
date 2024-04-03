

#include "get_next_line.h"

int main()
{
	int fd;
    // Open the file for reading
    fd = 0;//open("example.txt", O_RDONLY);
	if (fd == -1) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

	// char *test1 = get_next_line(fd);
	// printf("nextlen = %s", test1);


	// char *test2 = get_next_line(fd);
	// printf("nextlen = %s", test2);
	for (int a = 0; a < 10; a++ )
	{
		char *test1 = get_next_line(fd);
		printf("LINE_IND: %d = %s", a, test1);
	}
		// char *test1 = get_next_line(fd);
		// printf("LINE_IND = %s", test1);
	// char *test1 = get_next_line(fd);
	// printf("nextlen = %s", test1);
	// char *test2 = get_next_line(fd);
	// printf("nextlen = %s", test2);
	// char *test3 = get_next_line(fd);
	// printf("nextlen = %s", test3);
    // Close the file descriptor

    return 0;

}

