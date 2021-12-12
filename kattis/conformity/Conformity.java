import java.util.Scanner;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.Collections;

public class Conformity {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        HashMap<ArrayList<Integer>, Integer> combinationsMap = new HashMap<>();

        for (int i = 0; i < n; i++) {
            ArrayList<Integer> combi = new ArrayList<>();
            for (int j = 0; j < 5; j++) {
                combi.add(sc.nextInt());
            }
            Collections.sort(combi);
            combinationsMap.put(combi, combinationsMap.getOrDefault(combi, 0) + 1);
        }

        int max = 0;
        int count = 0;
        for (int size : combinationsMap.values()) {
            if (max == size) count++;
            if (size > max) {
                max = size;
                count = 1;
            }
        }

        System.out.println(max * count);

        sc.close();

    }
}

// class Combination {

//     private int[] combi;

//     public Combination(int[] combi) {
//         this.combi = combi;
//     }

//     @Override
//     public boolean equals(Object other) {
//         if (!(other instanceof Combination)) return false;
//         Combination o = (Combination) other;

//         for (int i = 0; i < 5; i++) {
//             if (this.combi[i] != o.combi[i]) return false;
//         }

//         return true;
//     }

//     @Override
//     public int hashCode() {
//         int product = Arrays.stream(combi).reduce(1, (a, b) -> a * b);
//         return product;
//     }

// }