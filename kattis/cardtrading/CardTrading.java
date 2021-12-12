import java.util.Arrays;
import java.util.Scanner;

public class CardTrading {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int T = sc.nextInt();
        int K = sc.nextInt();

        int[] count = new int[T];

        // Cost of purchasing 2 of the cards
        long[] cost = new long[T];

        long profit = 0;

        // 'Sell' all the cards, and treat their selling price as future "buying" price (opportunity cost).
        for (int i=0; i<N; i++) {
            count[sc.nextInt() - 1]++;
        }

        // Calculate total cost of buying/buying back each card
        for (int i=0; i<T; i++) {
            long buyPrice = sc.nextLong();
            long sellPrice = sc.nextLong();
            int buyBackQuantity = count[i];

            profit += count[i] * sellPrice;
            cost[i] = buyBackQuantity * sellPrice + (2-buyBackQuantity) * buyPrice;
        }

        Arrays.sort(cost);
        
        // Buy/ buy back the cheapest K cards
        for (int i=0; i<K; i++) {
            profit -= cost[i];
        }

        System.out.println(profit);
    }
}
