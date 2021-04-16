import java.util.Random;

public class Western {
    static void threadMessage(String message) {
        System.out.format("%s: %s%n", Thread.currentThread().getName(), message);
    }

    private static class Cowboy implements Runnable {
        private int accuracy;
        private Thread rival;
        private Random rand;

        public Cowboy(int accuracy) {
            this.accuracy = accuracy;
            this.rand = new Random();
        }

        public void setRival(Thread rival) { this.rival = rival; }

        public void run() {
            try {
                if (rival != null) {
                    while (rival.isAlive()) {
                        if(this.rand.nextInt(100) < accuracy) {
                            threadMessage("One tap ggwp");
                            rival.interrupt();
                            rival.join();
                            break;
                        } else {
                            threadMessage("*Misses*");
                        }
                        threadMessage("Reloading....");
                        Thread.sleep(1000);
                    }
                } else {
                    threadMessage("No rival!");
                }
            } catch (InterruptedException e) {
                threadMessage("My brother will avenge me!! Arggh *Dies*");
            }
        }
    }

    public static void main(String args[]) throws InterruptedException {
        threadMessage("A duel!");
        long startTime = System.currentTimeMillis(), patience = 100 * 1000;
        Cowboy c1 = new Cowboy(5), c2 = new Cowboy(5);
        Thread t1 = new Thread(c1);
        Thread t2 = new Thread(c2);
        c1.setRival(t2);
        c2.setRival(t1);

        t1.start();
        t2.start();

        while (t1.isAlive() && t2.isAlive()) {
            threadMessage("Just kill him already!!");
            t1.join(1000);
            t1.join(1000);
            if (((System.currentTimeMillis() - startTime) > patience)
                    && t1.isAlive() && t2.isAlive()) {
                threadMessage("Tired of waiting! You all die!");
                t1.interrupt();
                t2.interrupt();
                // Shouldn't be long now
                // -- wait indefinitely
                t1.join();
                t2.join();
            }
        }
        threadMessage("Finally!");
    }
}
