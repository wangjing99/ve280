#ifndef PROJECT_5_DLIST_IMPL_H
#define PROJECT_5_DLIST_IMPL_H
#include "dlist.h"

template<class T>
bool Dlist<T>::isEmpty() const {
    return this->first == nullptr;
}

template<class T>
void Dlist<T>::insertFront(T *op) {
    auto target = new node;
    target->op = op;
    target->prev = nullptr;
    if (this->isEmpty()) {
        target->next = nullptr;
        this->last = target;
    }
    else {
        target->next = this->first;
        this->first->prev = target;
    }
    this->first = target;
}

template<class T>
void Dlist<T>::insertBack(T *op) {
    auto target = new node;
    target->op = op;
    target->next = nullptr;
    if (this->isEmpty()) {
        target->prev = nullptr;
        this->first = target;
    }
    else {
        target->prev = this->last;
        this->last->next = target;
    }
    this->last = target;
}

template<class T>
T *Dlist<T>::removeFront() {
    if (this->isEmpty()) throw emptyList();
    auto *victim = this->first;
    auto *op = victim->op;
    if (victim->next == nullptr) {
        this->first = nullptr;
        this->last = nullptr;
    }
    else {
        this->first = victim->next;
        this->first->prev = nullptr;
    }
    delete victim;
    return op;
}

template<class T>
T *Dlist<T>::removeBack() {
    if (this->isEmpty()) throw emptyList();
    auto *victim = this->last;
    auto *op = victim->op;
    if (victim->prev == nullptr) {
        this->first = nullptr;
        this->last = nullptr;
    }
    else {
        this->last = victim->prev;
        this->last->next = nullptr;
    }
    delete victim;
    return op;
}

template<class T>
Dlist<T>::Dlist() {
    this->first = nullptr;
    this->last = nullptr;
}

template<class T>
Dlist<T>::Dlist(const Dlist &l) {
    if (!l.isEmpty()) {
        this->removeAll();
        this->copyAll(l);
    }
}

template<class T>
Dlist<T> &Dlist<T>::operator=(const Dlist &l) {
    if (this != &l) {
        this->removeAll();
        this->copyAll(l);
    }
    return *this;
}

template<class T>
Dlist<T>::~Dlist() {
    this->removeAll();
}

template<class T>
void Dlist<T>::removeAll() {
    while (!this->isEmpty()) {
        delete removeFront();
    }
}

template<class T>
void Dlist<T>::copyAll(const Dlist &l) {
    if (!l.isEmpty()) {
        auto item = l.first;
        while (item != nullptr) {
            this->insertBack(new T(*item->op));
            item = item->next;
        }
    }
}


#endif //PROJECT_5_DLIST_IMPL_H
