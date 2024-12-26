#include "pthread.h"
#include "stdio.h"

int my_turn(int x){
    for(int i = 0; i < 5; i++){
        printf("Hello, my turn is %d\n",i);
    }
    return x;
}
void you_turn(int i) {
    for (int i = 0; i < 3; i++) {
        printf("Hello, your turn is %d\n", i);
    }
}
int main(){
    pthread_t new_thread; //will hold the id of the new thread we will create
    int i  = 3;
    pthread_create(new_thread,NULL,my_turn,&i); // create a new thread in a program
                                               // myturn is where the thread will start executing

    you_turn(++i);
    int result;
    pthread_join(new_thread,&result);

}