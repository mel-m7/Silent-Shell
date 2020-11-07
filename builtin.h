
//  Function Declarations for builtin shell commands

int sh_cd(char **args);
int sh_help(char **args);
int sh_exit(char **args);


//  List of builtin commands, followed by their corresponding functions

char *builtin_str[] = {
    "cd",
    "help",
    "exit"
};

int (*builtin_func[]) (char **) = {
    &sh_cd,
    &sh_help,
    &sh_exit
};

int sh_num_builtins() {
    return sizeof(builtin_str) / sizeof(char *);
}


//  Builtin function implementations.

int sh_cd(char **args){
    if (args[1] == NULL) {
        fprintf(stderr, "sh: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("sh");
        }
    }
    return 1;
}

int sh_help(char **args){
    int i;
    printf("Silent shell\n");
    printf("Type program names and arguments, and press enter button.\n");
    printf("The following are built in:\n");

    for (i = 0; i < sh_num_builtins(); i++) {
        printf("  %s\n", builtin_str[i]);
    }

    printf("Use the man command for information on other programs.\n");
    return 1;
}

int sh_exit(char **args){
    return 0;
}
