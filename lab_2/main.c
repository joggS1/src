#include <stdio.h>
#include <pthread.h>
#include <sys/neutrino.h>
#include <unistd.h> // For sleep()

pthread_t thread_id1;
pthread_t thread_id2;

void *long_thread1(void *notused) {
    int n;
    for (n = 0; n < 5; n++) {
        printf("Eto pervii potok, TID %lu - N povtora %d\n", thread_id1, n);
        sleep(2);
    }
    return NULL;
}

void *long_thread2(void *notused) {
    int m;
    for (m = 0; m < 5; m++) {
        printf("Eto vtoroi potok, TID %lu - N povtora %d\n", thread_id2, m);
        sleep(1);
    }
    return NULL;
}

int main(void) {
    printf("Prog threads PID %d\n", getpid());

    pthread_create(&thread_id1, NULL, long_thread1, NULL);
    pthread_create(&thread_id2, NULL, long_thread2, NULL);

    sleep(40);

    return 0;
}
