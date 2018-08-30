#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define UNIMPLEMENTED(name) char* str_repr_##name = "\"" #name "\"";  int name(); int name() { printf("%s not implemented! at line number %d in file %s \n", str_repr_##name, __LINE__, __FILE__ ); return  EXIT_SUCCESS;}

#define AND       &&
#define OR        ||
#define NOT       !
#define NOTEQUALS !=
#define EQUALS    ==
#define IS        =
#define COUNT_OF(x) ((sizeof(x)/sizeof(0[x])) / ((size_t)(!(sizeof(x) % sizeof(0[x])))))
#define LSH_RL_BUFSIZE 1024

UNIMPLEMENTED (lsh_read_line);


UNIMPLEMENTED (lsh_split_line);
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
