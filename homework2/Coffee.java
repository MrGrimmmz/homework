import java.util.HashMap;
import java.util.LinkedList;

public class Coffee {
    private String name;
    private HashMap<String,String> properities;
    private LinkedList<Ingredient> ingredients;

    public Coffee(String name, HashMap<String, String> properities, LinkedList<Ingredient> ingredients) {
        this.name = name;
        this.properities = properities;
        this.ingredients = ingredients;
    }

    public double Calculate(){
        double totalPrice = ConstantPrices.COFFEE_VOL_PRICE.get(name).get(properities.get("type"));
        totalPrice += ConstantPrices.MILK_PRICE.get(properities.get("milk"));
        for(Ingredient i:ingredients){
            totalPrice += ConstantPrices.Ingredient_PRICE.get(i.getName())*i.getNum();
        }
        return totalPrice;
    }


}
