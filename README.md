# Semaforos en WSL (lenguaje C)

Este repositorio consiste en la documentacion de un ejemplo de semaforos en WSL con el objetivo de cumplir  
el mandato del maestro de sistemas operativos 2.

## Descripcion

El código comienza por incluir las cabeceras necesarias para utilizar semáforos, pthreads y printf.   
Luego se declara una variable del tipo sem_t llamada semaphore, que será nuestro semáforo. La función   
thread_function es la función que se ejecutará en el hilo secundario, y lo que hace es esperar a que   
el semáforo esté disponible, adquirirlo, imprimir un mensaje, liberarlo y luego salir de la función.

En la función main, se inicializa el semáforo con un valor de 1 usando la función sem_init. Luego se   
crea el hilo secundario utilizando pthread_create, y se espera a que el semáforo esté disponible en el   
hilo principal mediante sem_wait. Después de adquirir el semáforo, se imprime un mensaje, se libera el   
semáforo mediante sem_post, se espera a que el hilo secundario termine mediante pthread_join, y se   
destruye el semáforo mediante sem_destroy.

## La salida del codigo seria:

~~~
Main is waiting for the semaphore...
Thread is waiting for the semaphore...
Main has acquired the semaphore!
Main is releasing the semaphore...
Thread has acquired the semaphore!
Thread is releasing the semaphore...
~~~




