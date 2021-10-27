import java.util.ArrayList;
import java.util.Stack; 
public class Solution
{
    public static void printZigZag(BinaryTreeNode<Integer> root)
    {
        
        QueueUsingLL<BinaryTreeNode<Integer>> queue = new QueueUsingLL<>(); 
        Stack<BinaryTreeNode<Integer>> stack = new Stack<>();
        int level = 1; 
        queue.enqueue(root); 
        while(!queue.isEmpty())
        {
            BinaryTreeNode<Integer> currentNode; 
            try 
            {
                currentNode = queue.dequeue();
                System.out.print(currentNode.data+" "); 
                    if(level % 2 == 0)
                    {
                        if(currentNode.right != null)
                            stack.push(currentNode.right); 
                        if(currentNode.left != null) 
                            stack.push(currentNode.left); 
                    }
                else
                {
                    if(currentNode.left != null) 
                        stack.push(currentNode.left); 
                    if(currentNode.right != null)
                        stack.push(currentNode.right); 
                }
                if(queue.isEmpty())
                {
                    while(!stack.isEmpty())
                    {
                        queue.enqueue(stack.pop());
                    }
                    System.out.println(); 
                    level++; 
                }
            } catch (QueueEmptyException e) 
            {
            }
        }
    }
}