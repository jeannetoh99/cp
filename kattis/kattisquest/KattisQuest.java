import java.util.Scanner;
import java.util.TreeSet;

public class KattisQuest {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        TreeSet<Quest> quests = new TreeSet<>();

        int n = sc.nextInt();
        int totalQuests = 0;

        for (int i = 0; i < n; i++) {

            String command = sc.next();
            if (command.equals("add")) {

                long e = sc.nextLong();
                long g = sc.nextLong();

                quests.add(new Quest(totalQuests++, c, e));

            } else if (command.equals("query")) {

                long x = sc.nextLong();
                long gold = 0;

                while (x > 0) {
                    Quest q = quests.floor(new Quest(totalQuests, Long.MAX_VALUE, x));
                    if (q == null) {
                        break;
                    } else {
                        quests.remove(q);
                        x -= q.energy;
                        gold += q.cost;
                    }
                }
                System.out.println(gold);
            }
        }

    }
}

class Quest implements Comparable<Quest> {

    int id;
    long cost;
    long energy;

    public Quest(int id, long cost, long energy) {

        this.id = id;
        this.cost = cost;
        this.energy = energy;

    }


    public int compareTo(Quest other) {

        if (this.energy != other.energy) {
            if (this.energy < other.energy) {
                return -1;
            } else {
                return 1;
            }
        } else if (this.cost != other.cost) {
            if (this.cost < other.cost) {
                return -1;
            } else {
                return 1;
            }
        } else {
            return (int) this.id - other.id;
        }

    }

}