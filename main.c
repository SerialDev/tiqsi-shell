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

UNIMPLEMENTED (lsh_loop);


int main(){

    // Run command loop
    lsh_loop();

    // Perform any shutdown/cleanup

    return EXIT_SUCCESS;
}
