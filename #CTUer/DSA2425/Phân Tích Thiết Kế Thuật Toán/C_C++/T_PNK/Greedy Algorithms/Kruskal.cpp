#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>    // for sort() function
using namespace std;

//Bước 1: Biểu diễn bằng phương pháp danh sách các cung (list of edges)
//Sử dụng cấu trúc Edge để lưu cung (u, v, w)
typedef struct {
    int u, v;
    int w;
} Edge;

//Với mỗi cung u --w--> v, ta lưu (u, v, w)

#define MAX_N 101               // Tối đa 100 đỉnh, đánh số đỉnh từ 1
struct Graph {                  // Khai báo struct kiểu C++, không cần dùng typedef
    int n, m;                   // n: số đỉnh, m: số cung
    Edge edges[MAX_N];          // danh sách cung, lưu từ 0
};


//Bước 2: Định nghĩa hàm so sánh nhỏ hơn dùng để sắp xếp các cung
int edge_compare(const Edge& a, const Edge& b) {
    return a.w < b.w;   // Cung a được gọi là nhỏ hơn (đứng trước) cung b
                        // <=> trọng số của a < trọng số của b
}

//Bước 3: khai báo các biến toàn cục
int parent[MAX_N];  // Dùng để quản lý các BPLT


//Bước 4: Định nghĩa hàm find_root
int find_root(int u) {
    // Tìm và trả về nút gốc của cây chứa u
    while (u != parent[u])                            
        u = parent[u];                                
                                                      
    return u;                                         
                                                      
}

//Bước 5: Cài đặt thuật toán Kruskal tìm cây không nhỏ nhất của đồ thị
void Kruskal(Graph *pG, Graph *pMST) {
    // Sắp xếp các cung của đồ thị G theo thứ tự trọng số tăng dần (thực ra là không giảm)
    // Hàm sort của STL sắp xếp một mảng (hoặc 1 container) trong nửa đoạn [first, last)
    // theo thứ tự do hàm compare quy định.
    // Nếu không cung cấp hàm compare, sort sẽ dùng phép toán so sánh < để sắp xếp (tăng dần).
    // template< class RandomIt, class Compare >
    //              void sort(RandomIt first, RandomIt last, Compare compare);

    // Chúng ta muốn sắp xếp các cung theo thứ cung nhỏ đứng trước cung lớn
    // Vì thế hàm edge_compare phải trả về true khi trọng số cung a < trọng số cung b
    sort(pG->edges, pG->edges + pG->m, edge_compare);
    

    // Khởi tạo rừng các BPLT
    // Gán parent của các u = chính nó
    for (int u = 1; u <= pG->n; u++)                  
        parent[u] = u;                                

    
    // Khởi tạo cây MST rỗng
    pMST->n = pG->n; // Cây khung bao gồm các đỉnh của đồ thị gốc
    pMST->m = 0;     // Cây kết quả chưa có cung nào cả

    // Lặp qua các cung đã sắp xếp của G
    for (int e = 0; e < pG->m; e++) {
        int u, v, w;
        // Gán (u, v, w) = phần tử thứ e của danh sách các cung edges
        u = pG->edges[e].u;                               
        v = pG->edges[e].v;                               
        w = pG->edges[e].w;                               

        int root_u = find_root(u);
        int root_v = find_root(v);
        
        // Nếu u và v ở 2 cây khác nhau
        if (root_u != root_v              ) {
            // Thêm cung (u, v, w) vào pMST
            int m = pMST->m;                                  
            pMST->edges[m].u = u;                             
            pMST->edges[m].v = v;                             
            pMST->edges[m].w = w;                             
            pMST->m++;                                        
                                                              
            
            // Gom 2 cây chứa u và chứa v lại thành 1 cây duy nhất
            parent[root_v] = root_u;                          
        }
    }
}

//Bước 4: Kiểm thử
int main() {
    Graph G;
    
    cin >> G.n >> G.m;
    
    //Đọc các cung và thêm vào đồ thị
    for (int e = 0; e < G.m; e++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        // Gán edges[e] = (u, v, w)
        G.edges[e].u = u;                                 
        G.edges[e].v = v;                                 
        G.edges[e].w = w;                                 
    }
    
    Graph MST;
    Kruskal(&G, &MST);
    
    int total_weight = 0;
    for (int e = 0; e < MST.m; e++) {
        printf("(%d, %d, %d)\n", MST.edges[e].u, MST.edges[e].v, MST.edges[e].w);
        total_weight += MST.edges[e].w;
    }
        
    cout << "Total weight: " << total_weight << endl;

    return 0;
}
