package com.company;

public class Computer {
    public Double price ;
    public String serialnumber ;
    public ComputerSpec computerSpec;

    public String getSerialnumber() {
        return serialnumber;
    }

    public Computer(String serialnumbers,Double price,ComputerSpec computerSpec) {
        this.serialnumber = serialnumbers;
        this.price=price;
        this.computerSpec=computerSpec;
    }

    public void setSerialnumber(String serialnumber) {
        this.serialnumber = serialnumber;
    }

    public Double getPrice() {
        return price;
    }

    public void setPrice(Double price) {
        this.price = price;
    }

    public ComputerSpec getSpec() {
        return computerSpec ;
    }

    @Override
    public String toString() {
        return "Computer{" +
                "serialNumber='" + serialnumber + '\'' +
                ", price=" + price +
                ", computerSpec=" + computerSpec +
                '}';
    }

}
