package com.company;

import java.util.HashMap;
import java.util.LinkedList;

public class FindComputer {
    public enum ComputerType{
        BRAND,
        PRICE,
        CATEGORY,
        SIZE,
        PROCESSER;
        public String toString() {
            switch (this) {
                case BRAND:
                    return "Brand";
                case PRICE:
                    return "Price";
                case CATEGORY:
                    return "Category";
                case SIZE:
                    return "Size";
                case PROCESSER:
                    return "Processer";
                default:
                    return "upspecified";
            }
        }
    }
    public static void main (String args[]){

        Inventory inventory = new Inventory();

        //添加电脑
        HashMap<String,Object> properties = new HashMap<>();
        properties.put("size","16英寸");
        properties.put("CPU","Inter Core7");
        properties.put("type","台式机");

        ComputerSpec eSpec = new ComputerSpec(properties);

        inventory.addComputer("001",5000,eSpec);
        inventory.addComputer("002",5500,eSpec);
        inventory.addComputer("003",6000,eSpec);

        System.out.println("测试仓库产品");
        for(Computer e:inventory.getInventory())
            System.out.println(e.toString());

        System.out.println("单个查询结果：");
        //添加搜索条件
        HashMap<String,Object> searchoneproperty = new HashMap<>();
        searchoneproperty.put("size","15英寸");
        ComputerSpec matchoneeProductSpec = new ComputerSpec(searchoneproperty);
        System.out.println("测试条件："+matchoneeProductSpec.toString());

        //测试match结果
        LinkedList<Computer> matchoneresult =  inventory.search(matchoneeProductSpec);

        if(matchoneresult.size()==0)
            System.out.println("没有找到符合条件的产品！！");
        else{
            System.out.println("成功找到如下产品：");
            for(Computer e:matchoneresult)
                System.out.println(e.toString());
        }

        System.out.println();
        System.out.println("组合查询结果：");
        //添加搜索条件
        HashMap<String,Object> searchproperties = new HashMap<>();
        searchproperties.put("size","16英寸");
        searchproperties.put("CPU","Inter Core");
        ComputerSpec matcheProductSpec = new ComputerSpec(searchproperties);
        System.out.println("测试条件："+matcheProductSpec.toString());

        //测试match结果
        LinkedList<Computer> matchresult =  inventory.search(matcheProductSpec);

        if(matchresult.size()==0)
            System.out.println("没有找到符合条件的产品！！");
        else{
            System.out.println("成功找到如下产品：");
            for(Computer e:matchresult)
                System.out.println(e.toString());
        }

    }

    }

