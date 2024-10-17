**MYvector** hoạt động giống như std::vector trong C++, lưu trữ các phần tử trong một mảng động và tự động quản lý dung lượng bộ nhớ. Cụ thể:

Kiểu lưu trữ:

MYvector lưu trữ các phần tử theo **dạng tuần tự**, nghĩa là sử dụng một mảng động để chứa dữ liệu
 sử dụng bộ nhớ liên tục (contiguous memory)  Điều này có nghĩa là các phần tử của vector được lưu trữ liền kề nhau trong bộ nhớ, giúp tăng tốc độ truy cập phần tử nhờ vào địa chỉ bộ nhớ.

Con trỏ T* data sẽ trỏ đến vùng nhớ mà các phần tử được lưu trữ.
T* data là con trỏ trỏ đến mảng động chứa các phần tử. Khi  khởi tạo MYvector, 
một mảng có kích thước capacity sẽ được cấp phát trong bộ nhớ
Dung lượng và kích thước:

size: Số phần tử thực sự có trong vector (số phần tử  đã thêm vào)
capacity: 
Dung lượng là số lượng phần tử tối đa mà Myvector có thể chứa mà không cần phải cấp phát lại bộ nhớ. Nó đại diện cho khoảng trống đã được cấp phát trong bộ nhớ cho Myvector.


 Mảng động trong Myvector có thể lớn hơn số phần tử thực sự, do vector tự động cấp phát nhiều bộ nhớ hơn để tránh việc phải liên tục cấp phát lại khi thêm phần tử mới.

 **Myvector cũng có những đặc tính của std::vector**

 **1.push_back** : chèn phần tử vào vector nếu tràn dung lượng thì cấp phát  lại bộ nhớ với dung lượng gấp đôi(tự động cấp phát bộ nhớ)

 **2.resize** : để giảm kích thước, vector sẽ xóa bớt các phần tử ở cuối . Nếu tăng kích thước của vector, các phần tử mới sẽ được khởi tạo. Nếu không có giá trị cụ thể được chỉ định, các phần tử mới sẽ được khởi tạo với giá trị mặc định (0 đối với kiểu số nguyên, false đối với kiểu bool, hoặc giá trị mặc định của kiểu dữ liệu đó)