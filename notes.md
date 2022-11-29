2.  In my naive implementation there is a race condition that has been created by
    the line 14 where the variable part is incremented to be read as thread_part.
    This is a race condition because the variable part is shared by every 4 thread that
    comes in to the sum() method. There is a possibility that when the thread_part is
    assigned to a value its not correct because it has been incremented by another thread
    as well. This would cause some indexes to be not read or read multiple times.
    As any variable created is shared in the thread stack it will be changed constantly.

3.  The solution I had was to use a mutex lock to make sure each threads are not accessing
    the critical area, the lines that modify the variables, at the same time. When a
    thread enters the critical area it locks it and when its done it unlocks it so that
    other thread can come in. This is slow because we are not actually utilizing the
    benefits of having a multithread as threads can do the computation sequentially.

4.  The solution I had for fast was to have an extra array that stored the subarray sums
    of the main array that we were trying to add up. As I was using 4 threads I created
    an extra array with 4 indexes and filled each index with the sum of (array.length / 4)
    of the main array. To be able to do this I dynamically allocated memory for the
    i's that I used to indicate the indexes that I wanted to target. For example the
    second thread would send 1 as the parameter for the sum() and this would be used to
    target 1/4 - 2/4 of the array. The reason why Im dynamically allocating memory for the
    i is to make sure the location of the int stays unique and stays until its freed inside the function.
    What I have realized is the article https://www.geeksforgeeks.org/sum-array-using-pthreads/ is
    wrong and it creates race condition as the i that was sent could be accessed by every thread.

One of the optimization method that is worth sharing is the compiler optimization
flag that could be used during the compiling time. Another potential solution is
the usage of atomic value so that it doesn't need mutex. One way to implement this
was to modify the totalSum inside the sum() method to std::atomic<unsigned long long> totalSum(0);
This is a better solution than the slow.cpp one as we don't need the mutex anymore.
Then we would have to take care of the part variable to make sure there is no race
condition. This could be solved in multiple trivial way.
Another possible addition could be instead of the default memory model of sequential
consistency, I could use relaxes semantics. This would work because the order of
summing up the data doesn't matter in this case.

Kaan Karakas
