import java.util.LinkedList;
import java.util.Scanner;

public class Coconut {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int s = sc.nextInt();
        int n = sc.nextInt();

        LinkedList<Hand> hands = new LinkedList<>();

        for (int i=0; i<n; i++) {
            hands.addLast(new Hand(i+1, Hand.FOLDED));
        }

        while (hands.size() > 1) {
            for (int i = 0; i < s-1; i++) {
                hands.addLast(hands.pollFirst());
            }

            Hand last = hands.pollFirst();

            if (last.state == Hand.FOLDED) {
                hands.addFirst(new Hand(last.id, Hand.FIST));
                hands.addFirst(new Hand(last.id, Hand.FIST));
            } else if (last.state == Hand.FIST) {
                hands.addLast(new Hand(last.id, Hand.PALM));
            }
        }

        System.out.println(hands.get(0).id);
    }

    private static class Hand {
        static int FOLDED = 0;
        static int FIST = 1;
        static int PALM = 2;
        
        int id;
        int state;

        public Hand(int id, int state) {
            this.id = id;
            this.state = state;
        }
    }
}

