# Topological Sorting (Topo)

### **Định nghĩa**

Sắp xếp các đỉnh của đồ thị có hướng sao cho **đỉnh gốc (đầu mũi tên)** phải **đứng trước đỉnh ngọn (cuối mũi tên)**.  
Nói cách khác: nếu `(u → v)` thì `u` phải đứng trước `v` trong thứ tự topo.

---

## Rank – Xếp hạng đỉnh trong đồ thị có hướng

- Mục tiêu: gán hạng (rank) cho các đỉnh sao cho nếu `(u → v)` thì `rank[u] < rank[v]`.
- Ví dụ: nếu `u → v` thì `rank[u] = 0` ⇒ `rank[v] = 1`
- Đỉnh gốc có hạng = 0, ngược lại `rank[u]` là **số cung trên đường đi dài nhất từ gốc đến u**

---

## BFS xếp hạng topo

1. **Đỉnh có bậc vào = 0** (không có đỉnh nào trỏ vào) sẽ có `rank = 0` → gọi là _gốc cũ_.
2. **Gỡ bỏ các cung** nối từ các đỉnh này đến đỉnh kề.
3. Sau khi gỡ, các đỉnh **có bậc vào = 0** mới (do bị trừ bậc vào) sẽ có `rank = 1` → _gốc mới_.
4. Lặp lại quá trình đến khi không còn đỉnh nào.

---

### Biến hỗ trợ

- `d[u]`: bậc vào của đỉnh `u`, mỗi khi gỡ bỏ cung nối đến u, ta giảm `d[u]` đi 1.
- `r[u]`: rank (hạng) của đỉnh `u`
- `S1`: danh sách các đỉnh đang xét hạng (các gốc cũ)
- `S2`: danh sách các đỉnh sắp sửa xem xét (có d[u] == 0, các gốc mới)

---

## Cài đặt thuật toán

- **Biểu diễn đồ thị**: ma trận kề `A[u][v] = 1` nếu có cung `u → v`
- **Danh sách hỗ trợ** (`List`):
  - `make_null_list(List *pL)`: khởi tạo danh sách rỗng
  - `push_back(List *pL, int x)`: thêm phần tử vào cuối danh sách
  - `element_at(List *pL, int i)`: trả về phần tử thứ `i` trong danh sách (thứ tự tính từ 1 đến `size`)
  - `copy_list(List *pS1, List *pS2)`: sao chép `pS2` vào `pS1`
  - `size`: số phần tử của danh sách

---

### Thuật toán

- Tính d[u] cho tất cả các đỉnh
- Đưa các đỉnh u có d[u] = 0 vào S1
- `k = 0` (hoặc 1 tuỳ theo ta muốn gốc có hạng mấy)

```c
while (S1 không rỗng) {
    Làm rỗng S2
    for (các đỉnh u trong S1) {
        r[u] = k;
        for (các đỉnh kề v của u) {
            d[v]--;
            if (d[v] == 0)
                Đưa v vào S2;
        }
    }
    k++;
    copy S2 vào S1 (gán S1 = S2);
}
```

---

```c
// Bước 1: Tính bậc vào d[u] cho tất cả các đỉnh
for (u = 1 → n)
    d[u] = số lượng đỉnh v mà A[v][u] = 1

// Bước 2: Đưa các đỉnh có d[u] = 0 vào S1
make_null_list(&S1);
for (u = 1 → n)
    if (d[u] == 0)
        push_back(&S1, u);

// Bước 3: Lặp cho đến khi không còn đỉnh nào
k = 0; //k = 0 (hoặc 1 tuỳ theo ta muốn gốc có hạng mấy)
while (S1 không rỗng) {
    make_null_list(&S2);
    for (i = 1 → S1.size) {
        u = element_at(&S1, i);
        r[u] = k;
        for (v = 1 → n)
            if (A[u][v]) {
                d[v]--;
                if (d[v] == 0)
                    push_back(&S2, v);
            }
    }
    k++;
    copy_list(&S1, &S2);
}
```

### **Code**

```c
//Lưu hạng của các đỉnh
int r[MAX_N];
//Hàm xếp hạng
void rank (Graph *pG) {
 int d[MAX_N]; //Lưu bậc các đỉnh
 //Tính bậc vào của các đỉnh d[u]
 for (int u = 1; u <= pG->n; u++) {
  d[u] = 0;
  for (int x = 1; x <= pG->n; x++)
   if (pG->A[x][u] != 0)
    d[u]++;
 }
 //Sử dụng 2 danh sách S1, S2
 List S1, S2;
 //Tìm gốc, đưa vào S1
 make_null_list(&S1);
 for (int u = 1; u <= pG->n; u++)
  if (d[u] == 0)
   push_back(&S1, u);

 //Vòng lặp chính, lặp đến khi S1 rỗng thì dừng
 int k = 0; //hạng tính từ 0. Tùy theo bài toán có thể cho k = 1
 while (S1.size > 0) {
  make_null_list(&S2);
  for (int i = 1; i <= S1.size; i++) {
   int u = element_at(&S1, i);  //Lấy các gốc u trong S1 ra
   r[u] = k;     //Xếp hạng cho u
   //Xoá đỉnh u <=> giảm bậc vào của các đỉnh kề v của u
   for (int v = 1; v <= pG->n; v++)
    if (pG->A[u][v] != 0) {
     d[v]--;
     if (d[v] == 0)
      push_back(&S2, v);
    }
  }
  copy_list(&S1, &S2);  //Copy S2 vào S1
  k++;     //Tăng hạng kế tiếp cho các gốc mới
 }
}
```

## DFS xếp hạng topo

- Duyệt DFS đi ngược cạnh
- DFS đi ngược cạnh là: duyệt DFS từ đích → ngược về nguồn, và cập nhật hạng tại u bằng cách xem hạng của các đỉnh v có cạnh v → u.
- Nhưng để tính hạng dựa trên các đỉnh đi vào u, thì cần xét tất cả v sao cho v → u ⇒ phải duyệt ngược cạnh.

- Nghĩa là: duyệt DFS từ u và nhìn ngược lại xem ai đẩy u.
  Nó phù hợp với cách định nghĩa:

`"Hạng của u là max(hạng của các đỉnh đẩy u) + 1"`

### Biến hỗ trợ - DFS

## Cài đặt thuật toán

### Thuật toán

### 🎯 Ví dụ

Cho DAG có **5 đỉnh** và **5 cung**:

```markdown
5 5
1 → 2
1 → 3
3 → 4
2 → 4
4 → 5
```

---

### ✅ Cách tính hạng thủ công:

| Đỉnh | Đường đi dài nhất đến nó | Hạng |
| ---- | ------------------------ | ---- |
| 1    | — (nguồn)                | 0    |
| 2    | 1 → 2                    | 1    |
| 3    | 1 → 3                    | 1    |
| 4    | 1 → 2 → 4 hoặc 1 → 3 → 4 | 2    |
| 5    | 1 → 2 → 4 → 5            | 3    |

---

### ✅ DFS đi ngược: minh hoạ `dfs(5)`

- **Duyệt DFS từ 5**:  
  → Cạnh ngược: `4 → 5`, nên gọi `dfs(4)`

- **Duyệt DFS từ 4**:  
  → Cạnh ngược: `2 → 4` và `3 → 4`  
  → Gọi `dfs(2)` và `dfs(3)`

- **Duyệt DFS từ 2**:  
  → Cạnh ngược: `1 → 2`  
  → Gọi `dfs(1)`

- **Duyệt DFS từ 1**:  
  → Không có ai đẩy 1 → là đỉnh nguồn  
  → `r[1] = 0`

---

#### 🔁 Quay ngược lại:

- `dfs(2)` → `r[2] = r[1] + 1 = 1`
- `dfs(3)` → `r[3] = r[1] + 1 = 1`
- `dfs(4)` → `r[4] = max(r[2] + 1, r[3] + 1) = max(2, 2) = 2`
- `dfs(5)` → `r[5] = r[4] + 1 = 3`

---

### ✅ Tổng kết:

| Đỉnh | Hạng |
| ---- | ---- |
| 1    | 0    |
| 2    | 1    |
| 3    | 1    |
| 4    | 2    |
| 5    | 3    |
