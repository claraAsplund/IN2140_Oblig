#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFSIZE 255

int main(void){


	int fd, rc;
	char buf[BUFSIZE];

	fd = open("minfil.txt", O_RDONLY);
	if (fd == -1){
		perror("open");
		return 1;
	}

	rc = read(fd, buf, BUFSIZE-1);
	if (rc == -1){
		perror("read");
		close(fd);
		return 1;
	}
	buf[rc] = 0;

	printf("%s\n", buf);

	return 0;
}
