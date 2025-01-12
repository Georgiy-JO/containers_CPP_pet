#pragma once


template <typename T>
void Tree<T>::insert(const Tree<T>::value_type &value){
    if (insert(root_,value)){
        size_++;
        addParents();
        
    }
}

template <typename T>
bool Tree<T>::insert(node_ *& root,const Tree<T>::value_type& value){
    bool flag = true;
    if(!root)
        root = new node_(value);
    else{
        if(value==root->data_)
            flag = false;
        else if(value < root->data_)
            flag =insert(root->left_,value);
        else
            flag =insert(root->right_,value);
        
        if(flag){
            // root->hight_=getHight(root);
            // std::cout<<root->data_<<":"<<root->hight_<<std::endl;
            balancerInsert(root,value);
        }
    }
    return flag;
}

// template <typename T>
// unsigned int Tree<T>::hightCounter(node_ * root){
//     if(!root)
//         root->hight_=1;
//     else
//         root->hight_=1+std::max(hightCounter(root->left_),hightCounter(root->right_));
//     return root->hight_;
// }

template <typename T>
void Tree<T>::balancerInsert(node_ *& root,const Tree<T>::value_type &value){
    int delta=getBalanceFactor(root);

    if(delta>1 && root->left_ && value < root->left_->data_)
        rotateRight(root);
    else if(delta<-1 && root->right_ && value > root->right_->data_)
        rotateLeft(root);
    else if(delta>1 && root->left_ && value > root->left_->data_) {
        rotateLeft(root->left_);
        rotateRight(root);
    }
    else if(delta<-1 && root->right_ && value<root->right_->data_){
        rotateRight(root->right_);
        rotateLeft(root);
    }
}

template <typename T>
void Tree<T>::rotateLeft(node_ *& root){
      node_* tmp_ptr=root;
      root=root->right_;
      tmp_ptr->right_=root->left_;
      root->left_=tmp_ptr;
}
template <typename T>
void Tree<T>::rotateRight(node_ *& root){
      node_* tmp_ptr=root;
      root=root->left_;
      tmp_ptr->left_=root->right_;
      root->right_=tmp_ptr;
}

template <typename T>
unsigned int Tree<T>::getHight(const node_* root) const{
    if(!root)
        return 0;
    unsigned int h_left=(root->left_)?getHight(root->left_):0;
    unsigned int h_right=(root->right_)?getHight(root->right_):0;
    return 1+std::max(h_left,h_right);
}

template <typename T>
void Tree<T>::clear(node_*& root){
    if(root){
        if(root->right_)
            clear(root->right_);
        if (root->left_)
            clear(root->left_);
        removeNode(root);
    }
}

template <typename T>
typename Tree<T>::node_* Tree<T>::find(node_ * root, const value_type &value) const{
    if(!root)
        return nullptr;
    if(value==root->data_)
        return root;
    if(value<root->data_)
        return find(root->left_, value);
    return find(root->right_, value);
}

template <typename T>
void Tree<T>::addParents(node_*& root){
    if(root){
        if (root->left_)
            root->left_->parent_=root;
        if (root->right_)
            root->right_->parent_=root;    
        addParents(root->left_);
        addParents(root->right_);
    }
}

template <typename T>
void Tree<T>::showTreeVertical(const node_ *node){
    if(node){
        showTreeVertical(node->left_);
        std::cout<<node->data_<<" ";
        showTreeVertical(node->right_);
    }
}
template <typename T>
void Tree<T>::showTreeVertical(){
    showTreeVertical(root_);
    std::cout<<std::endl;
}

template <typename T>
Tree<T>::Tree(std::initializer_list<value_type> const &items):Tree(){
    for(const auto& i:items )
        insert(i);
}

template <typename T>
void Tree<T>::swap(Tree& other) noexcept{
    node_* tmp=other.root_;
    other.root_=root_;
    root_=tmp;
    std::swap(size_, other.size_);
}

template <typename T>
Tree<T>& Tree<T>::operator=(Tree &&other){
    if(this!=&other){
        clear();
        root_=other.root_;
        size_=other.size_;
        other.setNull();
    }
    return *this;
}

template <typename T>
Tree<T>& Tree<T>::operator=(const Tree &other){
    if(this!=&other){
        clear();
        Tree new_tree;
        other.copyTree(new_tree);
        swap(new_tree);
    }
    return *this;
}

template <typename T>
void Tree<T>::setNull(){
    if(root_){
        root_=nullptr;
        size_=0;
    }
}

template <typename T>
Stack<T>& Tree<T>::getTree(const node_ *node,Stack<T>& stack)const{
    if(node){
        getTree(node->left_,stack);
        stack.push(node->data_);
        getTree(node->right_,stack);
    }
    return stack;
}

template <typename T>
void Tree<T>::copyTreeNode(const node_* from,node_*& to) const{
    if(from){
        if(!to)
            to=new node_;
        copyTreeNode(from->left_,to->left_);
        to->data_=from->data_;
        to->parent_=nullptr;
        copyTreeNode(from->right_,to->right_);
    }
}
template <typename T>
void Tree<T>::copyTree(Tree<T>& TO) const{
    if(root_){
        copyTreeNode(root_,TO.root_);
        TO.size_=size_;
    }
}

template <typename T>
typename Tree<T>::node_* Tree<T>::remove(node_ *& root, const value_type &value){
    if(!root)
        return root;
    if(value<root->data_)
        root->left_=remove(root->left_,value);
    else if (value>root->data_)
        root->right_=remove(root->right_,value);
    else{
        node_ * tmp;
        if(!root->right_){
            tmp=root->left_;
            removeNode(root);
            return tmp;
        }
        else if(!root->left_){
            tmp=root->right_;
            removeNode(root);
            return tmp;
        }
        //(root->left_ && root->right_)
        tmp=getBeginig(root->right_);
        root->data_=tmp->data_;
        root->right_=remove(root->right_,tmp->data_);
    }
    addParents();
    balancerRemove(root);
    return root;
}

template <typename T>
void Tree<T>::balancerRemove(node_ *& root){

    int delta=getBalanceFactor(root);
    if(delta>1 && root->left_ && getBalanceFactor(root->left_)>=0)
        rotateRight(root);
    else if(delta<-1 && root->right_ && getBalanceFactor(root->right_)<=0)
        rotateLeft(root);
    else if(delta>1 && root->left_ && getBalanceFactor(root->left_)<0) {
        rotateLeft(root->left_);
        rotateRight(root);
    }
    else if(delta<-1 && root->right_ && getBalanceFactor(root->right_)>0){
        rotateRight(root->right_);
        rotateLeft(root);
    }
}

template <typename T>
inline void Tree<T>::removeNode(node_ *& node){
    delete node;
    node=nullptr;
    size_--;
}

template <typename T>
inline int Tree<T>::getBalanceFactor(const node_ * node)const{
    if(!node)
        return 0;
    return getHight(node->left_)-getHight(node->right_);
}

template <typename T>
inline typename Tree<T>::size_type Tree<T>::max_size() const noexcept {
    return std::numeric_limits<size_type>::max() / sizeof(Tree<T>::node_);
}

template <typename T>
inline typename  Tree<T>::node_* Tree<T>::getParent(const value_type &value)const{
    node_* tmp=find(value);
    if(tmp)
        return find(value)->parent_; 
    return nullptr;
 }
template <typename T>
typename Tree<T>::value_type Tree<T>::getParentData(const value_type &value)const{
    node_* tmp=getParent(value);
    if(!tmp)
        throw std::out_of_range("No parents found");
    return tmp->data_;
}

template <typename T>
void Tree<T>::crazyPrinter(const node_* root)const{
    if(root){
        std::cout<<"Node:"<<root->data_<<":   Parent:";    
        if (root->parent_)
            std::cout<<root->parent_->data_<<";   Left:";
        else
            std::cout<<"NULL"<<";   Left:";
        if(root->left_)
            std::cout<<root->left_->data_<<";   Right:";
        else
            std::cout<<"NULL"<<";   Right:";
        if(root->right_)
            std::cout<<root->right_->data_<<"."<<std::endl;
        else
            std::cout<<"NULL"<<"."<<std::endl;
        crazyPrinter(root->left_);
        crazyPrinter(root->right_);
    }
}

template <typename T>
typename  Tree<T>::node_* Tree<T>::getBeginig(node_* root){
    if(root){
        if(root->left_)
            return getBeginig(root->left_);
        return root;
    }
    return nullptr;
}

template <typename T>
typename Tree<T>::node_* Tree<T>::getEnd(node_* root){
    if(root){
        if(root->right_)
            return getEnd(root->right_);
        return root;
    }
    return nullptr;
}

