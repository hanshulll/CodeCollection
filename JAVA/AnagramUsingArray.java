public class AnagramUsingArray {
    public static void main(String[] args) {

        String a = "ab#;^$c";
        String b = "^c#b;a$";

        boolean isAnagram = true;
        int al[] = new int[256];
        int bl[] = new int[256];

        for (int c : a.toCharArray()) {
            int index = (int) c;
            al[index]++;
        }
        for (int c : b.toCharArray()) {
            int index = (int) c;
            bl[index]++;
        }

        for (int i = 0; i < 256; i++) {
            if (al[i] != bl[i]) {
                isAnagram = false;
                break;
            }
        }

        if (isAnagram) {
            System.out.println("Anagram");
        } else {
            System.out.println("Not Anagram");
        }
    }
}