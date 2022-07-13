// AprioritHome_12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Worker {
    int id = 0;
    int salary = 0;
    Worker* next = nullptr;
};

int main()
{
    const int lenWorkers = 20;
    const int minSalary = 9000;
    const int maxSalary = 45000;
    Worker* head = nullptr;
    Worker* tail = nullptr;
    // Fill start list and print
    for (int i = 0; i < lenWorkers; i++)
    {
        Worker* curent = new Worker;
        curent->id = i + 1;
        curent->salary = minSalary + rand() % (maxSalary - minSalary + 1);
        
        if (head == nullptr)
        {
            head = curent;
        }
        else
        {
            tail->next = curent;
        }


        tail = curent;
        //print curent(tail) worker
        std::cout << "id : " << tail->id << "\t salary : " << tail->salary << "\n";
    }

    // Task 1 - reverse list
    for (int i = 0; i < lenWorkers / 2; i++)
    {
        Worker* left = head;
        Worker* right = head;
        for (int j = 0; j < i; j++) // set necessary index like A[i]
        {
            left = left->next;
        }

        for (int k = 0; k < lenWorkers - i - 1; k++) // set necessary index like A[len - i]
        {
            right = right->next;
        }

        // Swap id and salary
        std::swap(left->id, right->id);
        std::swap(left->salary, right->salary);
    }

    // print list
    std::cout << "\n\n";
    for (Worker* cur = head; cur != nullptr; cur = cur->next)
    {
        std::cout << "id : " << cur->id << "\t salary : " << cur->salary << "\n";
    }
    

    //delete list
    Worker* prev = head;
    for (Worker* cur = head->next; cur != nullptr; cur = cur->next)
    {
        delete prev;
        prev = nullptr;
        prev = cur;
    }
    // Delete last element
    delete prev;
    prev = nullptr;
}

