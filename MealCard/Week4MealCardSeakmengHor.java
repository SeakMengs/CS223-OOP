public class Week4MealCardSeakmengHor {
    private int amount;
    private String owner;

    public Week4MealCardSeakmengHor() {
        this.amount = 100;
        this.owner = "Unassign";
    }

    public Week4MealCardSeakmengHor(int amount, String owner) {
        this.amount = amount;
        this.owner = owner;
    }

    public int getAmount() {
        return this.amount;
    }

    public void setAmount(int amount) {
        this.amount = amount;
    }

    public String getOwner() {
        return this.owner;
    }

    public void setOwner(String owner) {
        this.owner = owner;
    }

    public void addAmount(int add) {
        this.amount += add;
    }

    public void deductAmount(int deduct) {
        this.amount -= deduct;
    }
}