import java.util.Arrays;
import java.util.Scanner;

public class BestRelayTeam {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        Runner[] runnersSortByFirst = new Runner[n];
        Runner[] runnersSortBySecond  = new Runner[n];
        
        for (int i=0; i<n; i++) {
            Runner runner = new Runner(sc.next(), sc.nextDouble(), sc.nextDouble());
            runnersSortByFirst[i] = runner;
            runnersSortBySecond[i] = runner;
        }

        Arrays.sort(runnersSortByFirst, (a, b) -> (int) ((a.first - b.first)*1000));
        Arrays.sort(runnersSortBySecond, (a, b) -> (int) ((a.second - b.second)*1000));

        double minTime = Double.MAX_VALUE;
        Runner[] minRunners = new Runner[4];

        for (int i=0; i<4; i++) {
            Runner[] runners = new Runner[4];
            Runner first = runnersSortByFirst[i];
            runners[0] = first;
            int j = 1;
            int k = 0;
            double time = first.first;
            while (j < 4) {
                if (runnersSortBySecond[k] != first) {
                    runners[j] = runnersSortBySecond[k];
                    time += runnersSortBySecond[k].second;
                    j++;
                }
                k++;
            }

            if (time < minTime) {
                minTime = time;
                minRunners = runners;
            }
        }

        System.out.printf("%.9f\n", minTime);
        for (int i=0; i<4; i++) {
            System.out.println(minRunners[i].name);
        }

    }

    static class Runner {
        String name;
        double first;
        double second;
    
        public Runner(String name, double first, double second) {
            this.name = name;
            this.first = first;
            this.second = second;
        }
    }
    
}