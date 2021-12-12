import java.util.Scanner;

public class T9Spelling {

    public static String[] mappings =  new String[] {
        "2", "22", "222", 
        "3", "33", "333", 
        "4", "44", "444",
        "5", "55", "555",
        "6", "66", "666",
        "7", "77", "777", "7777",
        "8", "88", "888",
        "9", "99", "999", "9999"
    };

    public static String SPACE = "0";
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = Integer.parseInt(sc.nextLine());

        for (int i=0; i<N; i++) {
            String message = sc.nextLine();
            StringBuffer sb = new StringBuffer();
            sb.append(String.format("Case #%d: ", i+1));

            for (int j=0; j<message.length(); j++) {
                char ch = message.charAt(j);
                String mapping;
                if (ch == ' ') {
                    mapping = SPACE;
                } else {
                    mapping = mappings[ch - 'a'];
                }
                if (mapping.charAt(0) == sb.charAt(sb.length() - 1) && j != 0) {
                    sb.append(' ');
                }
                sb.append(mapping);
            }

            System.out.println(sb.toString());
        }

    }

}
