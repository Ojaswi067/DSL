#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Job structure to store job details
struct Job {
    int id;
    string description;
};

// Function to add a job to the queue
void addJob(queue<Job>& jobQueue, int jobId, const string& jobDescription) {
    Job newJob = { jobId, jobDescription };
    jobQueue.push(newJob);
    cout << "Job added: " << jobDescription << " (Job ID: " << jobId << ")" << endl;
}

// Function to delete a job from the queue
void deleteJob(queue<Job>& jobQueue) {
    if (!jobQueue.empty()) {
        cout << "Job removed: " << jobQueue.front().description << " (Job ID: " << jobQueue.front().id << ")" << endl;
        jobQueue.pop();
    } else {
        cout << "Job queue is empty. No job to remove." << endl;
    }
}

// Function to display all jobs in the queue
void displayJobs(const queue<Job>& jobQueue) {
    if (jobQueue.empty()) {
        cout << "Job queue is empty." << endl;
        return;
    }

    queue<Job> tempQueue = jobQueue; // Make a copy of the queue
    cout << "Current jobs in the queue:" << endl;
    while (!tempQueue.empty()) {
        cout << "Job ID: " << tempQueue.front().id << ", Description: " << tempQueue.front().description << endl;
        tempQueue.pop();
    }
}

int main() {
    queue<Job> jobQueue;
    int choice, jobId;
    string jobDescription;

    do {
        cout << "\nJob Queue Operations:\n";
        cout << "1. Add Job\n";
        cout << "2. Delete Job\n";
        cout << "3. Display Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter job ID: ";
                cin >> jobId;
                cout << "Enter job description: ";
                cin.ignore(); // To ignore the newline character left in the input buffer
                getline(cin, jobDescription);
                addJob(jobQueue, jobId, jobDescription);
                break;
            case 2:
                deleteJob(jobQueue);
                break;
            case 3:
                displayJobs(jobQueue);
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
