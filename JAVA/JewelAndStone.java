import java.util.HashSet;
import java.util.Set;

class JewelAndStone {
    public static int numJewelsInStones(String jewels, String stones) {
//        return hashTableApproach(jewels, stones);
//        return multipleLoopApproach(jewels, stones);
        return indexOfApproach(jewels, stones);
    }

    public static int indexOfApproach(String jewels, String stones) {
        int counter = 0;
        for(char stoneChar: stones.toCharArray()) {
            if(jewels.indexOf(stoneChar) != -1) {
                counter++;
            }
        }

        return counter;
    }

    public static int multipleLoopApproach(String jewels, String stones) {
        int counter = 0;
        char[] jewelInChar = jewels.toCharArray();
        char[] stoneInChar = stones.toCharArray();
        for (char jewelChar : jewelInChar) {
            for (char stoneChar : stoneInChar) {
                if(stoneChar == jewelChar) {
                    counter++;
                }
            }
        }

        return counter;
    }

    public static int hashTableApproach(String jewels, String stones) {
        int counter = 0;
        Set<Character> set = new HashSet<>();
        for(int i = 0; i < jewels.length(); i++) {
            set.add(jewels.charAt(i));
        }

        for(int i = 0; i < stones.length(); i++) {
            if(set.contains(stones.charAt(i))) {
                counter++;
            }
        }

        return counter;
    }

    public static void main(String[] args) {
        String jewels = "aA";
        String stones = "aAAbbbb";
        System.out.println("result => " + JewelAndStone.numJewelsInStones(jewels, stones));
    }
}