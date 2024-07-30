//
// Created by takos on 07.07.2024.
//

#ifndef DATASTRUCTURES_HASHMAP_H
#define DATASTRUCTURES_HASHMAP_H

#include <vector>
//hash fnc w zależności od typu
// zakładam że najłatwiej odróznić string , i liczbowe póki co
// nie wiem czy się brać za rozróżnaine vectorów

//hash map node definition
template<class V , class K>struct _hash_map_node{
    _hash_map_node();
    _hash_map_node(V const & val , K const & key);


    V _val;
    K _key;
    _hash_map_node<V , K>* _next;

};

template<class V, class K>
_hash_map_node<V, K>::_hash_map_node() {
    _next = nullptr;
}

template<class V, class K>
_hash_map_node<V, K>::_hash_map_node(const V &val, const K &key) {
    _val = val;
    _key = key;
    _next = new _hash_map_node<V , K>;
}


template<class V , class K>class hash_map{
public:
    hash_map();
    V& operator[](K const & key);
    typedef _hash_map_node<V , K> _node;

private:
    size_t hash(int x);

    std::vector<_node>arr;

};

template<class V, class K>
hash_map<V, K>::hash_map() {
    arr.resize(2);
}


template<class V, class K>
V &hash_map<V, K>::operator[](const K &key) {

    size_t _h = hash(key);
    _node* N = &arr[_h];
    while(N->_key != key){
        if(N->_next == nullptr){
            *N =  _node(N->_val , key);
            break;
        }
       N = N->_next;
    }
    return N->_val;


}

template<class V, class K>
size_t hash_map<V , K>::hash(int x) {
        return (arr.size()-1) % x;
}





#endif //DATASTRUCTURES_HASHMAP_H
