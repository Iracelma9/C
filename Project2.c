#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_LEITORES 5
#define NUM_ESCRITORES 2

sem_t sem_leitores;
sem_t sem_escritor;
int num_leitores = 0;

void* leitor(void* arg) {
    int id = *((int*)arg);
    printf("Leitor %d quer ler\n", id);

    sem_wait(&sem_leitores);
    num_leitores++;
    if (num_leitores == 1) {
        sem_wait(&sem_escritor);
    }
    sem_post(&sem_leitores);

    printf("Leitor %d está lendo\n", id);

    sem_wait(&sem_leitores);
    num_leitores--;
    if (num_leitores == 0) {
        sem_post(&sem_escritor);
    }
    sem_post(&sem_leitores);

    printf("Leitor %d terminou de ler\n", id);

    pthread_exit(NULL);
}

void* escritor(void* arg) {
    int id = *((int*)arg);
    printf("Escritor %d quer escrever\n", id);

    sem_wait(&sem_escritor);

    printf("Escritor %d está escrevendo\n", id);

    sem_post(&sem_escritor);

    printf("Escritor %d terminou de escrever\n", id);

    pthread_exit(NULL);
}

int main() {
    pthread_t leitores[NUM_LEITORES];
    pthread_t escritores[NUM_ESCRITORES];
    
    sem_init(&sem_leitores, 0, 1);
    sem_init(&sem_escritor, 0, 1);

    int i;
    int ids_leitores[NUM_LEITORES];
    int ids_escritores[NUM_ESCRITORES];

    for (i = 0; i < NUM_LEITORES; i++) {
        ids_leitores[i] = i;
        pthread_create(&leitores[i], NULL, leitor, &ids_leitores[i]);
    }

    for (i = 0; i < NUM_ESCRITORES; i++) {
        ids_escritores[i] = i;
        pthread_create(&escritores[i], NULL, escritor, &ids_escritores[i]);
    }

    for (i = 0; i < NUM_LEITORES; i++) {
        pthread_join(leitores[i], NULL);
    }
    
    for (i = 0; i < NUM_ESCRITORES; i++) {
        pthread_join(escritores[i], NULL);
    }

    sem_destroy(&sem_leitores);
    sem_destroy(&sem_escritor);

    return 0;
}

