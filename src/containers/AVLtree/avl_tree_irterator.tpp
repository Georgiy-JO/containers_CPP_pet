#pragma once

template <typename Key_T, typename T>
typename Tree<Key_T, T>::node_* Tree<Key_T, T>::iterator_::getNext(
    node_* node) {
  if (!node) return nullptr;
  if (node->right_)
    node = getBeginig(node->right_);
  else if (node->parent_) {
    node_* parent = node->parent_;
    node_* local = node;
    while (parent && local == parent->right_) {
      local = parent;
      parent = parent->parent_;
      if (!parent->parent_) break;
    }
    if (parent->key_ > node->key_)
      node = parent;
    else
      node = nullptr;
  }
  return node;
}

template <typename Key_T, typename T>
typename Tree<Key_T, T>::node_* Tree<Key_T, T>::iterator_::getPrev(
    node_* node) {
  if (!node) return nullptr;
  if (node->left_)
    node = getEnd(node->left_);
  else if (node->parent_) {
    node_* parent = node->parent_;
    node_* local = node;
    while (parent && local == parent->left_) {
      local = parent;
      parent = parent->parent_;
      if (!parent->parent_) break;
    }
    if (parent->key_ < node->key_)
      node = parent;
    else
      node = nullptr;
  }
  return node;
}

template <typename Key_T, typename T>
typename Tree<Key_T, T>::iterator_& Tree<Key_T, T>::iterator_::operator=(
    const iterator_& other) {
  element_ = other.element_;
  return *this;
}

template <typename Key_T, typename T>
typename Tree<Key_T, T>::iterator_& Tree<Key_T, T>::iterator_::operator=(
    const Tree<Key_T, T>& tree) {
  element_ = tree.root_;
  return *this;
}

template <typename Key_T, typename T>
typename Tree<Key_T, T>::iterator_& Tree<Key_T, T>::iterator_::operator=(
    const node_*& node) {
  element_ = node;
  return *this;
}

template <typename Key_T, typename T>
typename Tree<Key_T, T>::constIterator_&
Tree<Key_T, T>::constIterator_::operator=(const constIterator_& other) {
  if (this != &other) {
    Tree<Key_T, T>::iterator_::operator=(other);
  }
  return *this;
}

template <typename Key_T, typename T>
typename Tree<Key_T, T>::iterator_& Tree<Key_T, T>::iterator_::operator++() {
  element_ = getNext(element_);
  return *this;
}

template <typename Key_T, typename T>
typename Tree<Key_T, T>::iterator_& Tree<Key_T, T>::iterator_::operator--() {
  element_ = getPrev(element_);
  return *this;
}

template <typename Key_T, typename T>
typename Tree<Key_T, T>::iterator_& Tree<Key_T, T>::iterator_::operator+=(
    int n) {
  if (n >= 0) {
    while (n) {
      element_ = getNext(element_);
      n--;
    }
  } else
    operator-=(-n);
  return *this;
}

template <typename Key_T, typename T>
typename Tree<Key_T, T>::iterator_& Tree<Key_T, T>::iterator_::operator-=(
    int n) {
  if (n >= 0) {
    while (n) {
      element_ = getPrev(element_);
      n--;
    }
  } else
    operator+=(-n);
  return *this;
}

template <typename Key_T, typename T>
typename Tree<Key_T, T>::iterator_ Tree<Key_T, T>::iterator_::operator++(int) {
  iterator_ temp = *this;
  operator++();
  return temp;
}

template <typename Key_T, typename T>
typename Tree<Key_T, T>::iterator_ Tree<Key_T, T>::iterator_::operator--(int) {
  iterator_ temp = *this;
  operator--();
  return temp;
}

template <typename Key_T, typename T>
auto Tree<Key_T, T>::iterator_::getPair() const {
  ifElement();
  return std::make_pair(const_cast<const_key_type&>(element_->key_),
                        const_cast<const_value_type&>(element_->data_));
}

template <typename Key_T, typename T>
inline typename Tree<Key_T, T>::const_key_type&
Tree<Key_T, T>::iterator_::getKey() const {
  ifElement();
  return element_->key_;
}
template <typename Key_T, typename T>
inline typename Tree<Key_T, T>::value_type&
Tree<Key_T, T>::iterator_::getValue() const {
  ifElement();
  return element_->data_;
}

template <typename Key_T, typename T>
inline void Tree<Key_T, T>::iterator_::ifElement() const {
  if (!element_)
    throw std::out_of_range(
        "Iterator is out of range");  // exception is better than undefined
                                      // behavior
}
