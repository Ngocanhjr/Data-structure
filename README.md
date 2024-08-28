# sort

Với kích thước dữ liệu đầu vào nhỏ(3000) nhìn chung tốc độ chênh lệch của các thuật toán là không rõ để nhận thấy.

Với mảng đã được sắp xếp, thì Bubble Sort và Shaker Sort cho tốc độ nhanh nhất do chi phí để biết được đây là mảng có thứ tự của 2 thuật toán trên là O(n).

Với mảng gần như đã được sắp xếp thì Insertion Sort và Binary Insertion Sort là những sự lựa chọn tốt nhất do số phép hoán đổi phải thực hiện ít.

Selection Sort cho tốc độ khá chậm trong đa số trường hợp do độ phức tạp luôn là O(n2), do đó Selection Sort chỉ nên dùng cho các trường hợp số lượng phần tử cần sắp xếp không quá nhiều.

Với mảng gần như đã được sắp xếp thì Shaker Sort cho tốc độ nhanh hơn đáng kể so với Bubble Sort, do thu hẹp được khoảng phải duyệt tiếp theo sau khi duyệt.

Shell Sort, Heap Sort, Merge Sort và Quick Sort có tốc độ ổn định xuyên suốt cả 4 loại dữ liệu đầu vào.

Flash Sort(được phát minh bởi Karl-Dietrich Neubert vào năm 1998) là một thuật toán cho tốc độ nhanh(thậm chí nhanh hơn cả Quick Sort) và tiêu tốn rất ít bộ nhớ, tuy nhiên cách thức xây dựng thuật toán trên khá phức tạp mà nếu có dịp mình sẽ có một bài viết riêng để nói về thuật toán này.

Counting Sort và Radix Sort là những thuật toán cho tốc độ nhanh, tuy nhiên cần đánh đổi bằng cách sử dụng thêm bộ nhớ.
