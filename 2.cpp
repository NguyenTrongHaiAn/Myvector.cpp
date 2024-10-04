#inlcude<bits/stdc++.h>
#inlcude "Myvector.h"
/*const trong phương thức: Đảm bảo rằng phương thức không thay đổi trạng thái của đối tượng.
Gọi phương thức trên đối tượng const: Chỉ những phương thức được
 định nghĩa là const mới có thể được gọi trên các đối tượng const.*/
template <typename T>
size_t Myvector<T> size() const{

    return size;
}

template <typename T>
size_t Myvector<T> capacity() {

    return capacity ;
}

template <typename T>
