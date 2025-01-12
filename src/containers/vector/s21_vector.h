#ifndef S21_CONTAINERS_VECTOR_H
#define S21_CONTAINERS_VECTOR_H

#include <initializer_list>
#include <iostream>
#include <limits>

namespace s21 {
template <typename T>

class vector {
 private:
  T* data_;  // указатель на массив элементов типа T
  size_t capacity_;  // текущий максимальный размер вектора без необходимости
                     // реаллокации памяти.
  size_t size_;  // текущее количество элементов в векторе

 public:
  // Vector Member type
  using value_type = T;
  using reference = T&;
  using const_reference = const T&;
  using iterator = T*;
  using const_iterator = const T*;
  using size_type = size_t;

  // Vector Member functions
  vector() : data_(nullptr), capacity_(0), size_(0){};
  vector(size_type n);
  vector(std::initializer_list<value_type> const& items);
  // copy constructor
  vector(const vector& v);
  // move constructor
  vector(vector&& v);
  ~vector();
  vector& operator=(vector&& v);

  // Vector Element access
  // доступ к указанному элементу с проверкой границ
  reference at(size_type pos) { return data_[pos]; };
  // доступ к указанному элементу
  reference operator[](size_type pos) { return data_[pos]; };
  const_reference front() { return data_[0]; };
  const_reference back() { return data_[size_ - 1]; };
  // прямой доступ к базовому массиву
  T* data() { return data_; };

  // Vector Iterators
  iterator begin() { return data_; }
  iterator end() { return data_ + size_; }

  // Vector Capacity
  bool empty() const { return size_ == 0; }
  size_type size() const { return size_; }
  // возвращает максимально возможное количество элементов
  size_type max_size() const;
  // выделяет хранилище элементов и копирует текущие элементы массива в новый
  // выделенный массив
  void reserve(size_type size);
  // возвращает количество элементов, которые могут храниться в выделенном в
  // данный момент хранилище
  size_type capacity() const { return capacity_; };
  //	сокращает использование памяти за счет освобождения неиспользуемой
  // памяти
  void shrink_to_fit();

  // Vector Modifiers
  void clear();
  // вставляет элементы в конкретный pos и возвращает итератор, указывающий на
  // новый элемент
  iterator insert(iterator pos, const_reference value);
  // стирает элемент в точке pos
  void erase(iterator pos);
  // добавляет элемент в конец
  void push_back(const_reference value);
  //	удаляет последний элемент
  void pop_back();
  // меняет местами содержимое
  void swap(vector& other);

  // Insert many
  // Вставляет новые элементы в контейнер непосредственно перед pos.
  template <typename... Args>
  iterator insert_many(const_iterator pos, Args&&... args);
  // Добавляет новые элементы в конец контейнера
  template <typename... Args>
  void insert_many_back(Args&&... args);
};
}  // namespace s21

#include "s21_vector.tpp"
#endif