#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define UNIMPLEMENTED(name) char* str_repr_##name = "\"" #name "\"";  int name(); int name() { printf("%s not implemented! at line number %d in file %s \n", str_repr_##name, __LINE__, __FILE__ ); return  EXIT_SUCCESS;}
#define ALLOC_FAIL(buf) if (!#buf) { fprintf(stderr, "lsh: allocation error " #buf "at line number %d in file %s \n", __LINE__, __FILE__); exit(EXIT_FAILURE); }
#define AND       &&
#define OR        ||
#define NOT       !
#define NOTEQUALS !=
#define EQUALS    ==
#define IS        =
#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))

#define LSH_RL_BUFSIZE 1024
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"


char * lsh_read_line(void){
    int bufsize = LSH_RL_BUFSIZE;
    int position = 0;
    char * buffer = malloc(sizeof(char) * bufsize);
    int c;
    ALLOC_FAIL(buffer);

    while(1) {
        // Read a character
        c = getchar();

        // if we hit EOF, replace it with a null character and return
        if (c == EOF || strcmp(&c, '\n') == 0 ) {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }
        position++;

        // if we exceeded the buffer, reallocate.
        if (position >= bufsize) { 
            bufsize += LSH_RL_BUFSIZE;
            buffer = realloc(buffer,bufsize);
            if (!buffer){
                fprintf(stderr, "lsh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }


    }
}

// UNIMPLEMENTED (lsh_split_line);

char **lsh_split_line(char *line){
    int bufsize = LSH_TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    ALLOC_FAIL(tokens);

    token = strtok(line, LSH_TOK_DELIM);
    while (token != NULL) {
        tokens[position] = token;
        position ++;
        if (position >= bufsize) {
            bufsize += LSH_TOK_BUFSIZE;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "lsh: allocation error \n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, LSH_TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}



UNIMPLEMENTED (lsh_execute);

void lsh_loop(void){
    char *line;
    char **args;
    int status;

    do {
        printf("> ");
        line = lsh_read_line();
        args = lsh_split_line(line);
        status = lsh_execute(args);

        free(line);
        free(args);
    } while (status);

}



int main(){

    // Run command loop
    lsh_loop();

    // Perform any shutdown/cleanup

    return EXIT_SUCCESS;
}
