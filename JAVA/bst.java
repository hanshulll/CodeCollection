public class bst {
    static Node root;

    static class Node {
        int data;
        Node left, right;

        Node(int data) {
            this.data = data;
            left = null;
            right = null;
        }
    }

    Node insert(Node node, int value) {
        if (node == null) {
            return new Node(value);
        }

        if (value < node.data) {
            if (node.left != null) {
                insert(node.left, value);
            } else
                node.left = new Node(value);
        } else if (value > node.data) {
            if (node.right != null) {
                insert(node.right, value);
            } else
                node.right = new Node(value);
        }
        return node;
    }

    void add(int data) {
        root = insert(root, data);
    }

    void displayInOrder(Node node) {
        if (node == null) {
            return;
        } else {
            displayInOrder(node.left);
            System.out.print(" " + node.data);
            displayInOrder(node.right);
        }
    }

    void displayPreOrder(Node node) {
        if (node == null) {
            return;
        } else {
            System.out.print(" " + node.data);
            displayPreOrder(node.left);
            displayPreOrder(node.right);
        }
    }

    void displayPostOrder(Node node) {
        if (node == null) {
            return;
        } else {
            displayPostOrder(node.left);
            displayPostOrder(node.right);
            System.out.print(" " + node.data);
        }
    }

    public static void main(String args[]) {
        bst bt = new bst();

        bt.add(2);
        bt.add(4);
        bt.add(8);
        bt.add(6);
        bt.add(7);
        bt.add(3);
        bt.add(9);
        System.out.println("InOrder:");
        bt.displayInOrder(root);
        System.out.println("");
        System.out.println("PreOrder:");

        bt.displayPreOrder(root);
        System.out.println(" ");
        System.out.println("PostOrder:");
        bt.displayPostOrder(root);
    }
}
