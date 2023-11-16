#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

struct Thread {
    int index; // Index of the thread
    int job_index; // Index of the job the thread is processing
    int processing_time; // Remaining processing time of the job

    // Overloading the less-than operator for the priority queue
    bool operator<(const Thread& other) const {
        return processing_time > other.processing_time || (processing_time == other.processing_time && index > other.index);
    }
};

int main() {
    // Read the input file
    ifstream inputFile("input1.txt");
    int n, m;
    inputFile >> n >> m;

    // Create an array of threads
    Thread threads[n];
    for (int i = 0; i < n; i++) {
        threads[i].index = i;
        threads[i].job_index = -1; // Initialize with an invalid job index
        threads[i].processing_time = 0; // Initialize with zero processing time
    }

    // Read the processing times of the jobs
    int processingTimes[m];
    for (int i = 0; i < m; i++) {
        inputFile >> processingTimes[i];
    }

    // Initialize the scheduler
    priority_queue<Thread> priorityQueue;
    for (int i = 0; i < n; i++) {
        priorityQueue.push(threads[i]);
    }

    // Simulate the execution of the jobs
    for (int i = 0; i < m; i++) {
        // Remove the thread with the highest priority from the priority queue
        Thread thread = priorityQueue.top();
        priorityQueue.pop();

        // Assign the job to the thread
        thread.job_index = i;
        thread.processing_time = processingTimes[i];

        // Output the result
        cout << thread.index << " " << i << endl;

        // Add the thread back to the priority queue
        priorityQueue.push(thread);
    }

    return 0;
}
