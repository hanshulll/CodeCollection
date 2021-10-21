//Reverse the given String

class StringReverse {

	public static String reverseString(String inputString) {
		StringBuffer stringValue = new StringBuffer();

		for (int i = inputString.length() - 1; i >= 0; i--) {
			stringValue.append(inputString.charAt(i));
		}

		return stringValue.toString();

	}

	public static void main(String[] args) {
		String reverseString = reverseString("Stringreverse");
		System.out.println("Reversed String is:" + reverseString);
	}

}
