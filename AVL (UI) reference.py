import matplotlib.pyplot as plt
import networkx as nx

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1

class AVLTree:
    def get_height(self, node):
        if not node:
            return 0
        return node.height

    def get_balance(self, node):
        if not node:
            return 0
        return self.get_height(node.left) - self.get_height(node.right)

    def update_height(self, node):
        node.height = 1 + max(self.get_height(node.left), self.get_height(node.right))

    def rotate_right(self, y):
        x = y.left
        T2 = x.right
        x.right = y
        y.left = T2
        self.update_height(y)
        self.update_height(x)
        return x

    def rotate_left(self, x):
        y = x.right
        T2 = y.left
        y.left = x
        x.right = T2
        self.update_height(x)
        self.update_height(y)
        return y

    def insert(self, root, key):
        if not root:
            return Node(key)
        elif key < root.key:
            root.left = self.insert(root.left, key)
        elif key > root.key:
            root.right = self.insert(root.right, key)
        else:
            return root
        
        self.update_height(root)
        balance = self.get_balance(root)

        # Cân bằng cây
        if balance > 1 and key < root.left.key:
            return self.rotate_right(root)
        if balance < -1 and key > root.right.key:
            return self.rotate_left(root)
        if balance > 1 and key > root.left.key:
            root.left = self.rotate_left(root.left)
            return self.rotate_right(root)
        if balance < -1 and key < root.right.key:
            root.right = self.rotate_right(root.right)
            return self.rotate_left(root)

        return root

    # Vẽ cây AVL
    def draw_tree(self, root):
        graph = nx.DiGraph()
        pos = {}
        self._add_edges(graph, root, None, pos, 0, 0, 1)
        plt.figure(figsize=(10, 8))
        nx.draw(graph, pos, with_labels=True, node_size=2000, node_color="skyblue", font_size=12, font_weight="bold")
        plt.title("Mô phỏng cây AVL")
        plt.show()

    def _add_edges(self, graph, node, parent, pos, x, y, dx):
        if node is None:
            return
        graph.add_node(node.key)
        pos[node.key] = (x, -y)  # Điều chỉnh tọa độ
        if parent:
            graph.add_edge(parent.key, node.key)
        self._add_edges(graph, node.left, node, pos, x - dx, y + 1, dx / 2)
        self._add_edges(graph, node.right, node, pos, x + dx, y + 1, dx / 2)

# Chạy thử chương trình
if __name__ == "__main__":
    avl = AVLTree()
    root = None

    # Chèn các phần tử vào cây AVL
    elements = [10, 20, 30, 40, 50, 25, 9, 8, 7, 6, 5, 4, 3, 2, 1, -1, 11, 13, 15, 17, 19, 18, 16, 14, 12, 100, 90]
    for el in elements:
        root = avl.insert(root, el)

    # Vẽ cây AVL
    avl.draw_tree(root)
      
