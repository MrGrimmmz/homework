package com.company;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

public class Inventory {
    public LinkedList<Computer> inventory=new LinkedList<>();
    public LinkedList<Computer> getInventory() {
        return inventory;
    }
    public void addComputer(String serialnumber, double price, ComputerSpec computerSpec) {

        Computer computer = new Computer(serialnumber, price, computerSpec);
        inventory.add(computer);

    }

    public Computer get(String serialnumber) {
        for(Iterator i=inventory.iterator();i.hasNext();){
            Computer eProduct = (Computer)i.next();
            if(eProduct.getSerialnumber().equals(serialnumber))
                return eProduct;
        }
        return null;
    }
//SRP
    public LinkedList<Computer> search(ComputerSpec computerSpec) {
        LinkedList<Computer> matchingcomputers = new LinkedList<>();
        for (Iterator i = inventory.iterator(); i.hasNext(); ) {
            Computer computer = (Computer) i.next();
            if (computer.getSpec().matches(computerSpec)) {
                matchingcomputers.add(computer);
            }
        }
        return matchingcomputers;
    }

}
