#pragma once

#include <iostream>

#include "../set/set.hpp"
#include "../vector/vector.h"

namespace my_containers {
template <typename Key>
class multiset : public set<Key> {
 public:
  using key_type = Key;
  using value_type = Key;
  using reference = value_type&;
  using const_reference = const value_type&;
  using iterator = typename Tree<Key, Key>::iterator_;
  using const_iterator = typename Tree<Key, Key>::constIterator_;
  using size_type = size_t;

  multiset();
  multiset(std::initializer_list<value_type> const& items);
  multiset(const multiset& s);
  multiset(multiset&& s);
  ~multiset();

  inline multiset& operator=(multiset&& s);       // move assignment
  inline multiset& operator=(const multiset& s);  // copy assignment
  /*
  * Functions and operators that are defined in set/Tree classes
  * bool empty();                 //  checks if the multiset is empty
  * void clear();                 //  clear the multiset
  * size_type size();             //  ammount of multiset elements
  * size_type max_size();         //  returns the maximum possible number of
  elements
  * iterator begin();             //  returns an iterator to the beginning
  * iterator end();               //  returns an iterator to the end

  * void erase(iterator pos);	  // erases an element at "pos"
  * iterator find(const Key& key);//  finds an element with a specific key
  * bool contains(const Key& key);//  checks if the container contains an
  element with a specific key
  */

  iterator insert(
      const value_type& value);  //  inserts a node, returns iterator to it
  std::pair<iterator, iterator> equal_range(
      const Key& key);  // returns range of elements matching a specific key
  iterator lower_bound(const Key& key);  // returns an iterator to the first
                                         // element not less than the given key
  iterator upper_bound(const Key& key);  // returns an iterator to the first
                                         // element greater than the given key
  size_type count(const Key& key);  // returns the number of elements matching a
                                    // specific key
  void swap(multiset& other);       // swaps the contents
  void merge(multiset& other);      // splices nodes from another container //!
  template <typename... Args>
  my_containers::vector<iterator> insert_many(
      Args&&... args);  // Inserts several new elements into the container
};

#include "multiset.tpp"
}  // namespace my_containers