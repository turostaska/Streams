#include <iostream>
#include "linked_list.h"

template<typename T>
LinkedList<T>::LinkedList() : first{nullptr}, last{nullptr}, size{0} {}

template<typename T>
void LinkedList<T>::push_back(T item) {
    auto node = std::make_shared<ListNode>( item );
    if (!last) {
        first = node;
        last = first;
    } else {
        last->next = node;
        last = last->next;
    }
    size++;
}

template<typename T>
T& LinkedList<T>::front() {
    if (!first)
        throw std::out_of_range("The list was empty.");
    return first->data;
}

template<typename T>
T& LinkedList<T>::back() {
    if (!last)
        throw std::out_of_range("The list was empty.");
    return last->data;
}

template<typename T>
size_t LinkedList<T>::get_size() const {
    return size;
}

template<typename T>
bool LinkedList<T>::empty() const {
    return size == 0;
}

template<typename T>
void LinkedList<T>::keep_if(std::function<bool(T)> fun) {
    for (auto it = first; it != nullptr; it = it->next) {
        if (!fun(it->data))
            remove_node(it);
    }
}

template<typename T>
void LinkedList<T>::remove(const T& to_remove) {
    auto prev = first;
    for (auto it = first; it != nullptr; it = it->next) {
        if (it->data == to_remove) {
            if (it == first) {
                first = first->next;
                // it->next = nullptr; TODO: talán szivárgáshoz vezet
            }
            else if (it == last) {
                last = prev;
                last->next = nullptr;
            }
            else {
                prev->next = it->next;
            }
            size--;
        }
        else
            prev = it;
    }
}

template<typename T>
void LinkedList<T>::remove_node(std::shared_ptr<ListNode> to_remove) {
    for (auto it = first; it != nullptr; it = it->next) {
        if (it->next == to_remove) {
            it->next = to_remove->next;
            size--;
            return;
        }
    }
}

template<typename S>
std::ostream &operator<<(std::ostream &os, const LinkedList<S> &list) {
    for (auto it = list.first; it != nullptr; it = it->next) {
        os << it->data << "\t";
    }
    os << std::endl;
    return os;
}

template<typename T>
LinkedList<T>::ListNode::ListNode(T data) : data{data}, next{nullptr} {}
