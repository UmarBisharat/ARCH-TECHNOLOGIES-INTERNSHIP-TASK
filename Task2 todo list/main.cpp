/*
 * ARCH TECHNOLOGIES
 * Task 2: To-Do List Application
 * 
 * A simple To-Do List application that allows users to:
 *   - Add tasks
 *   - View the current list of tasks
 *   - Remove tasks once they are completed
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

// Structure to hold a single task
struct Task {
    int id;
    string description;
    bool completed;
};

// Global task list and ID counter
vector<Task> taskList;
int nextId = 1;

// ─── Display the menu ────────────────────────────────────────────
void displayMenu() {
    cout << endl;
    cout << "=============================================" << endl;
    cout << "        ARCH TECHNOLOGIES - TO-DO LIST       " << endl;
    cout << "=============================================" << endl;
    cout << "  1. Add a new task" << endl;
    cout << "  2. View all tasks" << endl;
    cout << "  3. Mark a task as completed" << endl;
    cout << "  4. Remove a completed task" << endl;
    cout << "  5. Exit" << endl;
    cout << "=============================================" << endl;
    cout << "  Enter your choice: ";
}

// ─── Display all tasks ──────────────────────────────────────────
void viewTasks() {
    cout << endl;
    cout << "---------------------------------------------" << endl;
    cout << "            YOUR CURRENT TASKS               " << endl;
    cout << "---------------------------------------------" << endl;

    if (taskList.empty()) {
        cout << "  (No tasks yet. Add one to get started!)" << endl;
    } else {
        cout << "  ID  | Status     | Task" << endl;
        cout << "  ----|------------|------------------------------" << endl;

        for (const Task& task : taskList) {
            string status = task.completed ? "[DONE]    " : "[PENDING] ";
            cout << "  " << task.id << "   | " << status << " | " << task.description << endl;
        }
    }

    cout << "---------------------------------------------" << endl;
}

// ─── Add a new task ─────────────────────────────────────────────
void addTask() {
    cout << endl;
    cout << "  Enter the task description: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear leftover newline

    string description;
    getline(cin, description);

    // Validate: do not allow empty tasks
    if (description.empty()) {
        cout << "  [!] Task cannot be empty. Returning to menu." << endl;
        return;
    }

    Task newTask;
    newTask.id = nextId++;
    newTask.description = description;
    newTask.completed = false;

    taskList.push_back(newTask);

    cout << "  [+] Task #" << newTask.id << " added successfully!" << endl;
}

// ─── Mark a task as completed ───────────────────────────────────
void markCompleted() {
    if (taskList.empty()) {
        cout << endl;
        cout << "  [!] No tasks to mark. Add a task first." << endl;
        return;
    }

    viewTasks();

    cout << endl;
    cout << "  Enter the ID of the task to mark as completed: ";

    int id;
    cin >> id;

    // Find the task by ID
    bool found = false;
    for (Task& task : taskList) {
        if (task.id == id) {
            if (task.completed) {
                cout << "  [!] Task #" << id << " is already marked as completed." << endl;
            } else {
                task.completed = true;
                cout << "  [✓] Task #" << id << " marked as completed!" << endl;
            }
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "  [!] No task found with ID " << id << "." << endl;
    }
}

// ─── Remove a completed task ────────────────────────────────────
void removeTask() {
    if (taskList.empty()) {
        cout << endl;
        cout << "  [!] No tasks to remove. Add a task first." << endl;
        return;
    }

    // Check if there are any completed tasks at all
    bool hasCompleted = false;
    for (const Task& task : taskList) {
        if (task.completed) {
            hasCompleted = true;
            break;
        }
    }

    if (!hasCompleted) {
        cout << endl;
        cout << "  [!] No completed tasks to remove." << endl;
        cout << "      Mark a task as completed first (Option 3)." << endl;
        return;
    }

    viewTasks();

    cout << endl;
    cout << "  Enter the ID of the completed task to remove: ";

    int id;
    cin >> id;

    // Find and remove only if completed
    bool found = false;
    for (auto it = taskList.begin(); it != taskList.end(); ++it) {
        if (it->id == id) {
            if (!it->completed) {
                cout << "  [!] Task #" << id << " is not completed yet." << endl;
                cout << "      Only completed tasks can be removed." << endl;
            } else {
                taskList.erase(it);
                cout << "  [-] Task #" << id << " has been removed." << endl;
            }
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "  [!] No task found with ID " << id << "." << endl;
    }
}

// ─── Main Program ───────────────────────────────────────────────
int main() {
    int choice;

    cout << endl;
    cout << "  Welcome to the To-Do List Application!" << endl;
    cout << "  Manage your tasks with ease." << endl;

    while (true) {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                cout << endl;
                cout << "  Thanks for using the To-Do List App. Goodbye!" << endl;
                cout << "=============================================" << endl;
                cout << endl;
                return 0;
            default:
                cout << endl;
                cout << "  [!] Invalid choice. Please enter a number between 1 and 5." << endl;
                break;
        }
    }

    return 0;
}
