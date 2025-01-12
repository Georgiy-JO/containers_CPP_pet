#pragma once

#include <iostream>

#include "../AVLtree/avl_tree.hpp"
#include "../vector/s21_vector.h"

namespace s21 {
template <typename Key, typename T>
class map : public Tree<Key, T> {
 public:
  using key_type = Key;
  using mapped_type = T;
  using value_type = std::pair<key_type, mapped_type>;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = typename Tree<Key, T>::iterator_;
  using const_iterator = typename Tree<Key, T>::constIterator_;
  using size_type = size_t;

  map() : Tree<key_type, mapped_type>() {}
  map(std::initializer_list<value_type> const& items)
      : Tree<key_type, mapped_type>(items) {}
  map(const map& m) : Tree<key_type, mapped_type>(m) {}  // copy constructor
  map(map&& m)
      : Tree<key_type, mapped_type>(std::move(m)) {}  // move constructor
  ~map() { Tree<key_type, mapped_type>::clear(); }

  inline map& operator=(map&& m);  // moving assignment
  inline map& operator=(map& m);   // copy assignment
  std::pair<iterator, bool> insert_or_assign(
      const Key& key,
      const T& obj);  // inserts an element or assigns to the current element if
                      // the key already exists
  std::pair<iterator, bool> insert(const value_type& value);
  std::pair<iterator, bool> insert(
      const Key& key,
      const T& obj);  // inserts a value by key and returns an iterator and flag
  T& at(const Key& key);
  T& operator[](const Key& map_key);
  void swap(map& other);   // swaps the contents
  void merge(map& other);  // splices nodes from another container

  /*
   * Functions and operators that are defined in Tree class and can be used for
   * iterator begin()	//returns an iterator to the beginning
   * iterator end()	//returns an iterator to the end
   * bool empty()	    //checks whether the container is empty
   * size_type size()	    //returns the number of elements
   * size_type max_size()	    //returns the maximum possible
   *number of elements ok*        * void clear()	    //clears the
   *contents ok*        * void erase(iterator pos)	    //erases an element
   *at pos ok*        * bool contains(const Key& key)	    //checks if there is
   *an element with key equivalent to key in the container
   */

  template <typename... Args>
  vector<std::pair<iterator, bool>> insert_many(
      Args&&... args);  // insert undefined ammount of elements
};
#include "s21_map.tpp"

}  // namespace s21
