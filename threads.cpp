#include <pthread.h>
#include <stdio.h>

void* my_turn(void* arg) {
    int x = *(int*)arg; // Cast and dereference the argument
    for (int i = 0; i < 500; i++) {
        printf("Hello, my turn is %d\n", i);
    }
    return (void*)(long)x; // Return x as a void pointer
}

void you_turn(int i) {
    for (int j = 0; j < 5; j++) {
        printf("Hello, your turn is %d\n", j);
    }
}

/*int main() {
    pthread_t new_thread; // Holds the ID of the new thread
    int i = 3;

    // Create a new thread
    pthread_create(&new_thread, NULL, my_turn, &i);

    // Execute you_turn in the main thread
    you_turn(++i);

    // Wait for the new thread to finish,Try deleting this line and see what happens
    void* result;
    pthread_join(new_thread, &result);

    // Print the result (cast back to int)
    printf("Thread returned: %ld\n", (long)result);

    return 0;
}*/
