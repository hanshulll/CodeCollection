import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Arrays;
import java.util.PriorityQueue;

public class graph {

	public static void main(String[] args) {
        constructGraph();
        dijkstra(0);

	}

	public static class Edge {
		int v = 0;
		int w = 0;

		Edge(int v, int w) {
			this.v = v;
			this.w = w;
		}
	}

	public static int N = 7;
    public static ArrayList < Edge > [] graph;
   

	public static void addEdge(ArrayList < Edge > [] gp, int u, int v, int w) {
		gp[u].add(new Edge(v, w));
		gp[v].add(new Edge(u, w));
	}

	public static void display(ArrayList < Edge > [] gp) {

		for (int i = 0; i < gp.length; i++) {
			System.out.print(i + "-> ");

			for (Edge e: gp[i]) {
				System.out.print("(" + e.v + ", " + e.w + "), ");
			}
			System.out.println();
        }
        
        System.out.println();
	}

public static int[] par;
public static int[] setSize;

int findPar(int vtx)
{
    if(par[vtx]==vtx) return vtx;
    return par[vtx]=findPar(par[vtx]);
}

void mergeSet(int l1, int l2)
{
    if (setSize[l1] < setSize[l2])
    {
        par[l1] = l2;
        setSize[l2] += setSize[l1];
    }
    else
    {
        par[l2] = l1;
        setSize[l1] += setSize[l2];
    }
}

void kruskalalgo(int[][] arr)
{
    ArrayList < Edge > [] Kgraph=new ArrayList[N];

    for(int i=0;i<N;i++)
    {
        Kgraph[i]=new ArrayList<Edge>();
    }

    Arrays.sort(arr,(int[] a, int[] b)->{ //a=this  b=other
        return a[2]-b[2]; //inc order
        //return b[2]-[2]  DEC order
    });
     for(int[] ar: arr)
     {
         int u=ar[0];
         int v=ar[1];
         int p1=findPar(u);
         int p2=findPar(v);
         if(p1!=p2)
         {
             mergeSet(p1,p2);
             addEdge(Kgraph,p1,p2,ar[2]);
         }
     }
}

// static class pair_ implements Comparable<pair_>{ 
// 	   int src;
// 	   int par;
// 	   int w;
// 	   int wsf;
 
// 	   pair_(int src,int par,int w,int wsf){
// 		   this.src=src;
// 		   this.par=par;
// 		   this.w=w;
// 		   this.wsf=wsf;
// 	   }

// 	   public compareTo(pair_ o){
// 		return this.wsf - o.wsf;  // default -> min PQ.  (this - other)
// 		// return o.wsf - this.wsf;  // max PQ.
// 	   }
// }    
static class dpair{
    int src;
    int par;
    int w;
    int wsf;

    dpair(int src,int par, int w, int wsf)
    {
        this.src=src;
        this.par=par;
        this.w=w;
        this.wsf=wsf;
    }

}

public static void dijkstra(int src)
{
       ArrayList < Edge > [] Dgraph=new ArrayList[N];
      boolean[] vis=new boolean[N];
      
      for (int i = 0; i < N; i++) {
			Dgraph[i] = new ArrayList < Edge > ();
		}

        PriorityQueue<dpair> pq=new PriorityQueue<>((dpair a, dpair b)->{
           return a.wsf-b.wsf;   //min pq
         });

        pq.add(new dpair(src,-1,0,0));

        while(pq.size()!=0)
        {
            int sz=pq.size();
            while(sz-- >0)
            {
                dpair rvtx=pq.poll();
                if(vis[rvtx.src])
                {
                    continue;
                }
                if(rvtx.par!=-1)
                {
                    addEdge(Dgraph,rvtx.src,rvtx.par,rvtx.w);
                }

                vis[rvtx.src]=true;

                for( Edge e: graph[rvtx.src])
                {
                    if(!vis[e.v])
                    pq.add(new dpair(e.v,rvtx.src,e.w,rvtx.wsf+e.w));
                }
            }
            display(Dgraph);
        }
}
static class primpair{
    int src;
    int par;
    int w;  

    primpair(int src,int par,int w)
    {
        this.src=src;
        this.par=par;
        this.w=w;
    }
}

public static void prims(int src)
{
      ArrayList < Edge > [] Pgraph=new ArrayList[N];
      boolean[] vis=new boolean[N];
      
      for (int i = 0; i < N; i++) {
			Pgraph[i] = new ArrayList < Edge > ();
		}

         PriorityQueue<primpair> pq=new PriorityQueue<>((primpair a, primpair b)->{
           return a.w-b.w;   //min pq
         });
       
       pq.add(new(src,-1,0));

       while(pq.size()!=0)
       {
           int sz=pq.size();
           while(sz-- >0)
           {
               primpair rvtx=pq.poll();

               if(vis[rvtx.src])
               {
                 continue;
               }
               if(rvtx.par!=-1)
               {
                   addEdge(Pgraph,rvtx.src,rvtx.par,rvtx.w);     
               }

                for( Edge e: graph[rvtx.src])
                {
                    if(!vis[e.v])
                    {
                        pq.add(new primpair(e.v,rvtx.src,e.w));
                    }
                }
           }
       }

}

public static void constructGraph() {
		graph = new ArrayList[N];
		for (int i = 0; i < N; i++) {
			graph[i] = new ArrayList < Edge > ();
		}

		addEdge(graph, 0, 1, 10);
		addEdge(graph, 0, 3, 10);
		addEdge(graph, 1, 2, 10);
		addEdge(graph, 2, 3, 40);
		addEdge(graph, 3, 4, 2);
		addEdge(graph, 4, 5, 2);
		addEdge(graph, 4, 6, 3);
        addEdge(graph, 5, 6, 8);
        
        
       // display(graph);

	}
}
