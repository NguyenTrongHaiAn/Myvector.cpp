#include<iostream>
#include<Myvector.h>
using namespace std;

template <typename T>
T& Myvector<T>::operator[](size_t index) {
    static T default_value = T(); // Giá trị mặc định trả về khi có lỗi

    if (size == 0) {
        std::cout << "Vector rỗng, không thể truy cập phần tử!" << std::endl;
        return default_value; // Trả về giá trị mặc định
    }

    if (index >= size) {
        std::cout << "Index ngoài phạm vi cho phép!" << std::endl;
        return default_value; // Trả về giá trị mặc định
    }

    return data[index]; // Trả về tham chiếu đến phần tử hợp lệ
}

//xóa phần tử ở vị trí inddex
template <typename T>
void MyVector<T>::erase(size_t index) {
    // Kiểm tra nếu vector rỗng hoặc index không hợp lệ
    if (size == 0) {
        std::cerr << "Error: Cannot erase from an empty vector." << std::endl;
        return;
    }

    if (index >= size) {
        std::cerr << "Error: Index out of range." << std::endl;
        return;
    }

    // Không cần gọi destructor vì T không phải là class

    // Dịch chuyển các phần tử còn lại
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }

    // Giảm size
    --size;
}
