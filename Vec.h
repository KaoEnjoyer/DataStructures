//
// Created by takos on 07.07.2024.
//

#ifndef DATASTRUCTURES_VEC_H
#define DATASTRUCTURES_VEC_H
template<class T>
class vec{
public:
    vec();
    vec(int const & size);
    void resize(size_t const & n);
    void push(T const& var);
    T&operator[](size_t const & id);
    size_t size();
private:
    T* m_ptr;
    size_t m_size;
    size_t m_capacity;
    void m_Realoc(size_t const & k);

};

template<class T>
size_t vec<T>::size() {
    return m_size;
}

template<class T>
void vec<T>::push(const T &var) {
    if(m_size >= m_capacity){
        m_Realoc(m_capacity * 2);
    }
    m_ptr[m_size] = var;
    m_size++;
}

template<class T>
T &vec<T>::operator[](const size_t &id) {
    return m_ptr[id];
}

template<class T>vec<T>::vec() {
    m_size = 0;
    m_Realoc(2);
}

template<class T>vec<T>::vec(const int &size) {
    m_size = size;
    m_Realoc(size);
}


template<class T>
void vec<T>::m_Realoc(const size_t &k){
    m_capacity = k;
    T* temp_ptr = new T[m_capacity];
    for(int i = 0; i < m_size; i++){
    temp_ptr[i] = m_ptr[i];
    }
    m_ptr = temp_ptr;
    delete[] temp_ptr;
}
template<class T>
void vec<T>::resize(const size_t &n) {
    m_Realoc(n);
    m_size = n;
}


#endif //DATASTRUCTURES_VEC_H
