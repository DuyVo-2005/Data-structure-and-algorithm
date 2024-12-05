import tkinter as tk
from tkinter import messagebox
import math

MAXLEN = 1000
stack = None
adj = []
visited = []
result = []
positions = {}
canvas = None
result_text = None
entry_so_dinh = None
entry_so_canh = None
entry_edges = None
entry_start = None


class Stack:
    def __init__(self):
        self.M = []
        self.top = -1

    def push(self, value):
        if not self.is_full():
            self.top += 1
            self.M.append(value)

    def pop(self):
        if not self.is_empty():
            value = self.M[self.top]
            self.M.pop()
            self.top -= 1
            return value
        return None

    def is_empty(self):
        return self.top == -1

    def is_full(self):
        return self.top == MAXLEN


def draw_graph(so_dinh):
    """vẽ một biểu đồ hình tròn có so_dinh đỉnh trên một canvas"""
    canvas.delete(
        "all"
    )  # xóa tất cả các phần tử hiện có trên canvas để bắt đầu vẽ mới từ đầu
    radius = 150  # bán kính của hình tròn mà các đỉnh sẽ nằm trên đó
    center_x, center_y = 300, 200  # tọa độ tâm của hình tròn trên canvas
    global positions
    positions = {}  # biến toàn cục positions để lưu trữ vị trí của các đỉnh

    for i in range(1, so_dinh + 1):
        # Tính góc của đỉnh thứ i theo đơn vị radian. Đỉnh được phân bố đều trên hình tròn
        angle = 2 * math.pi * i / so_dinh
        # Tính tọa độ x, y của đỉnh dựa trên góc và bán kính
        x = center_x + radius * math.cos(angle)
        y = center_y + radius * math.sin(angle)
        positions[i] = (x, y)  # Lưu tọa độ của đỉnh vào dictionary positions
        canvas.create_oval(
            x - 20, y - 20, x + 20, y + 20, fill="lightblue", tags=f"{i}"
        )  # Vẽ một hình oval (để làm đỉnh) tại vị trí (x, y) với màu nền là xanh nhạt.
        canvas.create_text(x, y, text=str(i), font=("Times New Roman", 13), tags=f"{i}")


def draw_edges():
    """vẽ các cạnh giữa các đỉnh trong một biểu đồ dựa trên danh sách kề adj
    và vị trí của các đỉnh đã được lưu trong dictionary positions"""
    # duyệt qua từng đỉnh u trong biểu đồ, adj là danh sách kề chứa thông tin về các đỉnh kề của mỗi đỉnh.
    for u in range(1, len(adj)):
        # duyệt qua các đỉnh v kề với đỉnh u.
        for v in adj[u]:
            x1, y1 = positions[
                u
            ]  # Lấy tọa độ (x1, y1) của đỉnh u từ dictionary positions
            x2, y2 = positions[
                v
            ]  # Lấy tọa độ (x2, y2) của đỉnh v từ dictionary positions
            # Vẽ một đường thẳng (cạnh) từ điểm (x1, y1) đến điểm (x2, y2) trên canvas với màu đen
            # tags=f"{u}_{v}" được sử dụng để gán thẻ duy nhất cho cạnh
            # giúp dễ dàng tham chiếu hoặc thao tác về sau
            canvas.create_line(x1, y1, x2, y2, fill="black", tags=f"{u}_{v}")


def highlight_node(node, color):
    """dùng để làm nổi bật một đỉnh cụ thể trên canvas bằng cách thay đổi màu sắc của nó"""
    x, y = positions[node]  # Lấy tọa độ (x, y) của đỉnh node từ dictionary positions
    canvas.create_oval(x - 20, y - 20, x + 20, y + 20, fill=color, tags=f"{node}")
    canvas.create_text(
        x, y, text=str(node), font=("Times New Roman", 13), tags=f"{node}"
    )


def run_dfs():
    """triển khai một thuật toán tìm kiếm theo chiều sâu (DFS)
    trên một đồ thị không có hướng và không có trọng số"""
    global adj, visited, stack, result
    try:
        so_dinh = int(entry_so_dinh.get())
        so_canh = int(entry_so_canh.get())
        # Lấy toàn bộ nội dung của widget văn bản entry_edges từ vị trí dòng đầu tiên
        # ký tự đầu tiên ("1.0") đến cuối văn bản (tk.END)
        # strip(): Xóa bỏ tất cả các khoảng trắng thừa ở đầu và cuối của chuỗi thu được
        # split("\n"):Tách chuỗi đã được xóa khoảng trắng thành một danh sách các chuỗi con
        # mỗi chuỗi đại diện cho một dòng văn bản
        edges = entry_edges.get("1.0", tk.END).strip().split("\n")
        start = int(entry_start.get())
    except ValueError:
        messagebox.showerror("Lỗi", "Vui lòng nhập dữ liệu hợp lệ!")
        return

    # Khởi tạo đồ thị
    adj = [[] for _ in range(so_dinh + 1)]
    for edge in edges:
        try:
            u, v = map(int, edge.split())
            adj[u].append(v)
            adj[v].append(u)
        except ValueError:
            messagebox.showerror("Lỗi", f"Cạnh không hợp lệ: {edge}")
            return

    # Vẽ đồ thị
    draw_graph(so_dinh)
    draw_edges()

    for i in range(1, so_dinh + 1):
        adj[i].sort(reverse=True)

    visited = [False] * (so_dinh + 1)
    stack = Stack()
    result = []
    stack.push(start)

    result_text.config(state="normal")  # có thể chỉnh sửa result text: state="normal"
    # Xóa toàn bộ nội dung hiện có trong widget văn bản result_text
    # Tham số "1.0" chỉ vị trí bắt đầu của văn bản (dòng 1, cột 0) và tk.END chỉ vị trí kết thúc của văn bản
    result_text.delete(1.0, tk.END)
    result_text.insert(tk.END, "Bắt đầu DFS từ đỉnh " + str(start) + "\n")

    dfs_step()


def dfs_step():
    global stack, visited, result
    if stack.is_empty():
        result_text.insert(tk.END, "Kết thúc DFS.\n")
        result_text.config(state="disabled")
        return

    u = stack.pop()
    if not visited[u]:
        result.append(u)
        visited[u] = True
        result_text.insert(tk.END, f"Thăm đỉnh {u}\n")
        highlight_node(u, "lightgreen")

    for v in sorted(adj[u], reverse=True):
        if not visited[v]:
            stack.push(v)
            result_text.insert(tk.END, f"Đẩy {v} vào stack\n")

    root.after(800, dfs_step)  # sẽ đợi 800 mili giây (0.8 giây) rồi gọi hàm dfs_step


root = tk.Tk()
root.title("Mô phỏng DFS")

# Nhập liệu
input_frame = tk.Frame(root)
input_frame.pack(pady=10)

tk.Label(input_frame, text="Số đỉnh:").grid(row=0, column=0)
entry_so_dinh = tk.Entry(input_frame, width=5)
entry_so_dinh.grid(row=0, column=1)

tk.Label(input_frame, text="Số cạnh:").grid(row=0, column=2)
entry_so_canh = tk.Entry(input_frame, width=5)
entry_so_canh.grid(row=0, column=3)

tk.Label(input_frame, text="Các cạnh (u v):").grid(row=1, column=0)
entry_edges = tk.Text(input_frame, width=30, height=5)
entry_edges.grid(
    row=2, column=0, columnspan=4, pady=5
)  # columnspan=4 chỉ định rằng một widget sẽ chiếm 4 cột trong lưới.

tk.Label(input_frame, text="Đỉnh bắt đầu:").grid(row=3, column=0)
entry_start = tk.Entry(input_frame, width=5)
entry_start.grid(row=3, column=1)

run_button = tk.Button(input_frame, text="Chạy DFS", command=run_dfs)
run_button.grid(row=3, column=2)

# Canvas vẽ vùng chứa đồ thị
canvas = tk.Canvas(root, width=550, height=400, bg="white")
canvas.pack()

# Kết quả
result_label = tk.Label(root, text="Kết quả DFS:", font=("Times New Roman", 10))
result_label.pack()
result_text = tk.Text(
    root, width=50, height=10, state="disabled"
)  # state="disabled": không thể chỉnh result_text
result_text.pack()

root.mainloop()
"""
so dinh: 8, so canh: 7
cac canh
1 2
1 6
2 3
2 5
3 4
3 8
6 7
"""
