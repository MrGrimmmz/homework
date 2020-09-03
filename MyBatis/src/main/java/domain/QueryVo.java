package domain;

import java.io.Serializable;

public class QueryVo implements Serializable {
    private String username;
    private String address;
    public String getAddress() {
        return address;
    }
    public void setAddress(String address) {
        this.address = address;
    }
    public String getname() {
        return username;
    }
    public void setName(String username) {
        this.username = username;
    }

}
