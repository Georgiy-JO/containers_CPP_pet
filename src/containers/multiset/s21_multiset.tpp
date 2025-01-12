#pragma once 


template <typename Key>
multiset<Key>::multiset():set<value_type>(){}	

template <typename Key>
multiset<Key>::multiset(const multiset &s):set<value_type>(s){}

template <typename Key>
multiset<Key>::multiset(multiset &&s):set<value_type>(std::move(s)){}

template <typename Key>
multiset<Key>::~multiset(){set<value_type>::clear();}

template <typename Key>
multiset<Key>::multiset(std::initializer_list<value_type> const &items):multiset(){
    for(const auto& i:items )
    insert(i);
}

template <typename Key>
inline multiset<Key>& multiset<Key>::operator=(multiset &&s){        // move assignment 
    set<value_type>::operator=(std::move(s));
    return *this;
}   

template <typename Key>
inline multiset<Key>& multiset<Key>::operator=(const multiset &s){                    // copy assignment 
    set<value_type>::operator=(s);
    return *this;
}

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::insert(const value_type& value){ return set<value_type>::insertMult(value); }  //  inserts a node, returns iterator to it 

template <typename Key>
std::pair<typename multiset<Key>::iterator,typename multiset<Key>::iterator> multiset<Key>::equal_range(const Key& key){return std::make_pair(lower_bound(key),upper_bound(key)); }//returns range of elements matching a specific key

template <typename Key>
typename multiset<Key>::iterator multiset<Key>::lower_bound(const Key& key){return set<value_type>::find(key);}         //returns an iterator to the first element not less than the given key
      
template <typename Key>
typename multiset<Key>::iterator multiset<Key>::upper_bound(const Key& key){ //returns an iterator to the first element greater than the given key
    iterator beg=lower_bound(key), stop=beg;
    if(beg.assigned()){
        while(++stop!=nullptr && stop.assigned() && *stop==*beg){}
    }
    return stop;
}

template <typename Key>
typename multiset<Key>::size_type multiset<Key>::count(const Key& key){ //returns the number of elements matching a specific key
    std::pair<iterator,iterator> pair=equal_range(key);
    size_t n=0;
    if (pair.first.assigned()){
        // std::cout<<"HERE"<<*pair.first <<std::endl;
        iterator point =pair.first;
        for(;point!=pair.second;n++,point++){}
    }
    return n;
}

template <typename Key>
void multiset<Key>::swap(multiset& other){set<value_type>::swap(other);}	    //swaps the contents

template <typename Key>
void multiset<Key>::merge(multiset& other){		//splices nodes from another container //??
    if(this==&other || other.empty()) return;
    if(this->empty()) 
        swap(other);
    else{
        Stack<value_type> lst, lst2;
        other.getTree(lst);
        while(!lst.empty()){
            lst2.push(lst.top());
            lst.pop();
        }
        while(!lst2.empty()){
            this->insert(lst2.top());
            other.remove(lst2.top());
            lst2.pop();
        }
    }
}

template <typename Key>
template <typename...Args>
s21::vector<typename multiset<Key>::iterator> multiset<Key>::insert_many(Args&&... args){ // Inserts several new elements into the container
    s21::vector<typename set<value_type>::iterator> res;
    (res.push_back(insert(std::forward<Args>(args))), ...);
    return res;
}
