import java.util.Scanner;

public class VigenereCipher {

	public static void main(String[] args) {
//		System.out.println(encrypt("THE BOY HAS THE TOY!", "VIG"));
//		System.out.println(decrypt("OPK WWE CIY OPK OWE!", "VIG"));

		System.out.println("This Vignère Cipher only uses capital letters.\n");
		while (true) {
			System.out.println("(1) Encrypt a message");
			System.out.println("(2) Decrypt a cipher");
			System.out.println("(3) Exit program");
			System.out.print("Input: ");
			@SuppressWarnings("resource")
			Scanner sc = new Scanner(System.in);
			int choice = sc.nextInt();
			sc.nextLine();
			if (choice == 1) {
				System.out.print("Message to encrypt: ");
				String m = sc.nextLine();
				System.out.print("Key: ");
				String k = sc.nextLine();
				System.out.println("Cipher: " + encrypt(m, k) + "\n");
			} else if (choice == 2) {
				System.out.print("Cihper to decrypt: ");
				String c = sc.nextLine();
				System.out.print("Key: ");
				String k = sc.nextLine();
				System.out.println("Message: " + decrypt(c, k) + "\n");
			} else {
				sc.close();
				break;
			}
		}
	}

	// just does upper case letters [65, 90]
	public static String encrypt(String m, String k) {
		String c = "";
		int keyLength = k.length();
		int keyCounter = 0; // used in case character other than upper case
		for (int i = 0; i < m.length(); i++) {
			char mChar = m.charAt(i);
			if (mChar >= 65 && mChar <= 90) {
				c += (char) ((mChar + (k.charAt(keyCounter % keyLength))) % 26 + 65);
				keyCounter++;
			} else { // character other than upper case
				c += mChar;
			}
		}
		return c;
	}

	public static String decrypt(String c, String k) {
		String m = "";
		int keyLength = k.length();
		int keyCounter = 0;
		for (int i = 0; i < c.length(); i++) {
			char cChar = c.charAt(i);
			if (cChar >= 65 && cChar <= 90) {
				m += (char) ((26 + cChar - (k.charAt(keyCounter % keyLength))) % 26 + 65);
				keyCounter++;
			} else {
				m += cChar;
			}
		}
		return m;
	}
}
