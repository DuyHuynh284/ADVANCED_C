# Bài 3: Bitmask
## Bitmask là gì?
+ Bitmask là một kỹ thuật sử dụng các bit để lưu trữ và thao tác với các cờ (flags) hoặc trạng thái. 
  Có thể sử dụng bitmask để đặt, xóa và kiểm tra trạng thái của các bit cụ thể.
+ Bitmask thường được sử dụng để tối ưu hóa bộ nhớ, thực hiện các phép toán logic trên một cụm bit, 
  và quản lý các trạng thái, quyền truy cập, hoặc các thuộc tính khác của một đối tượng.
## Các phép toán logic
-----
|Tên phép toán|Cú pháp|Mô tả|
|-----|---------|------------------|
|NOT|int result = ~num;| Dùng để thực hiện phép NOT bitwise trên từng bit của một số. Kết quả là bit đảo ngược của số đó.|
|AND|int result = num1 & num2;|Dùng để thực hiện phép AND bitwise giữa từng cặp bit của hai số. Kết quả là 1 nếu cả hai bit tương ứng đều là 1, ngược lại là 0.|
|OR|int result = num1 or num2; |Dùng để thực hiện phép OR bitwise giữa từng cặp bit của hai số. Kết quả là 1 nếu có hơn một bit tương ứng là 1 |
|XOR|int int result = num1 ^ num2;|Dùng để thực hiện phép XOR bitwise giữa từng cặp bit của hai số. Kết quả là 1 nếu chỉ có một bit tương ứng là 1.|
