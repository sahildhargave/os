#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv) {
    int t = 1;
    while (t == 1) {
        printf("\nSystem Calls : ");
        printf("\n1) Fork ");
        printf("\n2) Copy(cp) ");
        printf("\n3) Grep");
        printf("\n4) Exit ");
        printf("\n**Select one option : ");
        int n;
        scanf("%d", &n);
        switch (n) {
            case 1: {
                pid_t pid;
                int status;
                pid = fork();
                if (pid == 0) {
                    printf("=> Child\n");
                    printf("It is a child process and pid is %d.\n", getpid());
                    execl("/bin/ls", "ls", "-l", "/home/pccoe/", (char *)0);
                    perror("In exec(): ");
                } else if (pid > 0) {
                    printf("=> Parent\n");
                    printf("I am a parent process and pid is %d.\n", getpid());
                    pid = wait(&status);
                    printf("End of process %d: ", pid);
                    if (WIFEXITED(status)) {
                        printf("The process ended with exit(%d).\n", WEXITSTATUS(status));
                    }
                    if (WIFSIGNALED(status)) {
                        printf("The process ended with kill -%d.\n", WTERMSIG(status));
                    }
                } else {
                    printf("ERROR");
                    perror("In fork():");
                }
                break;
            }
            case 2: {
                if (argc < 3) {
                    printf("Insufficient arguments!\n");
                    break;
                }
                if (strcmp(argv[1], argv[2]) != 0) {
                    char fs[100];
                    FILE *fptr;
                    fptr = fopen(argv[1], "r+");
                    if (fptr) {
                        FILE *fn = fopen(argv[2], "w");
                        while (fscanf(fptr, "%s", fs) != EOF) {
                            fprintf(fn, "%s\n", fs);
                        }
                        fclose(fn);
                    } else {
                        printf("\nOops... File does not exist or failed to open..\n");
                    }
                    fclose(fptr);
                } else {
                    printf("\nSource and Destination files are same\n");
                }
                break;
            }
            case 3: {
                if (argc < 4) {
                    printf("Insufficient arguments!\n");
                    break;
                }
                char fs[100];
                FILE *fptr;
                fptr = fopen(argv[3], "r+");
                if (fptr) {
                    if (strcmp(argv[1], "-c") == 0) {
                        int count = 0;
                        while (fscanf(fptr, "%s", fs) != EOF) {
                            if (strcmp(argv[2], fs) == 0) {
                                count++;
                            }
                        }
                        printf("count = %d\n", count);
                    }
                    fclose(fptr);
                } else {
                    printf("\nOops... File does not exist or failed to open...\n");
                }
                break;
            }
            case 4:
                t = 0;
                break;
            default:
                printf("Invalid argument!!");
        }
    }
    return 0;
}
