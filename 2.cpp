#inlcude<iostream>
#inlcude "Myvector.h"
/*const trong phương thức: Đảm bảo rằng phương thức không thay đổi trạng thái của đối tượng.
Gọi phương thức trên đối tượng const: Chỉ những phương thức được
 định nghĩa là const mới có thể được gọi trên các đối tượng const.
 
 trong mục này sẽ thấy nhận ra xuất hiện mảng có tên data ,xem lại file 1.cpp hàm khởi tạo 
 sẽ thấy ta đã khởi tạo cấp phát mảng động cho con trỏ data
 */

size_t Myvector<T>::size() const{

    return size;
}

template <typename T>
size_t Myvector<T>::capacity() const {

    return capacity ;
}

template <typename T> 
bool Myvector<T>::empty() const {

      if (size == 0) {
        
        return true;
    }
    return false;
}

// Phương thức cấp phát thêm bộ nhớ nếu dung lượng mới lớn hơn dung lượng hiện tại
template <typename T> 
void Myvector<T>::reserve(size_t new_capacity){
    if(new_capacity > capacity){
        T* new_data = new T[new_capacity]//cấp phát mảng mới vùng nhớ heap kthuoc là new_capacity
        for(int i=0; i<size ; i++){
            new_data[i]=data[i];//sao chép phần tử 
        }
        delete[] data; //xóa dữ liệu cũ
        data=new_data ;
        capacity=new_capacity;


    }
}
//shrink to fit
template <typename T>
void Myvector<T>:: shrink_to_fit(){
    if(capacity>size){
        T* new_data=new T[size];
        for(int i=0;i<size;i++){
            new_data[i]=data[i];

        }
    delete[] data;
    data=new_data;//con trỏ data trỏ tới mảng mà con trỏ new_data trỏ ,gán địa chỉ mảng 
    capacity=size;//cập nhật dung lượng sao fit 
    }

}


//in các phần tử 
void print() const {
        for (size_t i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }