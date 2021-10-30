import java.util.*;

public class inverseTree {
    static Node root = null;

    class Node {
        int data;
        Node right;
        Node left;

        Node(int data) {
            this.data = data;
            right = left = null;
        }
    }

    public void add(int data) {
        root = insert(root, data);
    }

    Node insert(Node root, int data) {
        if (root == null) {
            root = new Node(data);
            return root;
        }
        if (data < root.data) {
            root.right = insert(root.right, data);
        } else if (data > root.data) {
            root.left = insert(root.left, data);
        }
        return root;
    }

    int height(Node root) {
        if (root == null) {
            return 0;
        } else {
            int lh = height(root.left);
            int rh = height(root.right);
            if (lh > rh) {
                return (lh + 1);
            } else
                return (rh + 1);

        }

    }

    void printLevel() {
        int h = height(root);
        int i = 1;
        for (i = h; i > 0; i--) {
            printGlevel(root, i);

        }

    }

    void printGlevel(Node root, int i) {
        if (root == null) {
            return;
        }
        if (i == 1) {
            System.out.println(root.data + " ");
        } else if (i > 1) {
            printGlevel(root.left, i - 1);
            printGlevel(root.right, i - 1);
        }
    }

    public static void main(String args[]) {
        inverseTree bt = new inverseTree();

        bt.add(40);
        bt.add(70);
        bt.add(30);
        bt.add(80);
        bt.add(50);
        bt.add(35);
        bt.add(20);
        bt.add(10);
        System.out.println("Height of tree: " + bt.height(root));
        bt.printLevel();

    }
}
