#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include <iostream>
#include <stdexcept>

using size_t = unsigned long;

class DoubleLinkedListIterator;

template <typename T>
class DoubleLinkedList {
 private:
  struct Node {
    T data;
    Node* prev;
    Node* next;
  };

  Node* start;
  Node* endNode;
  size_t m_size;

 private:
  class DoubleLinkedListIterator {
   public:
    DoubleLinkedListIterator(Node* ptr) : m_ptr(ptr) {}

    DoubleLinkedListIterator& operator++() {
      if (m_ptr == nullptr) {
        throw std::invalid_argument("operator ++ on invalid iterator");
      }
      m_ptr = m_ptr->next;
      return *this;
    }

    DoubleLinkedListIterator& operator--() {
      if (m_ptr == nullptr || m_ptr->prev == nullptr) {
        throw std::invalid_argument("operator -- on invalid iterator");
      }
      m_ptr = m_ptr->prev;
      return *this;
    }

    T& operator*() {
      if (m_ptr == nullptr) {
        throw std::invalid_argument("operator * on invalid iterator");
      }
      return m_ptr->data;
    }

    bool operator==(const DoubleLinkedListIterator& it) {
      return m_ptr == it.m_ptr;
    }

    bool operator!=(const DoubleLinkedListIterator& it) {
      return m_ptr != it.m_ptr;
    }

   private:
    Node* m_ptr;
  };

 public:
  DoubleLinkedList()
      : start(nullptr),
        endNode(nullptr),
        m_size(0){

        };

  void push_back(T data) {
    Node* elem = new Node{data, nullptr, nullptr};

    if (empty()) {
      m_size++;
      start = elem;
      endNode = elem;
      return;
    }

    m_size++;

    elem->prev = endNode;
    endNode->next = elem;
    endNode = elem;
  }
  void push_front(T data) {
    Node* elem = new Node{data, nullptr, nullptr};

    if (empty()) {
      m_size++;
      start = elem;
      endNode = elem;
      return;
    }

    m_size++;
    elem->next = start;
    start->prev = elem;
    start = elem;
  }
  void pop_back() {
    if (empty()) {
      throw std::invalid_argument("List already empty");
    }

    if (m_size == 1) {
      delete start;
      start = nullptr;
      endNode = nullptr;
      m_size--;
      return;
    }

    m_size--;
    Node* prev = endNode->prev;
    delete endNode;
    prev->next = nullptr;
  }
  void pop_front() {
    if (empty()) {
      throw std::invalid_argument("List already empty");
    }

    if (m_size == 1) {
      delete start;
      start = nullptr;
      endNode = nullptr;
      m_size--;
      return;
    }

    m_size--;
    Node* next = start->next;
    delete start;
    start = next;
  }

  bool empty() { return m_size == 0; }

  size_t size() { return m_size; }

  void remove(T data) {
    if (empty()) {
      return;
    }

    Node* cur = start;

    while (cur != nullptr) {
      if (cur->data == data) {
        if (cur->prev != nullptr) {
          cur->prev->next = cur->next;
        } else {
          start = cur->next;
        }

        if (cur->next != nullptr) {
          cur->next->prev = cur->prev;
        } else {
          endNode = cur->prev;
        }
        m_size--;
        delete cur;
        remove(data);
      }
      cur = cur->next;
    }
  }

  void print() const {
    Node* current = start;
    while (current != nullptr) {
      std::cout << current->data << " ";
      current = current->next;
    }
    std::cout << "\n";
  }

  int indexAt(T data) {
     int index = 0;
     Node* current = start;
     while (current != nullptr) {
       if (current->data == data) {
         return index;
       }
       current = current->next;
       ++index;
     }
     return -1;
   }



  bool find(T data) {
    Node* current = start;
    while (current != nullptr) {
      if (current->data == data) {
        return true;
      }
      current = current->next;
    }
    return false;
  }

  DoubleLinkedListIterator begin() { return DoubleLinkedListIterator(start); }

  DoubleLinkedListIterator end() { return DoubleLinkedListIterator(nullptr); }
};

#endif // DOUBLELINKEDLIST_H
