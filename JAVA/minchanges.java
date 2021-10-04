import java.util.* ;

public class minchanges{

public static int[][] minChanges(String str) {
    int n = str.length();
    int[][] dp = new int[n][n];
    for (int gap = 1; gap < n; gap++) {
        for (int i = 0, j = gap; j < n; i++, j++) {
            if (gap == 1)
                dp[i][j] = str.charAt(i) == str.charAt(j) ? 0 : 1;
            else
                dp[i][j] = str.charAt(i) != str.charAt(j) ? dp[i + 1][j - 1] + 1 : dp[i + 1][j - 1];
        }
    }
    return dp;
}

public static int palindromePartition_(String str, int k, int si, int[][] dp, int[][] minChange) {
    if (str.length() - si <= k) {
        return dp[si][k] = (str.length() - si == k) ? 0 : (int) 1e9;
    }

    if (k == 1)
        return dp[si][k] = minChange[si][str.length() - 1];
    if (dp[si][k] != -1)
        return dp[si][k];

    int minAns = (int) 1e9;
    for (int i = si; i < str.length() - 1; i++) {
        int minChangesInMySet = minChange[si][i];
        int minChangesInRecSet = palindromePartition_(str, k - 1, i + 1, dp, minChange);
        if (minChangesInRecSet != (int) 1e9)
            minAns = Math.min(minAns, minChangesInRecSet + minChangesInMySet);
    }

    return dp[si][k] = minAns;
}

public static int palindromePartition(String str, int k) {
    int[][] minChangeDP = minChanges(str);
    int[][] dp = new int[str.length()][k + 1];
    for (int[] d : dp)
        Arrays.fill(d, -1);

    return palindromePartition_(str, k, 0, dp, minChangeDP);
}

public static void main(String[] args){
    Scanner scn=new Scanner(System.in);
    String str=scn.nextLine();
    int k=scn.nextInt();

    System.out.print(palindromePartition(str,k));
}
    
}
