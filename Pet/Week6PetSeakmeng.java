public class Week6PetSeakmeng {
    private String name;
    private String type;

    public Week6PetSeakmeng() {
    }

    public Week6PetSeakmeng(String name, String type) {
        this.name = name;
        this.type = type;
    }

    public String getName() {
        return this.name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getType() {
        return this.type;
    }

    public void setType(String type) {
        this.type = type;
    }


    @Override
    public String toString() {
        return "{" +
            " name='" + getName() + "'" +
            ", type='" + getType() + "'" +
            "}";
    }
    
}
