import java.util.*;
import java.io.*;
public class Dijkstra {
	static class Weight_pair{
	int weight,num;
	Weight_pair(int a, int b){
		num = a;
		weight = b;
	}
}
	static Comparator<Weight_pair> compare_func = (a, b) -> {
            if (a.weight < b.weight)
                return 1;
            if (a.weight > b.weight)
                return -1; 
            return 0;
        };
        
	static class Graph{
		List<List<Weight_pair>> adj_list;
		int vertices;
		Graph(int number_of_vertices){
			this.vertices = number_of_vertices;
			this.adj_list = new ArrayList<>(vertices);
		}
	}

	static void insert_in_adj_list(Graph x, int source, int destination, int weight){
		x.adj_list.get(source).add(new Weight_pair(destination, weight));
    	x.adj_list.get(destination).add(new Weight_pair(source, weight)); 
    	
	}



	public static void main(String[] args) throws Exception {
	Reader.init(System.in);
	int vertices = Reader.nextint();
	int edges = Reader.nextint();
	Graph y = new Graph(vertices);
	PriorityQueue<Weight_pair> pq = new PriorityQueue<>(compare_func);
	
	boolean visited[] = new boolean[vertices];
		for (Integer i = 0; i < vertices; i++){
    	y.adj_list.add(new ArrayList<Weight_pair>());
    	
    	
	}
	for(int i = 0; i < edges; i++){
		int source = Reader.nextint();
		int destination = Reader.nextint();
		int weight = Reader.nextint();
		insert_in_adj_list(y, source - 1, destination - 1, weight);
		
		
	}
	List<Integer> dist = new ArrayList<Integer>();
	for (Integer i = 0; i < vertices; i++){
    	dist.add(Integer.MAX_VALUE);
    	
    	
	}
	int source_node = 0;
	dist.set(source_node, 0);
	pq.add(new Weight_pair(source_node, 0));

        while (!pq.isEmpty()) {

            Weight_pair pair = pq.peek();
            pq.remove();

            int vertex = pair.num;

            for (Weight_pair u : y.adj_list.get(vertex)) {

                int side_vertex = u.num;
                int edge_length = u.weight;

                if (dist.get(side_vertex) > edge_length + dist.get(vertex)) {

                    if (dist.get(side_vertex) != Integer.MAX_VALUE) {
                        pq.remove(new Weight_pair(side_vertex, dist.get(side_vertex)));
                    }
                    dist.set(side_vertex, edge_length + dist.get(vertex));
                    pq.add(new Weight_pair(side_vertex, dist.get(side_vertex)));
                }
            }
        }
        for (int i=0; i<vertices; i++)
            System.out.println("Source Node(" + source_node + ") -> Destination Node(" + i + ") : " + dist.get(i));
		
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