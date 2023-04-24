#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <unistd.h>

void wait_or_die() {
    int rc = wait(NULL);
}

int fork_or_die() {
    int rc = fork();
    return rc;
}

int main(int argc, char *argv[]) {
    // 자식이면.
    if (fork_or_die() == 0) {
        sleep(1);
        // 자식이면.
        if (fork_or_die() == 0) {
            sleep(2);
            exit(0);
        }
        // 자식이면.
        if (fork_or_die() == 0) {
            sleep(3);
            exit(0);
        }
        wait_or_die();
        wait_or_die();
        exit(0);
    }
    wait_or_die();
    return 0;
}
