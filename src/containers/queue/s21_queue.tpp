#ifndef S21_CONTAINERS_QUEUE_TPP
#define S21_CONTAINERS_QUEUE_TPP

#include "s21_queue.h"

namespace s21 {
template <typename T>
queue<T>::queue() : data_(nullptr), tail_(nullptr), size_(0) {}

template <typename T>
queue<T>::queue(std::initializer_list<value_type> const& items)
    : data_(nullptr), tail_(nullptr), size_(0) {
  for (const auto& item : items) {
    Node* newNode = new Node(item);
    if (empty()) {
      data_ = tail_ = newNode;
    } else {
      tail_->next = newNode;
      tail_ = newNode;
    }

    size_++;
  }
}

template <typename T>
queue<T>::queue(const queue& q) : data_(nullptr), tail_(nullptr), size_(0) {
  Node* current = q.data_;
  while (current != nullptr) {
    push(current->data_);
    current = current->next;
  }
}

template <typename T>
queue<T>::queue(queue&& q) : data_(q.data_), tail_(q.tail_), size_(q.size_) {
  q.data_ = nullptr;
  q.tail_ = nullptr;
  q.size_ = 0;
}

template <typename T>
queue<T>::~queue() {
  while (data_) {
    Node* temp = data_;
    data_ = data_->next;
    delete temp;
  }
}

template <typename T>
queue<T>& queue<T>::operator=(queue<T>&& q) {
  if (this != &q) {
    data_ = std::exchange(q.data_, nullptr);
    tail_ = std::exchange(q.tail_, nullptr);
    size_ = std::exchange(q.size_, 0);
  }
  return *this;
}

template <typename T>
typename queue<T>::const_reference queue<T>::front() {
  if (!data_) throw std::out_of_range("Queue is empty");
  return data_->data_;
}

template <typename T>
typename queue<T>::const_reference queue<T>::back() {
  if (!data_) throw std::out_of_range("Queue is empty");
  return tail_->data_;
}

template <typename T>
void queue<T>::push(const_reference value) {
  Node* newNode = new Node(value);

  if (!data_) {
    data_ = newNode;
    tail_ = newNode;
  } else {
    tail_->next = newNode;
    tail_ = newNode;
  }

  ++size_;
}

template <typename T>
void queue<T>::pop() {
  if (empty()) throw std::out_of_range("Queue is empty");
  Node* temp = data_;
  data_ = data_->next;
  delete temp;
  size_--;
}

template <typename T>
void queue<T>::swap(queue<T>& other) {
  std::swap(data_, other.data_);
  std::swap(tail_, other.tail_);
  std::swap(size_, other.size_);
}

template <typename T>
template <typename... Args>
void queue<T>::insert_many_back(Args&&... args) {
  // Создаем временный список из переданных аргументов
  s21::vector<T> temp_args{std::forward<Args>(args)...};

  // Добавляем все элементы временного списка в очередь
  for (const auto& arg : temp_args) {
    push(arg);
  }
}

}  // namespace s21
#endif
