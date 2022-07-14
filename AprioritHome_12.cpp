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
    int lenWorkers = 20;
    const int minSalary = 9000;
    const int maxSalary = 45000;
    const int checkSalary = 9999;
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

    Worker* prev = nullptr;
    // Task 1 - reverse list
    for (Worker* cur = head; cur != nullptr; )
    {
        Worker* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    std::swap(head, tail);

    // print list
    std::cout << "\n\n";
    for (Worker* cur = head; cur != nullptr; cur = cur->next)
    {
        std::cout << "id : " << cur->id << "\t salary : " << cur->salary << "\n";
    }

    // Task 2 add worker before typed id
    std::cout << "\nInput id before : ";
    int id = 0;
    std::cin >> id;

    Worker* workerId = head;
    for ( ;workerId != nullptr; workerId = workerId->next) // find needed worker by id
    {
        if (workerId->id == id)
        {
            break;
        }
        prev = workerId;
    }

    // add newWorker to list
    //std::cout << "\nprev->id : " << prev->id << "\t salary : " << prev->salary << "\n";
    //std::cout << "\nworkerId->id : " << workerId->id << "\t salary : " << workerId->salary << "\n";
    
    if (prev == tail) // element wasn't founded
    {
        std::cout << "\n\t#####ELEM NOT FOUND#####\n";
    } 
    else
    {
        Worker* newWorker = new Worker;
        ++lenWorkers;
        newWorker->id = lenWorkers;
        newWorker->salary = checkSalary;
        newWorker->next = workerId;

        if (prev == nullptr)
        {
            head = newWorker;
        }
        else
        {
            prev->next = newWorker;
        }
    }
    
    // print list
    std::cout << "\n\n";
    for (Worker* cur = head; cur != nullptr; cur = cur->next)
    {
        std::cout << "id : " << cur->id << "\t salary : " << cur->salary << "\n";
    }

    //delete list
    prev = head;
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

