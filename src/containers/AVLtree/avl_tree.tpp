#pragma once

template <typename Key_T, typename T>
std::pair<typename Tree<Key_T,T>::iterator, bool> Tree<Key_T,T>::insert(const_key_type& key, const_value_type &value){
    iterator_ local;
    bool inserted = insert(root_,key,value);
    if (inserted){
        size_++;
        addParents();
        local=find_(key);
    }
    return std::make_pair(local,inserted);
}
template <typename Key_T, typename T>
bool Tree<Key_T,T>::insert(node_ *& root,const_key_type& key, const_value_type& value){
    bool flag = true;
    if(!root)
        root = new node_(key,value);
    else{
        if(key==root->key_)
            flag = false;
        else if(key < root->key_)
            flag =insert(root->left_,key,value);
        else
            flag =insert(root->right_,key,value);
        
        if(flag)
            balancerInsert(root,key);
    }
    return flag;
}

template <typename Key_T, typename T>
void Tree<Key_T,T>::balancerInsert(node_ *& root,const_key_type &key){
    int delta=getBalanceFactor(root);

    if(delta>1 && root->left_ && key < root->left_->key_)
        rotateRight(root);
    else if(delta<-1 && root->right_ && key > root->right_->key_)
        rotateLeft(root);
    else if(delta>1 && root->left_ && key > root->left_->key_) {
        rotateLeft(root->left_);
        rotateRight(root);
    }
    else if(delta<-1 && root->right_ && key<root->right_->key_){
        rotateRight(root->right_);
        rotateLeft(root);
    }
}

template <typename Key_T, typename T>
void Tree<Key_T,T>::rotateLeft(node_ *& root){
    node_* tmp_ptr=root;
    root=root->right_;
    tmp_ptr->right_=root->left_;
    root->left_=tmp_ptr;
}
template <typename Key_T, typename T>
void Tree<Key_T,T>::rotateRight(node_ *& root){
    node_* tmp_ptr=root;
    root=root->left_;
    tmp_ptr->left_=root->right_;
    root->right_=tmp_ptr;
}

template <typename Key_T, typename T>
unsigned int Tree<Key_T,T>::getHight(const node_* root) const{
    if(!root)
        return 0;
    unsigned int h_left=(root->left_)?getHight(root->left_):0;
    unsigned int h_right=(root->right_)?getHight(root->right_):0;
    return 1+std::max(h_left,h_right);
}

template <typename Key_T, typename T>
void Tree<Key_T,T>::clear(node_*& root){
    if(root){
        if(root->right_)
            clear(root->right_);
        if (root->left_)
            clear(root->left_);
        removeNode(root);
    }
}

template <typename Key_T, typename T>
typename Tree<Key_T,T>::node_* Tree<Key_T,T>::find_(node_ * root, const_key_type &key) const{  
    if(!root)
        return nullptr;
    if(key==root->key_)
        return root;
    if(key<root->key_)
        return find_(root->left_, key);
    return find_(root->right_, key);
}
template <typename Key_T, typename T>
typename Tree<Key_T,T>::node_* Tree<Key_T,T>::find__(node_ * root, const_value_type &value) const{ 
    if(!root)
        return nullptr;
    if(value==root->data_)
        return root;
    node_ * tmp=nullptr;
    tmp=find__(root->left_, value);
    if(!tmp)
        tmp=find__(root->right_, value);
    return tmp;
}
template <typename Key_T, typename T>
inline typename Tree<Key_T,T>::iterator Tree<Key_T,T>::find(const_key_type& key) const{
    iterator_ tmp = find_(key);
    return tmp;
}

template <typename Key_T, typename T>
void Tree<Key_T,T>::addParents(node_*& root){
    if(root){
        if (root->left_)
            root->left_->parent_=root;
        if (root->right_)
            root->right_->parent_=root;    
        addParents(root->left_);
        addParents(root->right_);
    }
}
template <typename Key_T, typename T>
void Tree<Key_T,T>::addParents(){
    if(root_){
    addParents(root_);
    root_->parent_=nullptr;

    }
}

template <typename Key_T, typename T>
void Tree<Key_T,T>::showTreeVertical(const node_ *node){
    if(node){
        showTreeVertical(node->left_);
        std::cout<<node->key_<<" ";
        showTreeVertical(node->right_);
    }
}
template <typename Key_T, typename T>
void Tree<Key_T,T>::showTreeVertical(){
    showTreeVertical(root_);
    std::cout<<std::endl;
}
template <typename Key_T, typename T>
void Tree<Key_T,T>::showTreeVerticalVal(const node_ *node){
    if(node){
        showTreeVerticalVal(node->left_);
        std::cout<<node->key_<<':'<< node->data_<<"  ";
        showTreeVerticalVal(node->right_);
    }
}
template <typename Key_T, typename T>
void Tree<Key_T,T>::showTreeVerticalVal(){
    showTreeVerticalVal(root_);
    std::cout<<std::endl;
}

template <typename Key_T, typename T>
Tree<Key_T,T>::Tree(std::initializer_list<key_type> const &items):Tree(){
    for(const auto& i:items )
        insert(i);
}
template <typename Key_T, typename T>
Tree<Key_T,T>::Tree(std::initializer_list<std::pair<key_type, value_type>> const &items){
    for(const auto& i:items )
        insert(i.first,i.second);
}

template <typename Key_T, typename T>
void Tree<Key_T,T>::swap(Tree& other) noexcept{
    node_* tmp=other.root_;
    other.root_=root_;
    root_=tmp;
    std::swap(size_, other.size_);
}

template <typename Key_T, typename T>
Tree<Key_T,T>& Tree<Key_T,T>::operator=(Tree &&other){
    if(this!=&other){
        clear();
        root_=other.root_;
        size_=other.size_;
        other.setNull();
    }
    return *this;
}

template <typename Key_T, typename T>
Tree<Key_T,T>& Tree<Key_T,T>::operator=(const Tree &other){
    if(this!=&other){
        clear();
        Tree new_tree;
        other.copyTree(new_tree);
        swap(new_tree);
    }
    return *this;
}

template <typename Key_T, typename T>
void Tree<Key_T,T>::setNull(){
    if(root_){
        root_=nullptr;
        size_=0;
    }
}

template <typename Key_T, typename T>
Stack<typename Tree<Key_T,T>::key_type>& Tree<Key_T,T>::getTree(const node_ *node,Stack<key_type>& stack)const{
    if(node){
        getTree(node->left_,stack);
        stack.push(node->key_);
        getTree(node->right_,stack);
    }
    return stack;
}
template <typename Key_T, typename T>
std::pair<Stack<typename Tree<Key_T,T>::key_type>, Stack<typename Tree<Key_T,T>::value_type>>& Tree<Key_T,T>::getTree(const node_ *node, std::pair<Stack<key_type>, Stack<value_type>>& stack)const{
    if(node){
        getTree(node->left_,stack);
        stack.first.push(node->key_);
        stack.second.push(node->data_);
        getTree(node->right_,stack);
    }
    return stack;
}
template <typename Key_T, typename T>
void Tree<Key_T,T>::copyTreeNode(const node_* from,node_*& to) const{
    if(from){
        if(!to)
            to=new node_;
        copyTreeNode(from->left_,to->left_);
        to->key_=from->key_;
        to->data_=from->data_;
        to->parent_=nullptr;
        copyTreeNode(from->right_,to->right_);
    }
}
template <typename Key_T, typename T>
void Tree<Key_T,T>::copyTree(Tree<Key_T,T>& TO) const{
    if(root_){
        copyTreeNode(root_,TO.root_);
        TO.addParents();
        TO.size_=size_;
    }
}

template <typename Key_T, typename T>
typename Tree<Key_T,T>::node_* Tree<Key_T,T>::remove(node_ *& root, const_key_type &key){
    if(!root)
        return root;
    if(key<root->key_)
        root->left_=remove(root->left_,key);
    else if (key>root->key_)
        root->right_=remove(root->right_,key);
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
        root->key_=tmp->key_;
        root->right_=remove(root->right_,tmp->key_);
    }
    addParents();
    balancerRemove(root);
    return root;
}

template <typename Key_T, typename T>
void Tree<Key_T,T>::balancerRemove(node_ *& root){

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

template <typename Key_T, typename T>
inline void Tree<Key_T,T>::removeNode(node_ *& node){
    delete node;
    node=nullptr;
    size_--;
}

template <typename Key_T, typename T>
inline int Tree<Key_T,T>::getBalanceFactor(const node_ * node)const{
    if(!node)
        return 0;
    return getHight(node->left_)-getHight(node->right_);
}

template <typename Key_T, typename T>
inline typename Tree<Key_T,T>::size_type Tree<Key_T,T>::max_size() const noexcept {
    return std::numeric_limits<size_type>::max() / sizeof(Tree<Key_T,T>::node_);
}

template <typename Key_T, typename T>
inline typename  Tree<Key_T,T>::node_* Tree<Key_T,T>::getParent(const_key_type &key)const{
    node_* tmp=find_(key);
    if(tmp)
        return find_(key)->parent_; 
    return nullptr;
 }
template <typename Key_T, typename T>
typename Tree<Key_T,T>::key_type Tree<Key_T,T>::getParentData(const_key_type key)const{
    node_* tmp=getParent(key);
    if(!tmp)
        throw std::out_of_range("No parents found");
    return tmp->key_;
}

template <typename Key_T, typename T>
void Tree<Key_T,T>::crazyPrinter(const node_* root)const{
    if(root){
        std::cout<<"Node:"<<root->key_<<'('<< root->data_<<')'<<":   Parent:";    
        if (root->parent_)
            std::cout<<root->parent_->key_<<'('<<root->parent_->data_<<')'<<";   Left:";
        else
            std::cout<<"NULL"<<";   Left:";
        if(root->left_)
            std::cout<<root->left_->key_<<'('<<root->left_->data_<<')'<<";   Right:";
        else
            std::cout<<"NULL"<<";   Right:";
        if(root->right_)
            std::cout<<root->right_->key_<<'('<<root->right_->data_<<')'<<"."<<std::endl;
        else
            std::cout<<"NULL"<<"."<<std::endl;
        crazyPrinter(root->left_);
        crazyPrinter(root->right_);
    }
}

template <typename Key_T, typename T>
typename  Tree<Key_T,T>::node_* Tree<Key_T,T>::getBeginig(node_* root){
    if(root){
        if(root->left_)
            return getBeginig(root->left_);
        return root;
    }
    return nullptr;
}

template <typename Key_T, typename T>
typename Tree<Key_T,T>::node_* Tree<Key_T,T>::getEnd(node_* root){
    if(root){
        if(root->right_)
            return getEnd(root->right_);
        return root;
    }
    return nullptr;
}

template <typename Key_T, typename T>
void Tree<Key_T,T>::merge(Tree<Key_T,T>& other){
    if(this==&other || !other.root_) return;
    if(!root_) 
        swap(other);
    else{
        iterator tmp=other.begin();
        std::pair <iterator_, bool> pr;
        Stack<Key_T> lst;
        while(1){
            pr=this->insert(tmp.getKey(),tmp.getValue());
            if(pr.second)
                lst.push(pr.first.getKey());
            if(tmp==other.end())
                break;
            tmp++;
        }
        while(!lst.empty()){
            other.remove(lst.top());
            lst.pop();
        }
    }
}

template <typename Key_T, typename T>
template <typename...Args>
s21::vector<std::pair<typename Tree<Key_T,T>::iterator,bool>> Tree<Key_T,T>::insert_many(Args&&... args){
    s21::vector<std::pair<typename Tree<Key_T,T>::iterator,bool>> res;
    (res.push_back(insert(std::forward<Args>(args))), ...);
    return res;
}
