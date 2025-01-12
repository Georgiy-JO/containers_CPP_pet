#pragma once

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const value_type& map_value) {
  return Tree<key_type, mapped_type>::insert(map_value.first, map_value.second);
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert(
    const Key& key, const T& obj) {
  return Tree<key_type, mapped_type>::insert(key, obj);
}
template <typename Key, typename T>
T& map<Key, T>::at(const Key& map_key) {
  if (!Tree<key_type, mapped_type>::contains(map_key))
    throw std::out_of_range("Element doesn't exist");
  return Tree<key_type, mapped_type>::find(map_key).getValue();
}

template <typename Key, typename T>
std::pair<typename map<Key, T>::iterator, bool> map<Key, T>::insert_or_assign(
    const Key& key, const T& obj) {
  iterator it = Tree<key_type, mapped_type>::find(key);
  if (it.assigned()) {
    Tree<key_type, mapped_type>::iterator::replaceVal(
        it, obj);  // may get errors here!
    return std::make_pair(it, false);
  } else
    return Tree<key_type, mapped_type>::insert(key, obj);
}

template <typename Key, typename T>
inline map<Key, T>& map<Key, T>::operator=(map&& m) {  // moving assignment
  Tree<key_type, mapped_type>::operator=(std::move(m));
  return *this;
}

template <typename Key, typename T>
inline map<Key, T>& map<Key, T>::operator=(map& m) {  // copy assignment
  Tree<key_type, mapped_type>::operator=(m);
  return *this;
}

template <typename Key, typename T>
void map<Key, T>::swap(map& other) {
  Tree<key_type, mapped_type>::swap(other);
}

template <typename Key, typename T>
void map<Key, T>::merge(map& other) {
  Tree<key_type, mapped_type>::merge(other);
}

template <typename Key, typename T>
T& map<Key, T>::operator[](const Key& map_key) {
  iterator it = Tree<key_type, mapped_type>::find(map_key);
  if (!it.assigned()) {
    return insert(map_key, mapped_type()).first.getValue();
  }
  return it.getValue();
}

template <typename Key, typename T>
template <typename... Args>
my_containers::vector<std::pair<typename map<Key, T>::iterator, bool>>
map<Key, T>::insert_many(Args&&... args) {
  my_containers::vector<std::pair<typename map<Key, T>::iterator, bool>> res;
  (res.push_back(insert(std::forward<Args>(args))), ...);
  return res;
}
