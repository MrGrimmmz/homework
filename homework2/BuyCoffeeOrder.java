import java.util.HashMap;
import java.util.LinkedList;

public class BuyCoffeeOrder
{
   private LinkedList<Coffee> coffee = new LinkedList<>();
   private int num;
   public BuyCoffeeOrder(int num) {
      this.num = num;
   }

   public void addCoffee(Coffee c){
      coffee.add(c);
   }

   public double Calculate(){
      double totalcost = 0;
      for(Coffee c:coffee)
         totalcost += c.Calculate();
      return totalcost;
   }


   }




