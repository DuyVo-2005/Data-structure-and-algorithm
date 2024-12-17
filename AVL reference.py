class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1


class AVLTree:
    # Lấy chiều cao của một node
    def get_height(self, node):
        if not node:
            return 0
        return node.height

    # Tính cân bằng của một node
    def get_balance(self, node):
        if not node:
            return 0
        return self.get_height(node.left) - self.get_height(node.right)

    # Cập nhật chiều cao của node
    def update_height(self, node):
        node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))

    # Quay phải
    def rotate_right(self, y):
        x = y.left
        T2 = x.right
        # Thực hiện quay
        x.right = y
        y.left = T2
        # Cập nhật chiều cao
        self.update_height(y)
        self.update_height(x)
        return x

    # Quay trái
    def rotate_left(self, x):
        y = x.right
        T2 = y.left
        # Thực hiện quay
        y.left = x
        x.right = T2
        # Cập nhật chiều cao
        self.update_height(x)
        self.update_height(y)
        return y

    # Thêm một nút vào cây AVL
    def insert(self, root, key):
        # Bước 1: Thêm nút giống như cây nhị phân tìm kiếm
        if not root:
            return Node(key)
        elif key < root.key:
            root.left = self.insert(root.left, key)
        elif key > root.key:
            root.right = self.insert(root.right, key)
        else:  # Không cho phép thêm trùng khóa
            return root

        # Bước 2: Cập nhật chiều cao của nút cha
        self.update_height(root)

        # Bước 3: Kiểm tra cân bằng và cân bằng lại nếu cần
        balance = self.get_balance(root)

        # Trường hợp mất cân bằng:
        # Trái-Trái
        if balance > 1 and key < root.left.key:
            return self.rotate_right(root)

        # Phải-Phải
        if balance < -1 and key > root.right.key:
            return self.rotate_left(root)

        # Trái-Phải
        if balance > 1 and key > root.left.key:
            root.left = self.rotate_left(root.left)
            return self.rotate_right(root)

        # Phải-Trái
        if balance < -1 and key < root.right.key:
            root.right = self.rotate_right(root.right)
            return self.rotate_left(root)

        return root

    # Duyệt cây theo thứ tự giữa (Inorder Traversal)
    def inorder_traversal(self, root):
        if not root:
            return
        self.inorder_traversal(root.left)
        print(f"{root.key} ", end="")
        self.inorder_traversal(root.right)


# Chạy thử
if __name__ == "__main__":
    avl = AVLTree()
    root = None

    # Chèn các phần tử vào cây
    elements = [10, 20, 30, 40, 50, 25, 9, 8, 7, 6, 5, 4, 3, 2, 1, -1, 11, 13, 15, 17, 19, 18, 16, 14, 12, 100, 90]
    for el in elements:
        root = avl.insert(root, el)

    print("Inorder Traversal của cây AVL là:")
    avl.inorder_traversal(root)
  
