# Myvector.cpp 
HELLO , WE ARE GROUP 1  

**Định nghĩa vector C++ là gì?**
Trong ngôn ngữ lập trình C++, vector là một cấu trúc dữ liệu dạng mảng động có sẵn trong thư viện chuẩn của C++. Vector cung cấp cơ sở lưu trữ, quản lý dữ liệu linh hoạt và nó có thể tự động mở rộng trong những trường hợp cần thiết. 

**Một số điểm quan trọng về vector trong C++ bao gồm:**

**1 :** Động cơ lý tưởng cho việc thêm/xóa phần tử: Vector cho phép thêm phần tử vào cuối mảng và xóa phần tử từ cuối mảng một cách hiệu quả với độ phức tạp O(1).

**2 :**Truy cập ngẫu nhiên: Vector cho phép truy cập các phần tử trong mảng thông qua chỉ số, cho phép truy cập ngẫu nhiên với độ phức tạp O(1).

**3 :**Tự động thay đổi kích thước: Vector có khả năng tự động điều chỉnh kích thước khi cần thiết, tự động tăng kích thước khi thêm phần tử mới vào và tự động giảm kích thước khi xóa phần tử ra khỏi vector.

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