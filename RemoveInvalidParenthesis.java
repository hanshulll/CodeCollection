import java.util.*;

public class RemoveInvalidParenthesis {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String s = "()())())";
		Stack<Character> st = new Stack<Character>();
		int count = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == '(') {
				st.add(s.charAt(i));
			} else if (s.charAt(i) == ')') {
				if (st.size() == 0) {
					count++;
				} else {
					st.pop();
				}
			}
		}
		count = count + st.size();
		HashSet<String> hset = new HashSet<>();
		helper(s, "", 0, 0, count, 0, 0, hset);
		System.out.println(hset);
	}

	public static void helper(String s, String ans, int openbracket, int closebracket, int maxdefect, int currdefect,
			int pos, HashSet<String> hset) {
		if (closebracket > openbracket) {
			return;
		}
		if (pos == s.length()) {
			if (openbracket == closebracket && openbracket != 0) {
				hset.add(ans);
			}
			return;
		}
		if (s.charAt(pos) == '(') {
			helper(s, ans + s.charAt(pos), openbracket + 1, closebracket, maxdefect, currdefect, pos + 1, hset);
			if (currdefect < maxdefect) {
				helper(s, ans, openbracket, closebracket, maxdefect, currdefect + 1, pos + 1, hset);
			}
		}
		if (s.charAt(pos) == ')') {
			helper(s, ans + s.charAt(pos), openbracket, closebracket + 1, maxdefect, currdefect, pos + 1, hset);
			if (currdefect < maxdefect) {
				helper(s, ans, openbracket, closebracket, maxdefect, currdefect + 1, pos + 1, hset);
			}
		} else {
			helper(s, ans + s.charAt(pos), openbracket, closebracket, maxdefect, currdefect, pos + 1, hset);
		}
	}

}
