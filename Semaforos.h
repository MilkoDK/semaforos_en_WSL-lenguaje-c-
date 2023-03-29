#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

sem_t semaphore; // declarar el semáforo

void* thread_function(void* arg) // función del hilo secundario
{
    printf("Thread is waiting for the semaphore...\n");
    sem_wait(&semaphore); // el hilo espera a que el semáforo esté disponible
    printf("Thread has acquired the semaphore!\n");
    printf("Thread is releasing the semaphore...\n");
    sem_post(&semaphore); // el hilo libera el semáforo
    return NULL;
}

int main()
{
    pthread_t thread; // declarar el hilo secundario
    sem_init(&semaphore, 0, 1); // inicializar el semáforo con valor 1
    pthread_create(&thread, NULL, thread_function, NULL); // crear el hilo secundario
    printf("Main is waiting for the semaphore...\n");
    sem_wait(&semaphore); // el hilo principal espera a que el semáforo esté disponible
    printf("Main has acquired the semaphore!\n");
    printf("Main is releasing the semaphore...\n");
    sem_post(&semaphore); // el hilo principal libera el semáforo
    pthread_join(thread, NULL); // esperar a que el hilo secundario termine
    sem_destroy(&semaphore); // destruir el semáforo
    return 0;
}