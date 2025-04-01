# Longest common substring 

Xét bài toán tìm dãy con chung dài nhất của chuỗi ký tự X và Y. Giả sử X có m ký tự và Y có n ký tự.

Quy trình thiết kế thuật toán quy hoạch động cho bài toán này gồm các bước:

Step 1: Identify optimal substructure

Chia nhỏ bài toán: chuỗi X sẽ được chia thành 2 phần: phần đầu và 1 ký tự cuối cùng. Quá trình chia nhỏ tiếp tục, phần đầu của X sẽ được thành hai phần, ... Tương tự như vậy cho Y. Như thế, các bài toán con sẽ có đầu vào là các tiền tố (prefixes) của X và Y.

Các bài toán con (subproblems): tìm dãy con chung dài nhất của các tiền tố (prefixes) của X và Y.

Nếu c1 c2 c3 ... ck-1 ck là một lời giải tối ưu (optimal solution) của bài toán (X,Y) thì c1 c2 c3 ... ck-1 cũng là một lời giải tối ưu của bài toán (Xi, Yj) với Xi, Yj là tiền tố nào đó của X và Y.

Step 2: Find a recursive formulation for the length of the longest common subsequence.

Gọi C[i, j] = chiều dài của dãy con chung dài nhất của hai tiền tố (Xi, Yj). C[i, j] sẽ được tính từ các C[k, l] với k, l nhỏ hơn i, j.

Trường hợp 1: Nếu X[i] == Y[j], thì C[i,j]=C[i−1,j−1]+1

Trường hợp 2: Nếu X[i] != X[j], bỏ X[i] hoặc bỏ Y[j] đi, ta có C[i,j]=maxC[i−1,j],C[i,j−1]

Trường hợp cơ sở (base case): Nếu i = 0 hoặc j = 0, C[i,j]=0
;

Step 3: Use dynamic programming to find the length of the longest common subsequence.

Hãy cài đặt bước 3 để điền các giá trị vào bảng C.

Chúng ta sẽ cài đặt thuật toán LCS này bằng ngôn ngữ C++.
