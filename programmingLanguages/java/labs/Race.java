/*
 * Pedro Luis González Roa
 * A01651517
 * Lab 1
 */

import java.util.Random;

/*
 * Execute examples:
 * ./Race
 * ./Race 50000
 * ./Race 50000 --rabbit 500 1000 100 200 --turtle 10 20 0 10
 */
public class Race {
    private abstract class Participant implements Runnable {
        private String name;
        private int distance;
        private int actual;
        private int vel_min;
        private int vel_max;
        private int rest_min;
        private int rest_max;
        private Random rand;

        public Participant (
            String name,
            int distance,
            int vel_min,
            int vel_max,
            int rest_min,
            int rest_max
        ) {
            this.name = name;
            this.distance = distance;
            this.actual = 0;
            this.vel_min = vel_min;
            this.vel_max = vel_max;
            this.rest_min = rest_min;
            this.rest_max = rest_max;
            this.rand = Random();
        }

        public void run() {
            try {
                while (distance >= actual) {
                    int advanced = this.rand.nextInt(vel_max-vel_min) + vel_min;
                    int rest = this.rand.nextInt(rest_max-rest_min) + rest_min;
                    if (actual >= distance) {
                        this.talk("I finished!!! Leeets goooo");
                    } else {
                        if (advanced > 100) {
                            this.talk(
                                String.format("I'm fast af booooi (%i)", advanced)
                            );
                        } else {
                            this.talk(
                                String.format("I'm too old for this sht (%i)", advanced)
                            );
                        }
                        Thread.sleep(200 + rest);
                    }
                }
            } catch (InterruptedException e) {
                this.talk("Oh maaaan. I did not finish! *Cries in the background*")
            }
        }

        private void talk (message) { System.out.format("%s: %s\n", this.name, message); }
    }

    private static void usage () {
        System.out.println("usage: <distance: int>");
        System.out.println("flags:\n--rabbit <vel_min: int> <vel_min: int> <rest_min:int> <rest_max:int>");
        System.out.println("--turtle <vel_min: int> <vel_min: int> <rest_min:int> <rest_max:int>");
    }

    public static void main (String args[]) throws InterruptedException {
        int distance = 10000;
        int rab_vel_min=500, rab_vel_max=1000, rab_rest_min=100, rab_rest_max=200;
        int tur_vel_min=3, tur_vel_max=10, tur_rest_min=0, tur_rest_max=0;

        if (args.length > 0) {
            try {
                distance = Int.parseInt(args[0]);
                for(int i = 1; i < args.length; i++) {
                    if (args[i] == "--rabbit") {
                        rab_vel_min = Int.parseInt(args[i+1]);
                        rab_vel_max = Int.parseInt(args[i+2]);
                        rab_rest_min = Int.parseInt(args[i+3]);
                        rab_rest_max = Int.parseInt(args[i+4]);
                        i = i + 4;
                    } else if (args[i] == "--turtle") {
                        tur_vel_min = Int.parseInt(args[i+1]);
                        tur_vel_max = Int.parseInt(args[i+2]);
                        tur_rest_min = Int.parseInt(args[i+3]);
                        tur_rest_max = Int.parseInt(args[i+4]);
                        i = i + 4;
                    } else {
                        usage();
                        System.exit(1);
                    }
                }
            } catch (NumberFormatException|ArrayOutOfBounds e) {
                usage();
                System.exit(2);
            }
        }

        Thread t1 = new Thread(
            new Participant("rabbit", distance, rab_vel_min, rab_vel_max, rab_rest_min, rab_res_max)
        );
        Thread t2 = new Thread(
            new Participant("turtle", distance, tur_vel_min, tur_vel_max, tur_rest_min, tur_res_max)
        );

        System.out.println("On your marks....");
        Thread.sleep(200);
        System.out.println("Get set....");
        Thread.sleep(200);
        System.out.println("GO!!!");
        t1.start();
        t2.start();

        long patience = 120 * 1000, startTime = System.currentTimeMillis();

        while (t1.isAlive() && t2.isAlive()) {
            t1.join(500);
            t2.join(500);

            if ( ((System.currentTimeMillis() - startTime) > patience) &&
                    t1.isAlive() && t2.isAlive()) {
                System.out.println("Race is taking too much time... Ending...");
                break;
                t2.interrupt();
                t2.join();
            }
        }
    }
    if (t1.isAlive()) {
        t1.interrupt();
        t1.join()
    }
}
