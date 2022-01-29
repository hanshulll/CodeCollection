The strengths of the four shinobi is given and you need to write a program such that finale have tough shinobi's to fight,
like after the two matches in the final the strengths of the shinobi should be greater so that fight is a justice  !

The first shinobi can only fight with second shinobi and the third shinobi can only fight with the fourth, first can't fight with third or fourth and so on.

ex : 4 3 2 1   First shinobi who has strength 4 can only fight with second shinobi who has strength 3 and 3rd with only fourth.


import java.io.*;
import java.util.*;

class ShinobiFight {

    // Function which is used to find whether a match is
    // valid or poor

    private static void theFinale(int s1, int s2, int s3, int s4) {

        // Finding the the shinobi who will loose in the

        // match 1 and 2

        int minOfM1 = Math.min(s1, s2);

        int minOfM2 = Math.min(s3, s4);

        // Finding the shinobi who will win in match1 and 2

        int maxOfM1 = Math.max(s1, s2);

        int maxOfM2 = Math.max(s3, s4);

        // If shinobi who won in match1 can get defeated by

        // shinobi who lost in match2 and vice versa print

        // Poor Match

        if (maxOfM1 < minOfM2 || maxOfM2 < minOfM1) {

            System.out.println("Poor Match");
        }

        else {

            System.out.println("Valid Match !");
        }
    }
}
