import java.util.Scanner;

public class Week4MainSeakmengHor {
    private Week4MealCardSeakmengHor bal;
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        Week4MainSeakmengHor meal = new Week4MainSeakmengHor();
        meal.start();
        scanner.close();
    }

    public Week4MainSeakmengHor() {
        this.bal = new Week4MealCardSeakmengHor();
    }

    public void start() {
        description();
        initBalance();
        int option;
        do {
            System.out.println("\nPlease select the following options:");
            System.out.println("1. Top up");
            System.out.println("2. Buy food");
            System.out.println("0. Exit");
            System.out.print("Please input your option: ");
            option = scanner.nextInt();
            if (option == 1) {
                topUp();
            } else if (option == 2) {
                buyFood();
            } else if (option != 0) {
                System.out.println("Error input! The program will start again");
            }
        } while (option != 0);
        System.out.println("\nThank you for using the program!");
    }

    public void description() {
        System.out.println("Welcome to Seakmeng's Meal Card Program!");
        System.out.println("This program allows you to created a meal card for once.");
        System.out.println("Later, you can top up or buy food as many times as you want.\n");
    }

    public void initBalance() {
        System.out.print("Please input the initialize balance (input 0 to keep default): ");
        int init = scanner.nextInt();

        if (init != 0) {
            System.out.print("Enter deposit amount: ");
            int depoAmount = scanner.nextInt();
            System.out.print("Enter your name: ");
            String ownerName = scanner.next();
            // Reconstruct
            this.bal = new Week4MealCardSeakmengHor(depoAmount, ownerName);
            displayBalance();
        } else if (init == 0) {
            displayBalance();
        }
    }

    public void displayBalance() {
        if (bal.getOwner() == "Unassign") {
            System.out.println("The current balance of your meal card is: $" + bal.getAmount());
        } else {
            System.out.println("The current balance of " + bal.getOwner() + "'s meal card is: $" + bal.getAmount());

        }
    }

    public void topUp() {
        System.out.print("\nPlease input the point to top up: ");
        int topAmount = scanner.nextInt();
        bal.addAmount(topAmount);
        System.out.println("Your have topped up: $" + topAmount);
        displayBalance();
    }

    public void buyFood() {
        System.out.print("\nPlease input the point of the food: ");
        int point = scanner.nextInt();
        if (point > bal.getAmount()) {
            System.out.println("Insufficient balance!");
            System.out.println("The current balance of your meal card is: $" + bal.getAmount());
        } else {
            System.out.println("Food has been ordered!");
            bal.deductAmount(point);
            System.out.println("The current balance of your meal card is: $" + bal.getAmount());
        }
    }
}
