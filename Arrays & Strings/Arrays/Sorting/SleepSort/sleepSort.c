#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * O(max(n))
 * The runtime is based on the largest number in the array in seconds
 */
void sleepSort(int arr[], int arr_count) {
    int i = 0;
    /**
     * While i is less than the number of elements in the array
     */
    while (i < arr_count) {
        /**
         * Fork function creates a new process to run concurrently with the parent
         * process
         * 
         * If the fork function returns 0 the process running is a child process
         * 
         * If the fork function returns a positive number it is the id of the
         * child process which was just created. This creates a branching structure,
         * the below code will only run if the process is a child and break if it is
         * a parent
         * 
         * Parent i=0                   Child 1 i=0
         * fork == positive number ->   fork == 0
         * break                        ++i
         * sleep(arr[0])...             Loop                        Child 2 i=1
         *                              fork == positive number ->  fork == 0
         *                              break                       etc...
         *                              sleep(arr[1])
         * 
         * 'i' will be what its parents 'i' was during creation
         */
        if (fork() == 0) {
            ++i;
        } else {
            break;
        }
    }
    /**
     * When the above instance of the while loop is broken (the process has a child)
     * 
     * Set a sleep for the length of time which is array[i]
     * Once the sleep has ended print that number
     * Waits until child process has completed
     * 
     */
    if (i < arr_count) {
        sleep(arr[i]);
        printf("%d\n", arr[i]);
        wait(NULL);
    }
}
