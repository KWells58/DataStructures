#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

struct Thread {
    int index; // Index of the thread
    int job_index; // Index of the job the thread is processing
    int processing_time; // Remaining processing time of the job
};

int main() {
    // Read the input file
    ifstream inputFile("input1");
    int n, m;
    inputFile >> n >> m;

    // Create an array of threads
    Thread threads[n];
    for (int i = 0; i < n; i++) {
        threads[i].index = i;
    }

    // Read the processing times of the jobs
    int processingTimes[m];
    for (int i = 0; i < m; i++) {
        inputFile >> processingTimes[i];
    }

    // Initialize the scheduler
    priority_queue<Thread, vector<Thread>, greater<Thread>> priorityQueue;
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

        // Decrement the processing time of the job
        thread.processing_time--;

        // If the processing time of the job is zero, remove the thread from the priority queue
        if (thread.processing_time == 0) {
            // Remove the thread from the priority queue
            priorityQueue.pop();
        }
    }

    // Write the output file
    ofstream outputFile("output1.txt");
    for (int i = 0; i < m; i++) {
        // Write the thread index and the start time to the output file
        outputFile << threads[i].index << " " << threads[i].job_index << endl;
    }

    return 0;
}
