public class Week6CatSeakmeng extends Week6PetSeakmeng{

    private String coatColor;

    public Week6CatSeakmeng(String name, String type, String coatColor) {
        super(name, type);
        this.coatColor = coatColor;
    }

    public String getCoatColor() {
        return this.coatColor;
    }

    public void setCoatColor(String coatColor) {
        this.coatColor = coatColor;
    }

    @Override
    public String toString() {
        return "{" +
        " name='" + getName() + "'" +
        ", Override toString Week6CatSeakmeng type='" + getType() + "'" +
        ", coatColor='" + getCoatColor() + "'" +
        "}";
    }

}
