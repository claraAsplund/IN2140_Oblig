#include <string.h>
#include <stdio.h>

#define BUFSIZE 255

// This is how you can take commands from the terminal when running the program.
// argc is the number of arguments (including the name of the binary file). argv is the list of arguments
int main(int argc, char **argv){

	// This types holds 'streams'
	FILE *fil;

	char *mode, *filename;
	char buf[BUFSIZE];
	int rc, wc;

	if (argc < 3){
		fprintf(stderr, "too few arguments\n");
		return 1;
	}

	// We use the arguments taken in from the command line interface
	mode = argv[1];
	filename = argv[2];

	// We open the file with the mode defined from the command line interface
	// Note that we also check for errors, and will keep doing so in the rest of the code.
	fil = fopen(filename, mode);
	if (fil == NULL){
		perror("fopen");
		return 1;
	}

	// If the mode is set to 'r', we start the 'read' part of our program.
	if (*mode == 'r'){
		rc = fread(buf, sizeof(char), BUFSIZE-1, fil);
		if (rc < BUFSIZE && ferror(fil)){
			fprintf(stderr, "fread");
			fclose(fil);
			return 1;
		}
		// We add a '0' to the end of the written part of the buffer. This is to tie of the content of the buffer as a string. (Since all strings end with a 0)
		buf[rc] = 0;
		printf("%s\n", buf);
	}

	// If the mode is set to 'w', we start the 'write' part of our program.
	if (*mode == 'w'){
		// Since writing to a file requires an additional argument, we check to see if we added a text from the command line.
		if (argc < 4){
			fprintf(stderr, "too few arguments\n");
			fclose(fil);
			return 1;
		}

		// Here we actually write the content of argv[4] to file. If the file doesn't exist, it is created.
		wc = fwrite(argv[3], sizeof(char), strlen(argv[3]), fil);
		if (wc < (int)strlen(argv[3])){
			fprintf(stderr, "fwrite");
			fclose(fil);
			return 1;
		}
	}

	// Remember to close the file you opened in the beginning of the program. This is also done when exiting the program due to an error.
	fclose(fil);
	return 0;
}
