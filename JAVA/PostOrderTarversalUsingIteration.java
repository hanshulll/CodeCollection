import java.util.Stack;

class Node
{
	int data;
	Node left, right;

	// Function to create a new binary tree node having a given key
	public Node(int key)
	{
		data = key;
		left = right = null;
	}
}


public class PostOrderItr {
	
	static  void Inorder(Node root) {
		
		Stack<Node> stack = new Stack<Node>();
		
		stack.push(root);
		
		
		Stack<Integer> out = new Stack<Integer>();
		
		while(!stack.isEmpty()) {
			
			Node curr = stack.pop();
			out.push(curr.data);
			
			if(curr.left != null) {
				stack.push(curr.left);
			}
			
			if(curr.right != null) {
				stack.push(curr.right);
			}
			
			
		}
		
		while(!out.isEmpty()) {
			System.out.print(out.pop()+" ");
		}
		
		
	}
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Node root = new Node(2);
		root.left = new Node(4);
		root.right = new Node(1);
		root.left.left = new Node(7);
		root.right.left = new Node(8);
		root.right.right = new Node(3);
		
		
		Inorder(root);
	}

}
