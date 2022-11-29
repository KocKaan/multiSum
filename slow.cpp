#include <iostream>
#include <pthread.h>
#include <chrono>

using namespace std;

pthread_mutex_t mutexLock = PTHREAD_MUTEX_INITIALIZER;
int arr[] = {1000, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220};
int totalSum = 0;
int part = 0;

void *sum(void *arg)
{
    pthread_mutex_lock(&mutexLock);

    int thread_part = part++;
    for (int i = thread_part * 4; i < (thread_part + 1) * 4; i++)
        totalSum += arr[i];

    pthread_mutex_unlock(&mutexLock);
}

int main()
{

    pthread_t threads[4];
    auto start = chrono::system_clock::now();

    for (int i = 0; i < 4; i++)
        pthread_create(&threads[i], NULL, sum, (void *)NULL);

    for (int i = 0; i < 4; i++)
        pthread_join(threads[i], NULL);

    chrono::duration<double> dur = chrono::system_clock::now() - start;
    cout << "Time for addition " << dur.count() << " seconds" << endl;

    cout << "sum is " << totalSum << endl;

    return 0;
}