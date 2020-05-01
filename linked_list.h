#ifndef STREAM_LINKED_LIST_H
#define STREAM_LINKED_LIST_H

#include <memory>
#include <functional>

template <typename T>
class LinkedList {
private:
    struct ListNode{
        T data;
        std::shared_ptr<ListNode> next;
        ListNode(T);
    };
    std::shared_ptr<ListNode> first;
    std::shared_ptr<ListNode> last;
    std::size_t size;
public:
    LinkedList();
    void push_back(T);
    T& front();
    T& back();
    size_t get_size() const;
    bool empty() const;
    void remove(const T&);
    void keep_if(std::function<bool(T)>);
    void remove_node(std::shared_ptr<ListNode>);

    template <typename S>
    friend std::ostream& operator<<(std::ostream& os, const LinkedList<S>& list);
};



#endif //STREAM_LINKED_LIST_H
