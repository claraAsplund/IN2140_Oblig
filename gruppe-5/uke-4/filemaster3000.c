#include <string.h>
#include <stdio.h>

#define BUFSIZE 255

int main(int argc, char **argv){

	FILE *fil;

	char *mode, *filename;
	char buf[BUFSIZE];
	int rc, wc;

	if (argc < 3){
		fprintf(stderr, "too few arguments\n");
		return 1;
	}

	mode = argv[1];
	filename = argv[2];

	fil = fopen(filename, mode);
	if (fil == NULL){
		perror("fopen");
		return 1;
	}

	if (*mode == 'r'){
		rc = fread(buf, sizeof(char), BUFSIZE-1, fil);
		if (rc < BUFSIZE && ferror(fil)){
			fprintf(stderr, "fread");
			fclose(fil);
			return 1;
		}
		buf[rc] = 0;
		printf("%s\n", buf);
	}

	if (*mode == 'w'){
		if (argc < 4){
			fprintf(stderr, "too few arguments\n");
			fclose(fil);
			return 1;
		}
		wc = fwrite(argv[3], sizeof(char), strlen(argv[3]), fil);
		if (wc < (int)strlen(argv[3])){
			fprintf(stderr, "fwrite");
			fclose(fil);
			return 1;
		}
	}

	fclose(fil);
	return 0;
}
