#include <pthread.h>
#include <stdio.h>

#define HUGE 10000000
int counter = 0;
pthread_mutex_t lock;

void* count_huge(void* arg) {
    for (int i = 0; i < HUGE && counter<HUGE; ++i) {
        pthread_mutex_lock(&lock);
        counter++;
        pthread_mutex_unlock(&lock);
    }
    return NULL;
}

int main() {
    pthread_t new_thread; // Holds the ID of the new thread
    pthread_mutex_init(&lock, NULL);

    pthread_create(&new_thread, NULL, count_huge, NULL);

    // Run in main thread
    count_huge(NULL);

    // Wait for the new thread to finish
    pthread_join(new_thread, NULL);


    pthread_mutex_destroy(&lock);

    // Print the final counter value
    printf("Final counter: %d\n", counter);

    return 0;
}
