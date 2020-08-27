import org.junit.Test;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;

public class TestStarbuzzCoffee {
 
	public static void main(String args[]) {
		BuyCoffeeOrder order = new BuyCoffeeOrder(1);
		Double total=0.0;
		String coffeeName="";
		String ingredientname="";
		String milkname="";
		String cupname="";
		String tem="";
		ConstantPrices constantPrices=new ConstantPrices();

		System.out.println("请选择您要购买的咖啡：1是摩卡，2是卡布奇诺，3是拿铁");
		Scanner input=new Scanner(System.in);
		int coffeetype = input.nextInt();
		switch (coffeetype) {
			case 1 :
				coffeeName="摩卡";
			case 2:
				coffeeName="卡布奇诺";
			case 3:
				coffeeName="拿铁";
			default:
		}

		Scanner in = new Scanner(System.in);
		System.out.println("请选择咖啡杯型，1表示中杯，2表示大杯，3表示超大杯");
		int cupSize = in.nextInt();
		switch (cupSize) {
			case 1 :
				cupname="中杯";
			case 2:
				cupname="大杯";
			case 3:
				cupname="超大杯";
			default:
		}


		System.out.println("请选择温度，1表示热，2表示冰，3表示去冰");
		int temp = in.nextInt();
		switch (coffeetype) {
			case 1 :
				tem="热";
			case 2:
				tem="冰";
			case 3:
				tem="去冰";
			default:
		}
		System.out.println("请选择牛奶，1表示全部牛奶，2表示燕麦奶，3表示去脱脂牛奶，4表示豆奶");
		int temp1 = in.nextInt();
		switch (temp1) {
			case 1 :
				milkname="全部牛奶";
			case 2:
				milkname="燕麦奶";
			case 3:
				milkname="脱脂牛奶";
			case 4:
				milkname="豆奶";
			default:
		}

		System.out.println("请选择您要的配料类型：1是摩卡淋酱，2是焦糖风味酱，3是香草糖浆，4是榛果糖浆，5是焦糖糖浆");
		Scanner input1=new Scanner(System.in);
		int ingretype = input1.nextInt();
		switch (ingretype) {
			case 1 :
				ingredientname="摩卡淋酱";
			case 2:
				ingredientname="焦糖风味酱";
			case 3:
				ingredientname="香草糖浆";
			case 4:
				ingredientname="榛果糖浆";
			case 5:
				ingredientname="焦糖糖浆";
			default:
		}

		HashMap<String, String> pro = new HashMap<>();
		Double totalPrice=0.0;
		pro.put("type",cupname);
		pro.put("milk","燕麦奶");
		LinkedList<Ingredient> ingredients = new LinkedList<>();
		ingredients.add(new Ingredient(1,ingredientname));
		order.addCoffee(new Coffee(coffeeName,pro,ingredients));
		totalPrice=order.Calculate();
		System.out.println("您购买的咖啡:"+cupname+tem+ingredientname+coffeeName+"总价为："+totalPrice);
	}

	@Test
	public void testMoka(){
		BuyCoffeeOrder order = new BuyCoffeeOrder(1);
		HashMap<String, String> pro = new HashMap<>();
		pro.put("type","中杯");
		pro.put("milk","燕麦奶");

		LinkedList<Ingredient> ingredients = new LinkedList<>();
		ingredients.add(new Ingredient(1,"摩卡淋酱"));
		order.addCoffee(new Coffee("摩卡",pro,ingredients));

		System.out.println(order.Calculate());
	}



}
