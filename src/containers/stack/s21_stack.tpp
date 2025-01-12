#pragma once
template <typename T>
void Stack<T>::push(const_reference value){
    Node_* node_new{new Node_(value)};                  //std::bad_alloc exception
    node_new->prev = top_;
    top_ = node_new;
    size_++;
}

template <typename T>
void Stack<T>::clean_last() noexcept{
    if(top_) {
        Node_* prev_ptr= (*top_).prev;
        delete top_;
        top_=prev_ptr;
        size_--;
    }
}

template <typename T>
inline void Stack<T>::clean() noexcept{
    while(top_ )
        clean_last();
}

template <typename T>
void Stack<T>::pop(){
    if(!top_)
        throw std::out_of_range("Stack is empty");
    else 
        clean_last();
}

template <typename T>
void Stack<T>::swap(Stack&other) noexcept{
    Node_* temp = top_;
    top_ = other.top_;
    other.top_ = temp;
    size_t tmp=size_;
    size_=other.size_;
    other.size_=tmp;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack &&s){
    if(this != &s){
        clean();
        top_=s.top_;
        size_=s.size();
        s.null_stack();
    }
    return *this;
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack &s){
    if(this != &s){
        clean();
        Stack tmp;
        Node_* ptr=s.top_;
        while(ptr){
            tmp.push(ptr->data);
            ptr=ptr->prev;
        }
        tmp.reverse();
        *this=std::move(tmp);
    }
    return *this;
}

template <typename T>
void Stack<T>::reverse(){
    Stack<T> tmp;
    while(!empty()){
        tmp.push(top());
        pop();
    }
    (*this)=std::move(tmp);

}

template <typename T>
inline void Stack<T>::null_stack() noexcept{
    top_ = nullptr;
    size_ = 0;
}

template <typename T>
Stack<T>::Stack(std::initializer_list<value_type> const &items):Stack(){
    for(const auto& elem:items)
        push(elem);
}

template <typename T>
inline typename Stack<T>::const_reference Stack<T>::top() const{
    if(empty())
        throw std::out_of_range("Stack is empty");
    return top_->data;
} 