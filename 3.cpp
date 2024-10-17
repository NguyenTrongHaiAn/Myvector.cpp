#include<iostream>
#include<Myvector.h>
using namespace std;

template <typename T>
Myvector<T>::T& operator[](size_t index);
if(size==0){
	return 0;
}
return data[index];

template <typename T>
Myvector<T>::T& at(size_t index);
if(size ==0 || index > size){
	return 0;
}
if(index <= size){
	return  data[index];
}
template <typename T>
Myvector<T>::erase(size_t index);
delete data[index];
for(size_t i=index ; i<size-1 ; ++i){
	data[i]= data[i+1];
}
--size; --capacity;