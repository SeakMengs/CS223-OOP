public class Faculty extends Employee {
    private int officeHour;
    private String rank;


    public Faculty(String name, String address, int phoneNumber, String email, int officeNumber, int salary, int officeHour, String rank) {
        super(name, address, phoneNumber, email, officeNumber, salary);
        this.officeHour = officeHour;
        this.rank = rank;
    }
    

    public int getOfficeHour() {
        return this.officeHour;
    }

    public void setOfficeHour(int officeHour) {
        this.officeHour = officeHour;
    }

    public String getRank() {
        return this.rank;
    }

    public void setRank(String rank) {
        this.rank = rank;
    }

    @Override
    public String toString() {
        return "{" +
            " officeHour='" + getOfficeHour() + "'" +
            ", rank='" + getRank() + "'" +
            "}";
    }

}
