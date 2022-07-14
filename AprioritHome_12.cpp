// AprioritHome_12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Worker {
    int id = 0;
    int salary = 0;
};

struct Node {
    Worker* worker = new Worker;
    Node* next = nullptr;
};

int main()
{
    int lenWorkers = 20;
    const int minSalary = 9000;
    const int maxSalary = 45000;
    const int checkSalary = 9999;
    Node* head = nullptr;
    Node* tail = nullptr;
    // Fill start list and print
    for (int i = 0; i < lenWorkers; i++)
    {
        Node* curent = new Node;
        curent->worker->id = i + 1;
        curent->worker->salary = minSalary + rand() % (maxSalary - minSalary + 1);
        
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
        std::cout << "id : " << tail->worker->id << "\t salary : " << tail->worker->salary << "\n";
    }

    Node* prev = nullptr;
    // Task 1 - reverse list
    for (Node* cur = head; cur != nullptr; )
    {
        Node* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    std::swap(head, tail);

    // print list
    std::cout << "\n\n";
    for (Node* cur = head; cur != nullptr; cur = cur->next)
    {
        std::cout << "id : " << cur->worker->id << "\t salary : " << cur->worker->salary << "\n";
    }

    // Task 2 add worker before typed id
    std::cout << "\nInput id before : ";
    int id = 0;
    std::cin >> id;

    Node* workerId = head;
    for ( ;workerId != nullptr; workerId = workerId->next) // find needed worker by id
    {
        if (workerId->worker->id == id)
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
        Node* newWorker = new Node;
        ++lenWorkers;
        newWorker->worker->id = lenWorkers;
        newWorker->worker->salary = checkSalary;
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
    for (Node* cur = head; cur != nullptr; cur = cur->next)
    {
        std::cout << "id : " << cur->worker->id << "\t salary : " << cur->worker->salary << "\n";
    }

    //delete list
    prev = head;
    for (Node* cur = head->next; cur != nullptr; cur = cur->next)
    {
        delete prev->worker;
        delete prev;
        prev = nullptr;
        prev = cur;
    }
    // Delete last element
    delete prev;
    prev = nullptr;
}

