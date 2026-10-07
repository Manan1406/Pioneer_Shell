#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include "pish_history.h"

static char pish_history_path[1024] = {'\0'};

/*
 * Set history file path to ~/.pish_history.
 */
static void set_history_path() {
    const char *home = getpwuid(getuid())->pw_dir;
    strncpy(pish_history_path, home, 1024);
    strcat(pish_history_path, "/.pish_history");
}

/*
 * Append the command represented by the given struct pish_arg to the history
 * file at pish_history_path. Separate argv values using a single space.
 */
void add_history(const struct pish_arg *arg) {
    if (!(*pish_history_path)) {
        set_history_path();
    }
    // TODO
    FILE* file = fopen(pish_history_path, "a");
    if(file == NULL){
        perror("add_history, fopen");
        return;
    }
    for(int i = 0; i < arg->argc; i++){
        fprintf(file, "%s", arg->argv[i]);
        if(i < arg->argc - 1){
            fputc(' ', file);
        }

    }
    fputc('\n', file);
    fclose(file);

}

/*
 * Print the contents of the file at pish_history_path with line numbers.
 * Each line of output should consist of the line number, a space, and the
 * line itself.
 *
 * For example, if the history file contains:
 * echo Hello 1
 * pwd
 *
 * Then, this function should print:
 * 1 echo Hello 1
 * 2 pwd
 */
void print_history() {
    if (!(*pish_history_path)) {
        set_history_path();
    }
    // TODO
    char line[1024];
    int line_num = 1;
    FILE* file = fopen(pish_history_path, "r");
    if(file == NULL){
        perror("print_history, fopen");
    }
    while(fgets(line, sizeof(line), file)){
       /* size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') {
            line[len - 1] = '\0';
        }*/
        printf("%d %s", line_num, line);
        line_num += 1;
    }

    fclose(file);

}

/*
 * Clear the contents of the file at pish_history_path.
 */
void clear_history() {
    if (!(*pish_history_path)) {
        set_history_path();
    }
    // TODO
    FILE* file = fopen(pish_history_path, "w");
    if(file == NULL){
        perror("clear_history, fopen");
    }
    fclose(file);
}
