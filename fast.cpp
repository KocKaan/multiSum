#include <iostream>
#include <pthread.h>
#include <chrono>

using namespace std;

int arr[] = {1, 5, 7, 10, 12, 14, 15, 18, 20, 22, 25, 27, 30, 64, 110, 220};
int sum[4] = {0};

void *sum_array(void *ptr)
{
    int tInput = *((int *)ptr);
    free(ptr);
    for (int i = tInput * 4; i < (tInput + 1) * 4; i++)
    {
        sum[tInput] += arr[i];
    }
}

int main()
{

    pthread_t threads[4];
    auto start = chrono::system_clock::now();

    for (int i = 0; i < 4; i++)
    {
        int *ptr;
        ptr = new int;
        *ptr = i;

        pthread_create(&threads[i], NULL, sum_array, ptr);
    }

    for (int i = 0; i < 4; i++)
    {
        pthread_join(threads[i], NULL);
    }

    int total_sum = 0;
    for (int i = 0; i < 4; i++)
    {
        total_sum += sum[i];
    }

    chrono::duration<double> dur = chrono::system_clock::now() - start;
    cout << "Time for addition " << dur.count() << " seconds" << endl;

    cout << "sum is " << total_sum << endl;

    return 0;
}