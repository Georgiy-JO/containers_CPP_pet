#ifndef CONTAINERS_VECTOR_TPP
#define CONTAINERS_VECTOR_TPP

#include "vector.h"

namespace my_containers {

template <typename T>
vector<T>::vector(size_type n) : data_(new T[n]), capacity_(n), size_(n) {
  std::fill_n(data_, n, value_type());
}

template <typename T>
vector<T>::vector(std::initializer_list<value_type> const &items)
    : data_(new value_type[items.size()]),
      capacity_(items.size()),
      size_(items.size()) {
  std::copy(items.begin(), items.end(), data_);
}

template <typename T>
vector<T>::vector(const vector &v)
    : data_(new T[v.size_]), capacity_(v.capacity_), size_(v.size_) {
  std::copy(v.data_, v.data_ + v.size_, data_);
}

template <typename T>
vector<T>::vector(vector &&v)
    : data_(v.data_), capacity_(v.capacity_), size_(v.size_) {
  v.data_ = nullptr;
  v.capacity_ = 0;
  v.size_ = 0;
}

template <typename T>
vector<T>::~vector() {
  delete[] data_;
  data_ = nullptr;
  capacity_ = 0;
  size_ = 0;
}

template <typename T>
vector<T> &vector<T>::operator=(vector<T> &&v) {
  if (this != &v) {
    data_ = v.data_;
    capacity_ = v.capacity_;
    size_ = v.size_;
    v.data_ = nullptr;
    v.capacity_ = 0;
    v.size_ = 0;
  }
  return *this;
}

template <typename T>
typename vector<T>::size_type vector<T>::max_size() const {
  return std::numeric_limits<std::size_t>::max() / sizeof(value_type) / 2;
}

template <typename T>
void vector<T>::reserve(size_type new_capacity) {
  if (new_capacity > capacity_) {
    T *new_data = new T[new_capacity];
    std::copy(data_, data_ + size_, new_data);
    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
  }
}

template <typename T>
void vector<T>::shrink_to_fit() {
  if (size_ < capacity_) {
    T *new_data = new T[size_];
    std::copy(data_, data_ + size_, new_data);
    delete[] data_;
    data_ = new_data;
    capacity_ = size_;
  }
}

template <typename T>
void vector<T>::clear() {
  for (size_type i = 0; i < size_; i++) data_[i] = 0;
  size_ = 0;
}

template <typename T>
typename vector<T>::iterator vector<T>::insert(iterator pos,
                                               const_reference value) {
  size_type index = pos - begin();
  if (size_ == capacity_) reserve(capacity_ * 2);
  for (size_type i = size_; i > index; i--) {
    data_[i] = data_[i - 1];
  }
  data_[index] = value;
  size_++;
  return begin() + index;
}

template <typename T>
void vector<T>::erase(iterator pos) {
  size_type index = pos - begin();
  for (size_type i = index; i < size_ - 1; i++) data_[i] = data_[i + 1];
  size_--;
}

template <typename T>
void vector<T>::push_back(const_reference value) {
  if (size_ == capacity_)
    (capacity_ == 0) ? reserve(1) : reserve(capacity_ * 2);
  data_[size_++] = value;
}

template <typename T>
void vector<T>::pop_back() {
  if (size_ > 0) {
    data_[size_ - 1] = 0;
    size_--;
  }
}

template <typename T>
void vector<T>::swap(vector<T> &other) {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

template <typename T>
template <typename... Args>
typename vector<T>::iterator vector<T>::insert_many(const_iterator pos,
                                                    Args &&...args) {
  size_type index = pos - begin();
  size_type args_count = sizeof...(Args);

  // Обеспечиваем емкость
  if (size_ + args_count > capacity_) {
    reserve(size_ + args_count);
  }

  // Сдвигаем элементы вправо для создания места для новых
  for (size_type i = size_ + args_count - 1; i > index + args_count - 1; --i) {
    data_[i] = std::move(data_[i - args_count]);
  }

  size_type i = 0;
  (void)std::initializer_list<int>{
      ((data_[index + i++] = std::forward<Args>(args)), 0)...};

  size_ += args_count;

  return begin() + index;
}

template <typename T>
template <typename... Args>
void vector<T>::insert_many_back(Args &&...args) {
  size_type args_count = sizeof...(Args);

  // Обеспечить емкость
  if (size_ + args_count > capacity_) {
    reserve(size_ + args_count);
  }

  // Вставляем новые элементы в конец
  size_type i = 0;
  (void)std::initializer_list<int>{
      ((data_[size_ + i++] = std::forward<Args>(args)), 0)...};
  size_ += args_count;
}

}  // namespace my_containers

#endif