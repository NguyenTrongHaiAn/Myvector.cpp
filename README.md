# Myvector.cpp 
HELLO , WE ARE GROUP 1  

**Định nghĩa vector C++ là gì?**
Trong ngôn ngữ lập trình C++, vector là một cấu trúc dữ liệu dạng mảng động có sẵn trong thư viện chuẩn của C++. Vector cung cấp cơ sở lưu trữ, quản lý dữ liệu linh hoạt và nó có thể tự động mở rộng trong những trường hợp cần thiết. 

**Một số điểm quan trọng về vector trong C++ bao gồm:**

1 :Động cơ lý tưởng cho việc thêm/xóa phần tử: Vector cho phép thêm phần tử vào cuối mảng và xóa phần tử từ cuối mảng một cách hiệu quả với độ phức tạp O(1).

2 :Truy cập ngẫu nhiên: Vector cho phép truy cập các phần tử trong mảng thông qua chỉ số, cho phép truy cập ngẫu nhiên với độ phức tạp O(1).

3 :Tự động thay đổi kích thước: Vector có khả năng tự động điều chỉnh kích thước khi cần thiết, tự động tăng kích thước khi thêm phần tử mới vào và tự động giảm kích thước khi xóa phần tử ra khỏi vector.

**Dưới đây là một ví dụ về cách sử dụng vector trong C++:**

 *Khai báo một vector chứa các số nguyên*

    std::vector<int> numbers;

*Thêm phần tử vào vector* 
    numbers.push_back(10);

    numbers.push_back(20);

    numbers.push_back(30);

*Truy cập phần tử trong vector và in ra màn hình*

    std::cout << "Phan tu tai vi tri thu 1: " << numbers[0] << std::endl;

    std::cout << "Phan tu tai vi tri thu 2: " << numbers[1] << std::endl;

    std::cout << "Phan tu tai vi tri thu 3: " << numbers[2] << std::endl;

# vector structure

**Khởi tạo:**

vector<Type> v; — Khởi tạo vector rỗng.
vector<Type> v(n); — Khởi tạo vector có n phần tử với giá trị mặc định.
vector<Type> v(n, value); — Khởi tạo vector có n phần tử với giá trị ban đầu là value.

**Thêm/xóa phần tử:**

push_back(value) — Thêm phần tử value vào cuối vector.
pop_back() — Xóa phần tử cuối cùng.
insert(it, value) — Thêm value vào vị trí it.
erase(it) — Xóa phần tử tại vị trí it.
clear() — Xóa toàn bộ phần tử trong vector.

**Truy cập:**

v[i] — Truy cập phần tử thứ i (bắt đầu từ 0).
at(i) — Truy cập phần tử thứ i với kiểm tra biên.
front() — Trả về phần tử đầu tiên.
back() — Trả về phần tử cuối cùng.

**Kích thước và dung lượng:**

size() — Trả về số lượng phần tử hiện có.
capacity() — Trả về dung lượng hiện tại của vector (tức là số phần tử mà vector có thể chứa trước khi cần cấp phát lại bộ nhớ).
resize(n) — Thay đổi kích thước vector thành n phần tử.
reserve(n) — Đặt dung lượng của vector ít nhất là n.
empty() — Kiểm tra xem vector có rỗng không.

**Duyệt qua các phần tử:**

begin() và end() — Trả về iterator đầu và sau cuối của vector.

**Sao chép và gán:**

v1 = v2; — Sao chép tất cả phần tử của v2 sang v1.
vector<int> v(v2); — Khởi tạo v với các phần tử từ v2.

# BIÊN DỊCH CODE 
Khi có nhiều file .cpp chứa phần định nghĩa hàm,  sẽ biên dịch tất cả các file đó cùng với file main.cpp.
VÍ DỤ

g++ main.cpp Myvector_constructors.cpp Myvector_capacity.cpp Myvector_access.cpp -o myvector
