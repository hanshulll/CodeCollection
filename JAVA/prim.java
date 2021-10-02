
class Prim {

	private static final int Vertices = 7;

	// create Min_Key_Vertex() method
	int min_key_vertex(int keys[], Boolean setOfMST[]) {
		// Initialize min value and its index
		int min_index = -1;
		int mini_value = Integer.MAX_VALUE;

		for (int i = 0; i < Vertices; i++)
			if (setOfMST[i] == false && keys[i] < mini_value) {
				mini_value = keys[i];
				min_index = i;
			}

		return min_index;
	}

	void MinimumSpanningTree(int mstArray[], int graphArray[][]) {
		System.out.println("     Edge \t\tWeight");
		for (int j = 1; j < Vertices; j++)
			System.out.println(" ( " + mstArray[j] + " --- " + j + "\t \t" + graphArray[j][mstArray[j]] + " ) ");
	}

	// create MST() method
	void mst(int graphArray[][]) {
		int mstArray[] = new int[Vertices];

		int keys[] = new int[Vertices];

		Boolean setOfMST[] = new Boolean[Vertices];

		for (int j = 0; j < Vertices; j++) {
			keys[j] = Integer.MAX_VALUE;
			setOfMST[j] = false;
		}

		keys[0] = 0;
		mstArray[0] = -1;
		for (int i = 0; i < Vertices - 1; i++) {
			int edge = min_key_vertex(keys, setOfMST);

			setOfMST[edge] = true;

			for (int vertex = 0; vertex < Vertices; vertex++)

				if (graphArray[edge][vertex] != 0 && setOfMST[vertex] == false
						&& graphArray[edge][vertex] < keys[vertex]) {
					mstArray[vertex] = edge;
					keys[vertex] = graphArray[edge][vertex];
				}
		}

		MinimumSpanningTree(mstArray, graphArray);
	}

	public static void main(String[] args) {

		Prim mst = new Prim();
		int graphArray[][] = new int[][] {
											{0 , 28, 0 , 0 , 0 , 10, 0 },
											{28, 0 , 16, 0 , 0 , 0 , 14},
											{0 , 16, 0 , 12, 0 , 0 , 0 },
											{0 , 0 , 12, 0 , 22, 0 , 18},
											{0 , 0 , 0 , 22, 0 , 25, 24},
											{10, 0 , 0 , 0 , 25, 0 , 0 },
											{0 , 14, 0 , 18, 24, 0 , 0 }
											};

		mst.mst(graphArray);
	}
}
