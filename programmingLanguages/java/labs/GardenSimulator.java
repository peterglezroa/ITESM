/*
 * Pedro Luis González Roa
 * A01651517
 * Lab 2
 */
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Random;
import java.util.Scanner;

public class GardenSimulator {
    // Declared as a global const so i can use it in all classes
    public static Random RANDOM = new Random();
    // Probability of the person exiting the garden. If not it does another action.
    public static int PROB = 10;
    // How much time between actions.
    public static int WAIT = 1000;

    private static class Door implements Runnable {
        private Garden garden;
        private String name;
        private int entered, exited;

        public Door(Garden garden, String name) {
            this.garden = garden;
            this.name = name;
            this.entered = 0;
            this.exited = 0;
        }

        public synchronized void enter(String pname, Thread person) {
            // Synchronize method to avoid memory leaks
            System.out.format("%s entered through gate %s.\n", pname, name);
            entered++;
            garden.enter(person);
        }
        public synchronized void exit(String pname, Thread person) {
            // Synchronize method to avoid memory leaks
            System.out.format("%s exited through gate %s.\n", pname, name);
            exited++;
            garden.exit(person);
        }

        public void run() {
            try {
                while(true) {
                    // Just keep running until de Garden tells you to stop
                    Thread.currentThread().sleep(1);
                }
            } catch (InterruptedException e) {
                System.out.format("%s: %d entered, %d exited\n", name, entered, exited);
            }
        }
    }

    private static class Garden implements Runnable {
        private int entered, exited;
        private LinkedList<Thread> people;
        private long open_duration; // How much time it will be open.
        private Door door1, door2;
        // Is it still open? This helps so that no one can enter when they are
        // closing.
        public boolean isOpen = true;

        public Garden(long open_duration) {
            this.open_duration = open_duration;
            this.entered = 0;
            this.exited = 0;
            this.people = new LinkedList<Thread>();
            this.isOpen = false;
        }

        public void setDoor1 (Door door) { this.door1 = door; }
        public void setDoor2 (Door door) { this.door2 = door; }

        public synchronized void enter(Thread person) {
            this.people.add(person);
            this.entered++;
        }

        public synchronized void exit(Thread person) {
            this.people.remove(person);
            this.exited++;
        }

        public Door randomDoor() {
            switch(RANDOM.nextInt(2)) {
                case 0:
                    return door1;
                case 1:
                    return door2;
            }
            return null;
        }

        public void run() {
            try {
                this.isOpen = true;
                Thread dt1 = new Thread(this.door1), dt2 = new Thread(this.door2);
                long startTime = System.currentTimeMillis();
                // Start both doors threads
                dt1.start();
                dt2.start();
                // Keep running until its closing time
                while (System.currentTimeMillis() - startTime < open_duration) {
                    Thread.currentThread().sleep(50);
                }
                this.isOpen = false; // Put up closed sign
                // Keep everyone out.
                System.out.format("Kicking %d people out!\n", people.size());
                if (!people.isEmpty()) {
                    Thread aux;
                    while(!people.isEmpty()) {
                        // Avoiding iterators and Concurrent exceptions
                        aux = people.remove();
                        aux.interrupt();
                        aux.join();
                    }
                }
                // Interrupt Door 1
                if (dt1.isAlive()) {
                    dt1.interrupt();
                    dt1.join();
                }
                // Interrupt Door 2
                if (dt2.isAlive()) {
                    dt2.interrupt();
                    dt2.join();
                }
            } catch (InterruptedException e) {
                System.out.println("Got interrupted!\n");
            }
            System.out.format("Garden: %d entered, %d exited.\n", entered, exited);
        }
    }

    private static class Person implements Runnable {
        private final String[] ACTIONS = {
            "playing football.",
            "drinking wine.",
            "having a picnic.",
            "taking photos.",
            "creeping on people.",
            "walking around.",
            "sleeping.",
        };
        private String name;
        private Garden garden;

        public Person(Garden garden, String name) {
            this.garden = garden;
            this.name = name;
        }

        public void say(String message) {
            System.out.format("%s: %s\n", this.name, message);
        }

        public void exit() {
            // method to exit. Used when kicked or leaving by choice.
            say("Well, its time to go...");
            garden.randomDoor().exit(name, Thread.currentThread());
        }

        public String getName() { return name; }

        public void run() {
            try {
                while (garden.isOpen) {
                    int aux = RANDOM.nextInt(100);
                    if (aux <= PROB) {
                        this.exit();
                        break;
                    }
                    say(ACTIONS[aux%7]);
                    Thread.sleep(WAIT);
                }
            } catch (InterruptedException e) {
                this.exit();
            }
        }
    }


    public static void main(String args[]) throws InterruptedException {
        int patience, people;

        Scanner scan = new Scanner(System.in);
        System.out.println("Escribe cuántos segs estará abierto el jardín: ");
        patience = scan.nextInt();

        System.out.println("Escribe cuantas personas irán al parque.");
        people = scan.nextInt();

        Garden garden = new Garden(patience*1000);
        Door west = new Door(garden, "West"), east = new Door(garden, "East");

        Thread gardenThread = new Thread(garden);
        garden.setDoor1(west);
        garden.setDoor2(east);

        gardenThread.start();

        Thread.sleep(WAIT);
        Person person;
        Thread taux;
        for (int i = 0; i < people && garden.isOpen ; i++) {
            person = new Person(garden, String.format("Persona %d", i));
            taux = new Thread(person);
            taux.start();
            garden.randomDoor().enter(person.getName(), taux);
            Thread.sleep(RANDOM.nextInt(WAIT));
        }

        gardenThread.join();
    }
}
