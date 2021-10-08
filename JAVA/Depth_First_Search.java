package DepthFirstSearch;

import java.util.Iterator;
import java.util.Stack;
import java.util.LinkedList;



public class DFS {
	
        // No. of vertices
        private int V; 
		
	//Adjacency List
        private LinkedList<Integer> adjacency[];
        
	//linkedlist to put the final path
        LinkedList<Integer> finalqueue = new LinkedList<Integer>(); 
	
	//to count iterations takes to reach the goal node
        int iteration=1; 
	
	//number of items removed from queue
        int count=0; 
	 
	//cost to go from 2-25 cells (
        double cost=0; 
        
        // nodes expanded from the visited node
        int nodesExpanded=0; 

        //Constructor
	DFS(int V)
        {
	    this.V = V;
	    adjacency = new LinkedList[V];
	    for (int i = 0; i < adjacency.length; i++)
            {
                adjacency[i] = new LinkedList<Integer>();
            }
				
	}
		
	//To add an edge to graph
	void addEdge(int v, int w)
	{
            adjacency[v].add(w); // Add w to v’s list.
	}
		
	// function DepthFirstSearch
	void DFS(int s)
	{
	    //start time
	    long start = System.currentTimeMillis();
	    
	    // Mark all the vertices as not visited(By default set as false)
	    boolean visited[] = new boolean[V];

	    // Create a stack for DFS
	    Stack<Integer> stack = new Stack<>();
			
	    // Mark the current node as visited and add to stack
            visited[s]=true;
	    stack.push(s);
			
	    //loop to check each node in stack whether it matches the goal node
            while(stack.empty() == false)
	    {
		//prints the nodes in memory
                System.out.print("iteration "+ iteration + " = nodes in memory : " +stack +"\n\n");
				
                // Pop a vertex from stack and print it
		s = stack.peek();
		stack.pop();
		count++;
		// when a node is visited, we are moving from one cell to another
                cost++; 		
				
		//add the node removed from to final path
                finalqueue.add(s);
			
				
		// Get all adjacent vertices of the removed vertex s
		// if an adjacent is not visited push to stack and add to visited[]
		// if already visited skips it
		Iterator<Integer> itr = adjacency[s].iterator();
		while (itr.hasNext()) 
		   {
			int v = itr.next();
			if(!visited[v])
			   {
			        visited[v] = true;
				stack.push(v);
                                nodesExpanded++;
	                   }
                   }if(s == 25)break;
		iteration++;
				
	
            }
			
	    //printing the finalqueue which contains the final path
            System.out.print("DFS final path = " +finalqueue+"\n\n");
				
	    //end time
	    long end = System.currentTimeMillis();
		
            //finding the time difference and converting it into seconds
            float sec = (end - start) / 1000F; System.out.println(sec + " seconds");
      
            //the number of nodes expanded when we visited a particular node
            System.out.print("full nodes expanded = " +nodesExpanded+"\n\n");
		
	    //total cost of BFS search, cause we are already in 2 cell need to minus 1
            System.out.print("total cost of DFS = " +(cost-1)+"\n\n"); 
      	   
				
    }
                
	// main method holding graph edges
	public static void main(String[] args) 
	{
		//creating instance of the class
		DFS g = new DFS(26);

                //passing the edges of the graph to the addEdge
                g.addEdge(2,1); 
                g.addEdge(2,3); 
                g.addEdge(2,7);
                
                g.addEdge(3,4); 
                g.addEdge(3,8); 
                g.addEdge(3,2);
                
                g.addEdge(4,5);
                g.addEdge(4,3); 
                g.addEdge(4,9);
                
                g.addEdge(5,4); 
                g.addEdge(5,10);
                
                g.addEdge(6,1);
                g.addEdge(6,7); 
                g.addEdge(6,11);
                
                g.addEdge(7,2);
                g.addEdge(7,6); 
                g.addEdge(7,8);
                g.addEdge(7,12);
                
                g.addEdge(8,9); 
                g.addEdge(8,13);
                g.addEdge(8,7); 
                g.addEdge(8,3);
                
                g.addEdge(9,10);
                g.addEdge(9,14);
                g.addEdge(9,8);
                g.addEdge(9,4);
                
                g.addEdge(10,15); 
                g.addEdge(10,9); 
                g.addEdge(10,5);
                
                g.addEdge(11,12); 
                g.addEdge(11,16); 
                g.addEdge(11,6);
                
                g.addEdge(12,7);
                g.addEdge(12,11);
                g.addEdge(12,13);
                g.addEdge(12,17);

                g.addEdge(13,14); 
                g.addEdge(13,18); 
                g.addEdge(13,12); 
                g.addEdge(13,8);
                
                g.addEdge(14,15); 
                g.addEdge(14,19); 
                g.addEdge(14,13); 
                g.addEdge(14,9);
                
                g.addEdge(15,20); 
                g.addEdge(15,14); 
                g.addEdge(15,10);
                
                g.addEdge(16,11);
                g.addEdge(16,21);
                g.addEdge(16,17);
                
                g.addEdge(17,12);
                g.addEdge(17,16);
                g.addEdge(17,18);
                g.addEdge(17,22);
                
                g.addEdge(18,19); 
                g.addEdge(18,23); 
                g.addEdge(18,17); 
                g.addEdge(18,13);
                
                g.addEdge(19,20); 
                g.addEdge(19,24); 
                g.addEdge(19,18); 
                g.addEdge(19,14);
                
                g.addEdge(20,19); 
                g.addEdge(20,25); 
                g.addEdge(20,15);
                
                g.addEdge(21,22); 
                g.addEdge(21,16);
                
                g.addEdge(22,23); 
                g.addEdge(22,21); 
                g.addEdge(22,17);
                
                g.addEdge(23,24); 
                g.addEdge(23,22); 
                g.addEdge(23,18);
                
                g.addEdge(24,25); 
                g.addEdge(24,23); 
                g.addEdge(24,19);
                
                g.addEdge(25,24); 
                g.addEdge(25,20);
      
                //passing the starting vertex to the function
                g.DFS(2);
	}
}