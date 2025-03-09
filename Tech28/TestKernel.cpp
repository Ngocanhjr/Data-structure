/*
    pid_t is a data type defined in Unix/Linux systems. It's used to represent Process IDs when working with processes.
   Typically pid_t is implemented as a signed integer type
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>  //Wait Functions, privide wait() and waitpid()
#include <unistd.h>    //Unix Standard Library

#define DEFAULT_TABLE "1"

int main(int argc, char *argv[])
{
    char *arg;

    //Check input
    if (argc != 2)
    {
        printf("Error input. This is default multiplication table!\n");
        arg = DEFAULT_TABLE;
    }
    else
    {
        arg = argv[1];  // Lấy số nhập vào
    }

    // Declaring a variable of type pid_t to store process ID values
    pid_t pid;
    // Get and check the current process ID
    pid = getpid();
    printf("Current process ID: %d\n", pid);

    // Forks a child and get ID
    pid = fork();

    if (pid < 0)  // Fork fail
    {
        printf("Fork failed\n");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)  // Children process (P2)
    {
        printf("You are in child process (P2) with PID: %d\n", pid);
        execl("./multiplicationtable", "multiplicationtable", arg, NULL);

        // If execl returns, it must have failed
        perror("execl failed");
        exit(EXIT_FAILURE);
    }
    else  // Parent process (P1)
    {
        printf("Parent process P1 with PID: %d waiting for child P2 (PID: %d) to complete\n", getpid(), pid);
        int status;
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
        {
            printf("Child P2 (PID: %d) completed with exit status: %d\n", pid, WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
        {
            printf("Child P2 (PID: %d) terminated by signal: %d\n", pid, WTERMSIG(status));
        }

        printf("Parent P1 exiting\n");
    }

    return 0;
}