/*
 * Pedro Luis González Roa
 * A01651517
 * Lab 1
 */

import java.util.Random;
import java.util.Scanner;

public class Race {
    /* Time that every participant will wait so it is easier to see the messages */
    private static int MESSAGE_TIMER = 50;

    private static class Participant implements Runnable {
        /* A race participant. Can be either the Rabbit or the Turtle */
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
        /* Constructor method for the Participant class */
            this.name = name;
            this.distance = distance;
            this.actual = 0;
            this.vel_min = vel_min;
            this.vel_max = vel_max;
            this.rest_min = rest_min;
            this.rest_max = rest_max;
            this.rand = new Random();
        }

        public void run() {
            /* Method to run the thread */
            try {
                /* Calc the deltas of velocity */
                int advanced, rest, dvel = vel_max-vel_min, drest = rest_max-rest_min;
                while (distance >= actual) {
                    advanced = this.rand.nextInt(dvel) + vel_min; // Calc advanced d
                    if(drest > 0){
                        rest = this.rand.nextInt(drest) + rest_min; // Calc time to rest
                    } else { rest = 0; }
                    actual += advanced;
                    if (actual >= distance) {
                        this.talk("I finished!!! Leeets goooo");
                    } else {
                        if (advanced > 100) {
                            this.talk(
                                String.format("I'm fast af booooi (%d)", actual)
                            );
                        } else {
                            this.talk(
                                String.format("I'm too old for this sht (%d)", actual)
                            );
                        }
                        if (rest > 0) {
                            this.talk(
                                String.format("I'm going to take a nap (%d)", rest)
                            );
                        }
                        Thread.sleep(MESSAGE_TIMER + rest*MESSAGE_TIMER);
                    }
                }
            } catch (InterruptedException e) {
                this.talk("Oh maaaan. I did not finish! *Cries in the background*");
            }
        }

        private void talk(String message) {
            System.out.format("%s: %s\n", this.name, message);
        }
    }

    private static void usage () {
        System.out.println("usage: <distance: int>");
        System.out.println("flags:\n--rabbit <vel_min: int> <vel_min: int> <rest_min:int> <rest_max:int>");
        System.out.println("--turtle <vel_min: int> <vel_min: int> <rest_min:int> <rest_max:int>");
    }

    private static void race(Thread t1, Thread t2) throws InterruptedException {
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
            }
        }

        if (t1.isAlive()) {
            t1.interrupt();
            t1.join();
        }

        if (t2.isAlive()) {
            t2.interrupt();
            t2.join();
        }

        System.out.println("\n\n\n");
    }

    public static void main (String args[]) throws InterruptedException {
        int option = 0, race_option = 0, distance=1*1000;
        int rab_vel_min=500, rab_vel_max=1000, rab_rest_min=100, rab_rest_max=200;
        int tur_vel_min=3, tur_vel_max=10, tur_rest_min=0, tur_rest_max=0;
        Scanner scan = new Scanner(System.in);

        do {
            System.out.println("1. Create new Race");
            System.out.println("2. Exit");

            System.out.print("Option: ");
            option = scan.nextInt();

            switch (option) {
                case 1:
                    do {
                        System.out.println("\n\n\n1. Start Race!");
                        System.out.format("2. Edit bunny (%d, %d, %d, %d)\n",
                            rab_vel_min,
                            rab_vel_max,
                            rab_rest_min,
                            rab_rest_max
                        );
                        System.out.format("3. Edit turtle (%d, %d, %d, %d)\n",
                            tur_vel_min,
                            tur_vel_max,
                            tur_rest_min,
                            tur_rest_max
                        );
                        System.out.println("4. Change distance ("+distance+')');
                        System.out.println("5. Exit");
                        System.out.print("Option: ");
                        race_option = scan.nextInt();

                        switch(race_option) {
                            case 1:
                                race (
                                    new Thread(
                                        new Participant(
                                            "rabbit",
                                            distance,
                                            rab_vel_min,
                                            rab_vel_max,
                                            rab_rest_min,
                                            rab_rest_max
                                        )
                                    ),
                                    new Thread(
                                        new Participant(
                                            "turtle",
                                            distance,
                                            tur_vel_min,
                                            tur_vel_max,
                                            tur_rest_min,
                                            tur_rest_max
                                        )
                                    )
                                );
                                break;
                            case 2:
                                System.out.print("VELOCITY=====\n min = ");
                                rab_vel_min = scan.nextInt();
                                System.out.print(" max = ");
                                rab_vel_max = scan.nextInt();

                                System.out.print("REST=========\n min = ");
                                rab_rest_min = scan.nextInt();
                                System.out.print(" max = ");
                                rab_rest_max = scan.nextInt();
                                break;
                            case 3:
                                System.out.print("VELOCITY=====\n min = ");
                                tur_vel_min = scan.nextInt();
                                System.out.print(" max = ");
                                tur_vel_max = scan.nextInt();

                                System.out.print("REST=========\n min = ");
                                tur_rest_min = scan.nextInt();
                                System.out.print(" max = ");
                                tur_rest_max = scan.nextInt();
                                break;
                            case 4:
                                System.out.print("Distance (*1000): ");
                                distance = scan.nextInt()*1000;
                                break;
                            case 5:
                                System.out.println("Race cancelled :c \n\n\n");
                                break;
                            default:
                                System.out.println("Not a valid option!!");
                        }
                    } while (race_option != 1 && race_option != 5);
                break;
                case 2:
                    System.out.println("Au revoir!!");
                break;
                default:
                    System.out.println("Not a valid option!!");
            }
        } while (option != 2);

        System.exit(0);
    }
}
