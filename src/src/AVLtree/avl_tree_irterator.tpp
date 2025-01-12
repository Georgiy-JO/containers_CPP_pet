#pragma once

template <typename T>
typename Tree<T>::node_* Tree<T>::iterator_::getNext(node_* node){
    if(!node)
        return nullptr;
    if(node->right_)
        node= getBeginig(node->right_);
    else if(node->parent_){
        node_* parent = node->parent_;
        node_* local=node;
        while (parent && local == parent->right_) {
            local = parent;
            parent = parent->parent_;
            if(!parent->parent_)
                break;
        }
        if(parent->data_>node->data_)
            node= parent;
    }
    return node;
}

template <typename T>
typename Tree<T>::node_* Tree<T>::iterator_::getPrev( node_* node){
    if(!node)
        return nullptr;
    if(node->left_)
        node= getEnd(node->left_);
    else if(node->parent_){
        node_* parent = node->parent_;
        node_* local=node;
        while (parent && local == parent->left_) {
            local = parent;
            parent = parent->parent_;
            if(!parent->parent_)
                break;
        }
        if(parent->data_<node->data_)
            node= parent;
    }
    return node;
}


template <typename T>
typename Tree<T>::iterator_& Tree<T>::iterator_::operator=(const iterator_& other){
    element_=other.element_;
    return *this;
}

template <typename T>
typename Tree<T>::iterator_& Tree<T>::iterator_::operator=(const Tree<T>& tree){
    element_=tree.root_;
    return *this;
}

template <typename T>
typename Tree<T>::iterator_& Tree<T>::iterator_::operator=(const node_*& node){
    element_=node;
    return *this;
}

template <typename T>
typename Tree<T>::iterator_& Tree<T>::iterator_::operator++(){
    element_=getNext(element_);
    return *this;
}

template <typename T>
typename Tree<T>::iterator_& Tree<T>::iterator_::operator--(){
    element_=getPrev(element_);
    return *this;
}

template <typename T>
typename Tree<T>::iterator_& Tree<T>::iterator_::operator+=(int n){
    
    if(n>=0){
        while(n ){
            element_ = getNext(element_);
            n--;
        }
    }
    else
        operator-=(-n);
    return *this;
}

template <typename T>
typename Tree<T>::iterator_& Tree<T>::iterator_::operator-=(int n){
    if(n>=0){
        while(n ){
            element_=getPrev(element_);
            n--;
        }
    }
    else
        operator+=(-n);
    return *this;
}

template <typename T>
typename Tree<T>::iterator_ Tree<T>::iterator_::operator++(int){
    iterator_ temp = *this;
  operator++();
  return temp;
}

template <typename T>
typename Tree<T>::iterator_ Tree<T>::iterator_::operator--(int){
    iterator_ temp = *this;
    operator--();
    return temp;
}

template <typename T>
typename Tree<T>::const_reference Tree<T>::iterator_::operator*()const{
    if(!element_)
        throw std::out_of_range("Iterator is out of range");    
    return element_->data_;

}

// template <typename T>
// typename Tree<T>::const_pointer Tree<T>::iterator_::operator->()const{
//     if(!element_)
//         throw std::out_of_range("Iterator is out of range");  
//     return &(element_->data_);
// }

