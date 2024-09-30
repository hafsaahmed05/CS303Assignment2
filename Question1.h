#pragma once

#include <vector>
#include <stdexcept>
#include <iostream>
using namespace std;

template <typename Item_Type>
class Single_Linked_List {

private:
    struct Node {
        Item_Type data;
        Node* next;

        Node(const Item_Type& data_item, Node* next_ptr = nullptr) : data(data_item), next(next_ptr) {}
        };

        Node* head;
        Node* tail;
        size_t num_items;

public:
    // Constructor
    Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

    // Destructor
    ~Single_Linked_List() {
        while (head != nullptr) {
            pop_front();
        }
    }

    bool empty() {
        return num_items == 0;
    }

    // Push an item to the front of the list
    void push_front(const Item_Type& item) {
        Node* new_node = new Node(item, head);
        head = new_node;
        if (tail == nullptr) {
            tail = new_node;
        }
        num_items++;
    }

    // Push an item to the back of the list
    void push_back(const Item_Type& item) {
        Node* new_node = new Node(item, nullptr);
        if (tail != nullptr)
            tail->next = new_node;
        else
            head = new_node;  // The list was empty
        tail = new_node;
        ++num_items;
    }

    // Pop an item from the front of the list
    void pop_front() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
            --num_items;
            if (num_items == 0)
                tail = nullptr;
        }
        else {
            throw std::out_of_range("List is empty");
        }
    }

    void pop_back() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        else if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        }
        else {
            Node* newTail = head;
            while (newTail->next != tail)
                newTail = newTail->next;
            delete tail;
            tail = newTail;
            tail->next = nullptr;
        }
    }

    Item_Type& front() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        return head->data;
    }

    Item_Type& back() {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        return tail->data;
    }

    void insert(size_t index, const Item_Type& item) {

        if (index == 0)
            push_front(item);

        else if (index == (num_items - 1))
            push_back(item);

        else if (index > (num_items - 1))
            throw std::out_of_range("Invalid Index.");

        else {
            Node* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            Node* new_node = new Node(item, current->next);
            current->next = new_node;
            num_items++;
        }
    }

    bool remove(size_t index) {
        if (empty()) {
            throw std::out_of_range("List is empty");
        }
        
        else if (index == 0)
            pop_front();
        
        else if (index > (num_items - 1))
            throw std::out_of_range("Invalid Index.");

        else {
            Node* current = head;
            for (int i = 0; i < index; i++) {
                current = current->next;
            }
            Node* node_to_remove = current->next;
            current->next = node_to_remove->next;
            delete node_to_remove;
            if (index == num_items - 1)
                tail = current;
            num_items--;
            return 1;
        }

        return 0;
    }

    size_t find(const Item_Type& item) const {
        Node* current = head;
        size_t index = 0;
        while (current != nullptr) {
            if (current->data == item)
                return index;
            current = current->next;
            index++;
        }
        return num_items;  // Return the size of the list if not found
    }

    void printList() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};
