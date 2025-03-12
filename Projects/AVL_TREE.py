class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None
        self.height = 1  # Height is needed for balancing

class AVLTree:
    def get_height(self, node):
        """Returns the height of the node"""
        return node.height if node else 0

    def get_balance(self, node):
        """Gets balance factor of the node"""
        return self.get_height(node.left) - self.get_height(node.right) if node else 0

    def rotate_right(self, y):
        """Performs right rotation"""
        x = y.left
        T2 = x.right

        # Perform rotation
        x.right = y
        y.left = T2

        # Update heights
        y.height = max(self.get_height(y.left), self.get_height(y.right)) + 1
        x.height = max(self.get_height(x.left), self.get_height(x.right)) + 1

        return x  # New root after rotation

    def rotate_left(self, x):
        """Performs left rotation"""
        y = x.right
        T2 = y.left

        # Perform rotation
        y.left = x
        x.right = T2

        # Update heights
        x.height = max(self.get_height(x.left), self.get_height(x.right)) + 1
        y.height = max(self.get_height(y.left), self.get_height(y.right)) + 1

        return y  # New root after rotation

    def insert(self, node, key):
        """Inserts a key into the AVL tree"""
        # Perform normal BST insertion
        if not node:
            return Node(key)
        elif key < node.key:
            node.left = self.insert(node.left, key)
        else:
            node.right = self.insert(node.right, key)

        # Update height of current node
        node.height = max(self.get_height(node.left), self.get_height(node.right)) + 1

        # Get balance factor
        balance = self.get_balance(node)

        # **Balancing the tree**
        # Case 1: Left Heavy (Right Rotation)
        if balance > 1 and key < node.left.key:
            return self.rotate_right(node)

        # Case 2: Right Heavy (Left Rotation)
        if balance < -1 and key > node.right.key:
            return self.rotate_left(node)

        # Case 3: Left-Right Case (Left-Right Rotation)
        if balance > 1 and key > node.left.key:
            node.left = self.rotate_left(node.left)
            return self.rotate_right(node)

        # Case 4: Right-Left Case (Right-Left Rotation)
        if balance < -1 and key < node.right.key:
            node.right = self.rotate_right(node.right)
            return self.rotate_left(node)

        return node  # Return unchanged node

    def inorder_traversal(self, root):
        """In-order traversal (Left, Root, Right)"""
        if root:
            self.inorder_traversal(root.left)
            print(root.key, end=" ")
            self.inorder_traversal(root.right)

# **Usage Example**
tree = AVLTree()
root = None

# Take user input for keys
keys = input("Enter the elements to insert in AVL Tree, separated by spaces: ")
keys = list(map(int, keys.split()))

for key in keys:
    root = tree.insert(root, key)

print("Inorder traversal of AVL tree:")
tree.inorder_traversal(root)  # Output should be sorted