import java.util.*;
import java.io.*;
public class Topological_Sort {
	public static class Node{
		int data;
		Node next;
		Node(int x){
			this.data = x;
			this.next = null;
		}
	}
		public static Node head = null;
		static void insert_start(int x){
			Node n = new Node(x);
			if(head == null){
				head = n;
			}
			else{
				n.next = head;
				head = n;

			}
		}

	
	static class Graph{
		ArrayList<ArrayList<Integer>> adj_list;
		int vertices;
		int time;
		Graph(int number_of_vertices){
			this.vertices = number_of_vertices;
			this.adj_list = new ArrayList<ArrayList<Integer>>(vertices);
			this.time = 1;
		}
	}

	static void insert_in_adj_list(Graph x, int source, int destination){
		x.adj_list.get(source).add(destination);
    	//x.adj_list.get(destination).add(source); 
	}

	static void printGraph(ArrayList<ArrayList<Integer>> adj_list) {
    for (int i = 0; i < adj_list.size(); i++) {
      System.out.println("\nVertex " + i + ":");
      for (int j = 0; j < adj_list.get(i).size(); j++) {
        System.out.print(" -> " + adj_list.get(i).get(j));
      }
      System.out.println();
    }
  }

  static void run_DFS(Graph y, int i, boolean visited[], int start[], int end[]){
    visited[i] = true;
    start[i] =  y.time;
    y.time++;
    for (int j = 0; j < y.adj_list.get(i).size(); j++) {
        if(visited[y.adj_list.get(i).get(j)] != true){
        	
            run_DFS(y, y.adj_list.get(i).get(j), visited, start, end);

        }
      }
      end[i] = y.time;
      insert_start(i);
      y.time++;
  }
  	static void printEnd(Graph y, int start[], int end[]){
  		for(int i = 0; i < y.vertices; i++){
  			System.out.println((i + 1) + " start : " + start[i] + " end : " + end[i] );
  		}
  	}

  	static void print_Topological(){
  		Node temp = head;
  		while(temp != null){
  			System.out.println(temp.data);
  			temp = temp.next;
  		}
  	}




	public static void main(String[] args) throws Exception {
	Reader.init(System.in);
	int vertices = Reader.nextint();
	int edges = Reader.nextint();
	Graph y = new Graph(vertices);
	for (Integer i = 0; i < vertices; i++){
    	y.adj_list.add(new ArrayList<Integer>());
	}
	for(int i = 0; i < edges; i++){
		int source = Reader.nextint();
		int destination = Reader.nextint();
		insert_in_adj_list(y, source - 1, destination - 1);
		
	}
	boolean visited[] = new boolean[vertices];
	int start[] = new int[vertices];
	int end[] = new int[vertices];
	
	for(int i = 0; i < y.adj_list.size(); i++){
		if(!visited[i])
			run_DFS(y, i, visited, start, end);

	}
	print_Topological();
		
	}
}
class Reader {
	
    static BufferedReader reader;
    static StringTokenizer tokenizer;

    static void init(InputStream input) {
        reader = new BufferedReader(new InputStreamReader(input) );
        tokenizer = new StringTokenizer("");
    }

    static String next() throws IOException {
        while ( ! tokenizer.hasMoreTokens() ) {
            //TODO add check for eof if necessary
            tokenizer = new StringTokenizer(
                   reader.readLine() );
        }
        return tokenizer.nextToken();
    }

    static int nextint() throws IOException {
        return Integer.parseInt( next() );
    }
    
    static long nextlong() throws IOException {
        return Long.parseLong( next() );
    }
    
    static double nextdouble() throws IOException {
        return Double.parseDouble( next() );
    }
    
}