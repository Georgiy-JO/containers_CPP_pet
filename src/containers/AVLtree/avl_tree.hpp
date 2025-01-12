#pragma once

#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <typeinfo>

#include "../stack/stack.hpp"
#include "../vector/vector.h"

namespace my_containers {
template <typename Key_T, typename T>
class Tree {
 private:
  class node_;

 public:
  class iterator_;
  class constIterator_;

 public:
  using value_type = T;
  using key_type = Key_T;
  using const_key_type = const Key_T;
  using const_value_type = const T;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;
  using pointer = T*;
  using const_pointer = const T*;
  using iterator = iterator_;
  using constIterator = constIterator_;

 private:
  class node_ {
   public:
    key_type key_;
    value_type data_{value_type()};
    node_* left_{nullptr};
    node_* right_{nullptr};
    node_* parent_{nullptr};
    node_() = default;
    node_(const key_type& key, node_* parent = nullptr)
        : key_{key}, data_{key}, parent_{parent} {}
    node_(const key_type& key, const value_type& data, node_* parent = nullptr)
        : key_{key}, data_{data}, parent_{parent} {}
  };
  node_* root_{nullptr};
  size_type size_{0};

  node_* find_(node_* root, const_key_type& key) const;
  node_* find__(node_* root, const_value_type& value) const;
  inline node_* find_(const_key_type& key) const { return find_(root_, key); }
  inline node_* find__(const_value_type& value) const {
    return find__(root_, value);
  }

  void addParents(node_*& root);
  void addParents();
  inline node_* getParent(const_key_type& key) const;

  node_* remove(node_*& root, const_key_type& key);
  inline void removeNode(node_*& root);
  inline int getBalanceFactor(const node_* node) const;
  bool insert(node_*& root, const_key_type& key, const_value_type& value);
  void balancerInsert(node_*& root, const_key_type& key);
  void balancerRemove(node_*& root);
  void rotateLeft(node_*& root);
  void rotateRight(node_*& root);
  unsigned int getHight(const node_* root) const;

  void clear(node_*& root);
  void setNull();
  void copyTreeNode(const node_* from, node_*& to) const;

  static node_* getBeginig(node_* root);
  static node_* getEnd(node_* root);
  Stack<key_type>& getTree(const node_* node, Stack<key_type>& stack) const;
  std::pair<Stack<key_type>, Stack<value_type>>& getTree(
      const node_* node,
      std::pair<Stack<key_type>, Stack<value_type>>& stack) const;

 protected:
  const node_* getBeginig() const { return getBeginig(root_); }
  const node_* getEnd() const { return getEnd(root_); }

 public:
  inline Tree() : root_{nullptr}, size_{0} {}
  inline Tree(const_key_type key) : Tree(key, key) {}
  inline Tree(const_key_type key, const_value_type value) : Tree() {
    insert(key, value);
  }
  Tree(std::initializer_list<key_type> const& items);
  Tree(std::initializer_list<std::pair<key_type, value_type>> const& items);
  Tree(const Tree& other) : Tree() { (*this) = other; }        // copy
  Tree(Tree&& other) : Tree() { (*this) = std::move(other); }  // move
  inline ~Tree() { clear(); }

  Tree& operator=(const Tree& other);  // copy
  Tree& operator=(Tree&& other);       // move

  inline bool contains(const_key_type key) const { return find_(key) ? 1 : 0; }
  inline bool containsVal(const_value_type value) const {
    return find__(value) ? 1 : 0;
  }
  inline iterator find(const_key_type& key) const;

  std::pair<iterator, bool> insert(const_key_type& key) {
    return insert(key, key);
  }
  std::pair<iterator, bool> insert(const_key_type& key,
                                   const_value_type& value);
  void remove(const_key_type key) { root_ = remove(root_, key); }
  void erase(iterator pos) {
    if (pos.assigned()) remove(pos.getKey());
  }

  void swap(Tree& other) noexcept;
  void merge(Tree& other);

  inline bool empty() { return root_ == nullptr; }
  inline size_type max_size() const noexcept;
  inline size_type size() { return size_; }
  inline void clear() { clear(root_); }
  void copyTree(Tree<Key_T, T>& TO) const;

  iterator_ begin() { return iterator_(getBeginig(root_)); }
  iterator_ end() { return iterator_(getEnd(root_)); }
  constIterator cbegin() const { return getBeginig(root_); }
  constIterator cend() const { return getEnd(root_); }

  // extra functions
  void showTreeVertical();
  void showTreeVertical(const node_* node);
  void showTreeVerticalVal();
  void showTreeVerticalVal(const node_* node);
  Stack<key_type>& getTree(Stack<key_type>& stack) const {
    return getTree(root_, stack);
  }
  std::pair<Stack<key_type>, Stack<value_type>>& getTree(
      std::pair<Stack<key_type>, Stack<value_type>>& stack) const {
    return getTree(root_, stack);
  }
  key_type getParentData(const_key_type key) const;
  void crazyPrinter(const node_* root) const;
  void crazyPrinter() const { crazyPrinter(root_); }

  // bonus functions
  template <typename... Args>
  my_containers::vector<std::pair<iterator, bool>> insert_many(Args&&... args);
  iterator insertMult(const_key_type& key) { return insertMult(key, key); }
  iterator insertMult(const_key_type& key, const_value_type& value);
  node_* insertMult(node_*& root, const_key_type& key, const_value_type& value);

  friend class iterator_;
  class iterator_ {
    node_* element_{nullptr};
    node_* getNext() { return element_ ? getNext(element_) : nullptr; }
    node_* getNext(node_* node);
    node_* getPrev() { return element_ ? getPrev(element_) : nullptr; }
    node_* getPrev(node_* node);
    inline void ifElement() const;

   public:
    friend class constIterator_;
    iterator_(node_* element = nullptr) : element_{element} {}
    iterator_(const iterator_& other) : iterator_(other.element_) {}
    iterator_& operator=(const iterator_& other);
    iterator_& operator=(const Tree<Key_T, T>& tree);
    iterator_& operator=(const node_*& node);
    iterator_& operator++();
    iterator_& operator--();
    iterator_& operator+=(int n);
    iterator_& operator-=(int n);
    iterator_ operator++(int);
    iterator_ operator--(int);
    auto operator*() const { return getValue(); }
    bool operator==(const iterator_& other) const {
      return element_ == other.element_;
    }
    bool operator!=(const iterator_& other) const {
      return element_ != other.element_;
    }

    inline value_type& getValue() const;  // const_value_type& ?
    inline const_key_type& getKey() const;
    auto getPair() const;
    bool assigned() const { return element_ != nullptr; }
    static void replaceVal(iterator_& it, const_value_type& value) {
      if (it.element_) it.element_->data_ = value;
    }
  };

  class constIterator_ : public iterator_ {
   public:
    constIterator_(node_* element = nullptr) : iterator_(element) {}
    constIterator_(const iterator_& other) : iterator_(other.element_) {}
    constIterator_(const constIterator_& other) : iterator_(other.element_) {}
    auto operator*() const { return iterator_::operator*(); }
    bool operator==(const iterator_& other) const {
      return iterator_::operator==(other);
    }
    bool operator!=(const iterator_& other) const {
      return iterator_::operator!=(other);
    }
    constIterator_& operator=(const constIterator_& other);
  };
};

#include "avl_tree.tpp"
// Iterator
#include "avl_tree_irterator.tpp"
// Multiset module
#include "avl_tree_multiset.tpp"

//* end() - is not standart
}  // namespace my_containers
