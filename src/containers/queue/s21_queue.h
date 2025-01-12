#ifndef S21_CONTAINERS_QUEUE_H
#define S21_CONTAINERS_QUEUE_H

#include <initializer_list>
#include <iostream>

#include "../vector/s21_vector.h"

namespace s21 {
template <typename T>

class queue {
 private:
  struct Node {
    T data_;
    Node* next;

    Node(const T& data) : data_(data), next(nullptr) {}
  };

  Node* data_;
  Node* tail_;
  size_t size_;

 public:
  // Queue Member type
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

  // Queue Member functions
  queue();
  queue(std::initializer_list<value_type> const& items);
  // copy constructor
  queue(const queue& q);
  // move constructor
  queue(queue&& q);
  ~queue();
  queue& operator=(queue&& q);

  // Queue Element access
  const_reference front();
  const_reference back();

  // Queue Capacity
  bool empty() const { return size_ == 0; };
  size_type size() const { return size_; };

  // Queue Modifiers
  void push(const_reference value);
  void pop();
  void swap(queue& q);

  // Insert many
  template <typename... Args>
  void insert_many_back(Args&&... args);
};
}  // namespace s21

#include "s21_queue.tpp"
#endif