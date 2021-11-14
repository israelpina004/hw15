#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

char** parse_args(char* line) {
	char** arr_args = calloc(5, sizeof(char *));
	char* token;

	int i;
	for(i = 0; i < sizeof(line); i++) {
		token = strsep(&line, " ");
		arr_args[i] = token;
	}
	return arr_args;
}

int main() {
	char line[50];

	printf("Enter commands: \n");
	fgets(line, sizeof(line), stdin);
	int newline = strcspn(line, "\n");
	line[newline] = '\0';

	printf("\n");
 	char** args = parse_args(line);
	execvp(args[0], args);
	return 0;
}
