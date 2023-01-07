public class Staff extends Employee {
    private String title;


    public Staff(String name, String adress, int phoneNumber, String email, int officeNumber, int salary, String title) {
        super(name, adress, phoneNumber, email, officeNumber, salary);
        this.title = title;
    }
    

    public String getTitle() {
        return this.title;
    }

    public void setTitle(String title) {
        this.title = title;
    }

    @Override
    public String toString() {
        return "{" +
            " title='" + getTitle() + "'" +
            "}";
    }

}
