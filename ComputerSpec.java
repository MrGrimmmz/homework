package com.company;

import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;

public class ComputerSpec {

    private HashMap<String, Object> properties;

    public ComputerSpec(HashMap<String, Object> propertiess){
        if(propertiess == null){
            this.properties=new HashMap<String, Object> (propertiess);
        }else{

            this.properties = new HashMap<String, Object> (propertiess);
        }

    }
    public Object getProperty(String s){
        return properties.get(s);
    }

    public HashMap<String,Object> getProperties(){

        return properties;
    }
    public boolean matches(ComputerSpec computerSpec){
        for(Iterator i=computerSpec.getProperties().keySet().iterator();i.hasNext();){

            String computerSpecs =(String) i.next();
            if(!properties.get(computerSpecs).equals(
                    computerSpec.getProperty(computerSpecs))){
                return false;
            }
        }
        return true;
    }
}
