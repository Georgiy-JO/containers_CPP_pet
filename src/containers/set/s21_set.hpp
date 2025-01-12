#pragma once

#include <iostream>

#include "../AVLtree/avl_tree.hpp"

namespace s21 {
template <typename Key>
class set : public Tree<Key, Key> {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type &;
  using const_reference = const value_type &;
  using iterator = typename Tree<Key, Key>::iterator_;
  using const_iterator = typename Tree<Key, Key>::constIterator_;
  using size_type = size_t;

  set() : Tree<value_type, value_type>() {}
  set(std::initializer_list<value_type> const &items)
      : Tree<value_type, value_type>(items) {}
  set(const set &s) : Tree<value_type, value_type>(s) {}
  set(set &&s) : Tree<value_type, value_type>(std::move(s)) {}
  ~set() { Tree<value_type, value_type>::clear(); }

  /*
   * Functions and operators that are defined in Tree class and can be used here
   * bool empty();              //  checks if the set is empty
   * void clear();              //  clear the set
   * size_type size();          //  ammount of set elements
   * size_type max_size();      //  returns the maximum possible
   * number of elements void erase(iterator pos)  //  erases an
   element at "pos"
   * std::pair<iterator, bool> insert(const value_type& value);  //  inserts
   a node, returns iterator to it and success flag iterator
   * find(const Key& key);      //  finds an element with a specific key bool
   * contains(const Key& key)   //  checks if the container contains an
   element with a specific key iterator
   * begin();                   // returns an iterator to the beginning iterator
   * end();                     //  returns an iterator to the end
   * s21::vector<std::pair<iterator,bool>> insert_many(Args&&... args);
   //inserts several new elements into the container
   */

  inline set &operator=(set &&s) {  // move assignment
    Tree<value_type, value_type>::operator=(std::move(s));
    return *this;
  }
  inline set &operator=(const set &s) {  // copy assignment
    Tree<value_type, value_type>::operator=(s);
    return *this;
  }

  void swap(set &other) {
    Tree<value_type, value_type>::swap(other);
  }  // swaps the contents
  void merge(set &other) {
    Tree<value_type, value_type>::merge(other);
  }  // splices nodes from another container
};

}  // namespace s21