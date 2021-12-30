import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();
        BigDecimal aa = new BigDecimal(a);
        BigDecimal bb = new BigDecimal(b);
        BigDecimal cc = new BigDecimal(c);

        BigDecimal res = aa.multiply(bb.divide(cc, 18, RoundingMode.HALF_EVEN));

        System.out.println(res);
        sc.close();
    }
}