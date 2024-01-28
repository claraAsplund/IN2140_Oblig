#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int fd = open("file.txt", O_RDONLY);
  if (fd == -1) {
    // handle error
  }
  size_t file_size = (size_t)lseek(fd, 0, SEEK_END); // seek to end of file
  if (file_size == -1) {
    // handle error
  }
  printf("%ld\n", file_size);
  if ((file_size > 0) && (lseek(fd, 0, SEEK_SET) == -1)) {
    // handle error
  }
  if (file_size > 0 && file_size % sizeof(char) != 0) {
    // handle error: file size is not a multiple of char size
  }
  char *buffer = malloc(file_size); // allocate buffer
  if (buffer == NULL) {
    // handle error
  }
  ssize_t nread = read(fd, buffer, file_size); // read entire file
  if (nread == -1) {
    // handle error
  }
  printf("%s", buffer);
  // do something with the buffer
  free(buffer); // free the buffer
  close(fd);    // close the file descriptor
  return 0;
}
