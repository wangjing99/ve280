#include "dlist.h"
#include <iostream>

enum STATUS {PLATINUM, GOLD, SILVER, REGULAR};
const char *statusName[] = {"platinum", "gold", "silver", "regular"};

STATUS getStatus(const std::string &str) {
    for (int i = 0; i < 4; i++) {
        if (str == statusName[i]) {
            return STATUS(i);
        }
    }
    return STATUS(3);
}

struct Customer {
    std::string name;
    int duration;
};


int main() {
    int num = 0, time = 0, timestamp = 0, readyAnswer = 0;
    std::cin >> num;
    Dlist<Customer> *queue[4];
    for (int i = 0; i < 4; i++) {
        queue[i] = new Dlist<Customer>;
    }
    if (num >= 0) {
        num--;
        std::cin >> timestamp;
    }
    bool busy = false;
    bool run = true;
    Customer *answer = nullptr;
    while (run) {
        if (num < 0) {
            bool empty = true;
            for (int i = 0; i < 4; i++) {
                if (!queue[i]->isEmpty()) {
                    empty = false;
                    break;
                }
            }
            if (empty) run = false;
        }

        std::cout << "Starting tick #" << time << std::endl;
        if (busy && readyAnswer == time) {
            busy = false;
            delete answer;
        }
        while (time == timestamp && num >= 0) {
            auto temp = new Customer;
            std::cin >> temp->name;
            std::string str;
            std::cin >> str;
            auto status = getStatus(str);
            std::cin >> temp->duration;
            queue[status]->insertBack(temp);
            std::cout << "Call from " << temp->name << " a " << statusName[status] << " member" << std::endl;
            num--;
            if (num >= 0) {
                std::cin >> timestamp;
            }
        }

        for (int i = 0; i < 4; i++) {
            if (!queue[i]->isEmpty()) {
                    if (!busy) {
                        answer = queue[i]->removeFront();
                        readyAnswer = time + answer->duration;
                        busy = true;
                        std::cout << "Answering call from " << answer->name << std::endl;
                        break;
                    }
            }
        }

        time++;
    }
    for (int i = 0; i < 4; i++) {
        delete queue[i];
    }
    return 0;
}

