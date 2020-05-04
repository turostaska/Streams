#include <iostream>
#include "linked_list.h"

template<typename T>
LinkedList<T>::LinkedList() : size{0} {
    auto first_node = std::make_shared<ListNode>();
    auto last_node = std::make_shared<ListNode>();
    first = first_node;
    first->next = last_node;
    last_node->prev = first;
    last = last_node;
}

template<typename T>
void LinkedList<T>::push_back(T item) {
    auto node = std::make_shared<ListNode>( item );
    node->next = last.lock();
    node->prev = node->next->prev;
    (node->prev).lock()->next = node;
    node->next->prev = node;
    size++;
}

template<typename T>
T& LinkedList<T>::front() {
    if (size == 0)
        throw std::out_of_range("The list was empty.");
    return first->next->data;
}

template<typename T>
T& LinkedList<T>::back() {
    if (size == 0)
        throw std::out_of_range("The list was empty.");
    return (last.lock()->prev).lock()->data;
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
    for (auto it = first->next; it != last.lock(); it = it->next) {
        if (!fun(it->data))
            remove_node(it);
    }
}

template<typename T>
void LinkedList<T>::remove(const T& to_remove) {
    for (auto it = first->next; it != last.lock(); it = it->next) {
        if (it->data == to_remove)
            remove_node(it);
    }
}

template<typename T>
void LinkedList<T>::remove_node(std::shared_ptr<ListNode> to_remove) {
    (to_remove->prev).lock()->next = to_remove->next;
    to_remove->next->prev = to_remove->prev;
    size--;
}

template<typename S>
std::ostream &operator<<(std::ostream &os, const LinkedList<S> &list) {
    for (auto it = list.first->next; it != list.last.lock(); it = it->next) {
        os << it->data << "\t";
    }
    os << std::endl;
    return os;
}

template<typename T>
LinkedList<T>::ListNode::ListNode() {}

template<typename T>
LinkedList<T>::ListNode::ListNode(T data) : ListNode{} { this->data = data; }
