#include "Myvector.h"
#include <bits/sdtc++.h>
using namespace std;

template <typename T>
void push_back(const T& value) {
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
void pop_back() {
    if (size > 0) {
        size--; // Giảm kích thước để xóa phần tử cuối
    }
}

template <typename T>
void clear() {
    size = 0; // Trả kích thước về 0, xóa tất cả phần tử
}

template <typename T>
void erase(size_t pos, const T& value) {
    if (pos < size) {
        // Dịch các phần tử về bên để ghi đè phần tử tại pos
        for (size_t i = pos; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        size--; // Giảm kích thước
    }
}

template <typename T>
void resize(size_t new_size) {
    if (new_size > capacity) {
        reserve(new_size); // Đảm bảo đủ dung lượng
    }
    size = new_size; // Cập nhật kích thước mới
}

template <typename T>
void swap(MYvector<T>& other) {
    std::swap(data, other.data);
    std::swap(size, other.size);
    std::swap(capacity, other.capacity);
}