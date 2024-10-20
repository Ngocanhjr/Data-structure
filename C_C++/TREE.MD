# TREE
## The Tree is a hierarchical DS
Nút cha con: nút A là cha của nút B khi nút A ở mức i và nút B ở mức i+1, đồng thời giữa A và B có cạnh nối.
Bậc của nút là số cây con của nút đó, bậc nút lá = 0.
Bậc của cây là bậc lớn nhất của các nút trên cây.
Cây n-phân là cây có bậc n.
Root: nút không có cha.
Leaf: nút không có comn.
Interior node: Nút có bậc khác 0 và không phải root.
Descentant & Ancesor: Nếu có đường đi từ nút a đến nút b thì nút a là Descentant (Tiền bối) của b, còn b là Ancesor (hậu duệ)của a.
Sub_tree của 1 cây là 1 nút cùng với tất cả các hậu duệ của nó.
Siblings: Các nút con cùng một nút cha.
Đường đi là một chuỗi các nút n1, n2, ..., nk trên cây sao cho ni là nút cha của nút ni+1 (i=1..k-1).
Độ dài đường đi bằng số nút trên đường đi trừ 1
– VD: độ dài đường đi A,D,I,O,Q = 5-1=4
Chiều cao của 1 nút là độ dài đường đi từ nút đó đến nút lá xa nhất.
Độ sâu của 1 nút là độ dài đường đi từ nút gốc đến nút đó, hay còn gọi là mức (level) của nút đó.
Cây có thứ tự: 
Nếu ta phân biệt thứ tự các nút trong cùng 1 cây thì ta gọi đó là có thứ tự. Ngược lại, gọi là cây không có thứ tự.
– Trong cây có thứ tự, thứ tự qui ước từ trái sang phải.
Duyệt cây:
– Có 3 phương pháp duyệt tổng quát:
• tiền tự (preorder)
• trung tự (inorder)
• hậu tự (posorder)