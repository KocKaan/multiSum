#include <iostream>
#include <pthread.h>

using namespace std;

int arr[] = {1000, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220};
int totalSum = 0;
int part = 0;

void *sum(void *arg)
{

    // Each thread computes sum of 1/4th of array
    int thread_part = part++;

    for (int i = thread_part * 4; i < (thread_part + 1) * 4; i++)
        totalSum += arr[i];
}

int main()
{

    pthread_t threads[4];

    for (int i = 0; i < 4; i++)
        pthread_create(&threads[i], NULL, sum, (void *)NULL);

    for (int i = 0; i < 4; i++)
        pthread_join(threads[i], NULL);

    cout << "sum is " << totalSum << endl;

    return 0;
}