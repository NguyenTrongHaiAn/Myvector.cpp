#include "Myvector.h"


#include <iostream>

using namespace std;

template <typename T>
void Myvector<T>:: push_back(const T& value) {
    // Nếu dung lượng tối đa, nhân đôi dung lượng
    if (size >= capacity) {
        // Nếu chưa có dung lượng, tạo dung lượng khởi tạo
        size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
        reserve(new_capacity);
    }
    data[size] = value; // Thêm phần tử vào của
    size++; // Tăng kích thước
}

template <typename T>
void Myvector<T>:: pop_back() {
    if (size > 0) {

        size--; // Giảm kích thước để xóa phần tử cuối
    }
}

template <typename T>
void Myvector<T>:: clear() {
    delete[] data; // Giải phóng bộ nhớ đã cấp phát
    data = nullptr; // Đặt con trỏ thành nullptr
    size = 0; // Trả lại kích thước về 0
    capacity = 0; // Đặt lại dung lượng về 0 (tùy vào mục đích sử dụng)
}


template <typename T>
void Myvector<T>:: erase(size_t pos) {

    if (pos < size) {
        // Dịch các phần tử về bên để ghi đè phần tử tại pos
        for (size_t i = pos; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        size--; // Giảm kích thước
    }
}

template <typename T>
void Myvector<T>:: resize(size_t new_size) {
    if (new_size > capacity) {
        reserve(new_size); // Đảm bảo đủ dung lượng
    }
    size = new_size; // Cập nhật kích thước mới
}

template <typename T>
void Myvector<T>:: swap(Myvector<T>& other) {
    std::swap(data, other.data);
    std::swap(size, other.size);
    std::swap(capacity, other.capacity);

}

//chèn phần tử ở vị trí pos
template <typename T>
bool Myvector<T>::insert(size_t pos, const T& value) {
    // Kiểm tra vị trí hợp lệ
    if (pos > size) {
        std::cerr << "Error: Position out of range" << std::endl;
        return false; // Không chèn được
    }

    // Kiểm tra và mở rộng dung lượng nếu cần
    if (size == capacity) {
        size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
        reserve(new_capacity); // Gọi hàm mở rộng dung lượng
    }

    // Dịch chuyển các phần tử từ vị trí `pos` sang phải
    for (size_t i = size; i > pos; --i) {
        data[i] = data[i - 1];
    }

    // Chèn phần tử mới vào vị trí `pos`
    data[pos] = value;

    // Tăng kích thước vector
    ++size;

    return true; // Chèn thành công
}

template <typename T>
void Myvector<T>::sort() {
    for (size_t i = 0; i < size - 1; ++i) {
        for (size_t j = 0; j < size - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                // Swap data[j] and data[j + 1]
                T temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}
