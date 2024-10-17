#include "Myvector.h"
#include <bits/sdtc++.h>
using namespace std ;

/*<T>: Biểu thị rằng Myvector là một class template và nó có thể chứa 
bất kỳ kiểu dữ liệu nào (ví dụ: int, float, char).
Myvector(): Đây là hàm constructor không có tham số (constructor rỗng), 
được gọi khi bạn tạo một đối tượng

:: toán tử phạm vi để chỉ ra rằng hàm này thuộc về class nào.  
  
  khai báo một template trình biên dịch cần biết 
  rằng những hàm này sẽ được tạo ra cho các kiểu dữ liệu khác nhau. Template là một phần của tính năng  trong C++, 
  cho phép tạo ra các hàm và lớp có thể hoạt động với nhiều kiểu dữ liệu khác nhau 
  mà không cần phải viết lại mã


Câu lệnh delete[] data; sẽ:
Xác định rằng data là một con trỏ đến một mảng (do đã sử dụng new[] để cấp phát).
Giải phóng bộ nhớ mà data đang trỏ tới.

*/
template <typename T>
Myvector<T>::Myvector(){
size =0;
capacity=1;
data=new T[capacity];//trả về địa chỉ vùng nhớ đc cấp phát cho mảng động .kiểu trả về T*
cout<<"empty Myvector is initialized "<<endl;
}

template <typename T>
Myvector::Myvector(size_t initial_capacity){
size=0;
capacity=initial_capacity; // Khởi tạo với dung lượng ban đầu do người dùng cung cấp
data =new T[capacity];
cout<<"The vector is initialized with a capacity of" << capacity << std::endl;
}
 
template <typename T> 

Myvector<T>::~Myvector(){
delete[] data<T>;
cout<<"memory has been freed"<<endl;


}

template <typename T>
Myvector<T>::Myvector(std::initializer_list<T> init) {
    size = init.size(); // Kích thước từ danh sách
    capacity = size; // Đặt dung lượng bằng kích thước
    data = new T[capacity]; // Cấp phát bộ nhớ cho mảng

    // Sao chép các phần tử từ danh sách vào mảng
    size_t index = 0;
    for (const T& value : init) {
        data[index++] = value;
    }

    std::cout << "Myvector constructor với danh sách được gọi" << std::endl;
}