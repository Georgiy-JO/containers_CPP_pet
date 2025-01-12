#pragma once

template <typename Key_T, typename T>
typename Tree<Key_T, T>::iterator Tree<Key_T, T>::insertMult(
    const_key_type& key, const_value_type& value) {
  iterator result = insertMult(root_, key, value);
  size_++;
  addParents();
  return result;
}
template <typename Key_T, typename T>
typename Tree<Key_T, T>::node_* Tree<Key_T, T>::insertMult(
    node_*& root, const_key_type& key, const_value_type& value) {
  if (!root)
    return root = new node_(key);
  else {
    if (key == root->key_) {
      if (root->right_) {
        node_* tmp =
            new node_(root->right_->key_, root->right_->data_, root->right_);
        tmp->left_ = root->right_->left_;
        tmp->right_ = root->right_->right_;
        root->right_->right_ = tmp;
        root->right_->data_ = value;
        root->right_->key_ = key;
        root->right_->left_ = nullptr;
      } else
        return insertMult(root->right_, key, value);
    } else if (key < root->key_)
      return insertMult(root->left_, key, value);
    else
      return insertMult(root->right_, key, value);

    Tree<key_type, key_type>::balancerInsert(root, key);
    return root;
  }
}