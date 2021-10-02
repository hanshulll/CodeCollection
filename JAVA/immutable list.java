// Below is the Java program to create ImmutableList

import com.google.common.collect.ImmutableList;
import java.util.*;

class GFG {

	// Function to create ImmutableList from List
	public static <T> void iList(List<T> list)
	{
		// Create ImmutableMap from Map using copyOf()
		ImmutableList<T> immutableList =
						ImmutableList.copyOf(list);

		// Print the ImmutableMap
		System.out.println(immutableList);
	}

	public static void main(String[] args)
	{
		List<String> list = new ArrayList<>(
			Arrays.asList("Geeks", "For", "Geeks"));

		iList(list);
	}
}
