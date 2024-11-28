#ifndef MYVECTOR_H
 #define MYVECTOR_H
 
 #include<bits/stdc++.h>
  

  /* template là một tính năng cho phép viết code chung cho nhiều kiểu dữ liệu khác nhau
  từ khóa typename được sử dụng để chỉ định rằng một tên  đại diện
  */
template <typename T> 

class MYvector {
private:
T* data;
//size_t là một kiểu dữ liệu trong C++ dược định nghĩa để đại diện cho kích thước của các đối tượng trong bộ nhớ
size_t size; //(số phần tử)
size_t capacity ;//dung lượng (kích thước mảng đc cấp)

public:
// 1. Tạo hàm và hủy hàm 
Myvector(); //tạo hàm rỗng
Myvector(size_t initial_capacity); // tạo hàm với initial_capacity dung lượng ban đầu
~Myvector() ; //hủy và giải phóng bộ nhớ
 Myvector(std::initializer_list<T> init);
/*số phần tử khác dung lượng
Nếu vector có dung lượng(capacity) hiện tại là 5, 
nhưng bạn chỉ thêm 3 phần tử(size), thì dung lượng vẫn là 5
size là 3
*/

//2. Dung lượng,kích thước , số phần tử
size_t size() const ; //số phần tử hiện tại 
size_t capacity() const ; //dung lượng hiện tại
bool empty() const; //kiểm tra dung lượng trống không
void reserve(size_t new_capacity);//cấp phát(bổ sung) nếu cần thêm bộ nhớ
void shrink_to_fit() ;//giảm dung lượng fit với kích thước hiện tại
 void print() const ; //hàm in các phần tử
//3.Truy cập phần tử 
T& operator[](size_t index); //truy cap phan tu x thuoc N
//index chỉ số ,hàm định nghĩa toán tử [] , từ operator để định nghĩa cú pháp

T& at(size_t index); //truy cập phần tử (0=< x <=n)
//định nghĩa hàm at ,trả vệ phần tử vị trí index



// 4. Sự sửa đổi trong Myvector
erase(size_t index);//xóa phần tử vị trí index
void push_back(const T& value);//thêm value vào cuối vector
void pop_back(); // xóa phần tử cuối
void clear ; // xóa tât cả phần tử
void insert(size_t pos , const T& value); //chèn phần tử value vào vị trí pos
void resize(size_t new_size);// thay đổi kích thước
void swap(Myvector<T>&other);//hóan đổi nd với vector khác
}

