public class Week6CatSeakmeng extends Week6PetSeakmeng{

    public Week6CatSeakmeng(String name, String type) {
        super(name, type);
    }

    @Override
    public String toString() {
        return "{" +
        " name='" + getName() + "'" +
        ", Override toString Week6CatSeakmeng type='" + getType() + "'" +
        "}";
    }
}
