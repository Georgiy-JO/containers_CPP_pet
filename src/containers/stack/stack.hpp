
#pragma once

#include <iostream>
#include <stdexcept>

namespace my_containers {
template <typename T>
class Stack {
 public:
  using value_type = T;
  using reference = T &;
  using const_reference = const T &;
  using size_type = size_t;
  using pointer = T *;

 private:
  struct Node_ {
    value_type data{value_type()};
    Node_ *prev{nullptr};

   public:
    Node_(const value_type &data = value_type()) : data(data), prev(nullptr) {}
  };
  Node_ *top_{nullptr};
  size_type size_{0};

  inline void clean() noexcept;
  void clean_last() noexcept;
  inline void null_stack() noexcept;
  void reverse();

 public:
  Stack()
      : top_{nullptr},
        size_{0} {}  // default constructor, creates an empty Stack
  Stack(std::initializer_list<value_type> const
            &items);  // initializer list constructor, creates Stack
                      // initizialized using std::initializer_list
  Stack(const Stack &s) : Stack() { (*this) = s; }        // copy constructor
  Stack(Stack &&s) : Stack() { (*this) = std::move(s); }  // move constructor
  ~Stack() { clean(); }                                   // destructor

  inline const_reference top() const;  // accesses the top element
  bool empty() const {
    return top_ == nullptr;
  }  // checks whether the container is empty
  size_type size() const { return size_; }  // returns the number of elements
  void push(const_reference value);         // inserts an element at the top
  void pop();                               // removes the top element
  void swap(Stack &other) noexcept;         // swaps the contents
  Stack &operator=(
      Stack &&s);  // assignment operator overload for move an object
  Stack &operator=(
      const Stack &s);  // assignment operator overload for copying an object

  template <typename... Args>
  void insert_many_back(Args &&...args) {
    (push(std::forward<Args>(args)), ...);
  }
};
#include "stack.tpp"

}  // namespace my_containers
