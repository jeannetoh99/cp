import java.util.Scanner;

public class PeaSoup {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        for (int i=0; i<n; i++) {
            int k = Integer.parseInt(sc.nextLine());
            boolean hasPeaSoup = false;
            boolean hasPancakes = false;
            String restaurant = sc.nextLine();
            for (int j=0; j<k; j++) {
                String item = sc.nextLine();
                if (item.equals("pea soup")) hasPeaSoup = true;
                if (item.equals("pancakes")) hasPancakes = true;
                if (hasPeaSoup && hasPancakes) {
                    System.out.println(restaurant);
                    return;
                }
            }
        }
        System.out.println("Anywhere is fine I guess");
    }
}