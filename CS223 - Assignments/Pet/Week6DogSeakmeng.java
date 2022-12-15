public class Week6DogSeakmeng extends Week6PetSeakmeng {
    
    public Week6DogSeakmeng(String name, String type) {
        super(name, type);
    }

    @Override
    public String toString() {
        return "{" +
        " name='" + getName() + "'" +
        ", Override toString Week6DogSeakmeng type='" + getType() + "'" +
        "}";
    }
}
