
import java.util.*;

public class Generator {


    //private SubSQL subSQLleft;
    //private SubSQL subSQLright;
    private List<Boolean> operatorNOT = new ArrayList<>();//操作符是否加上not
    private Connector connector;//连接符
    private String subSQLleftstring;
    private String subSQLrightstring;


    public String getSubSQLleftstring() {
        return subSQLleftstring;
    }

    public void setSubSQLleftstring(String subSQLleftstring) {
        this.subSQLleftstring = subSQLleftstring;
    }

    public String getSubSQLrightstring() {
        return subSQLrightstring;
    }

    public void setSubSQLrightstring(String subSQLrightstring) {
        this.subSQLrightstring = subSQLrightstring;
    }




    public Generator(String subSQLleftstrings,String subSQLrightstrings,Connector connectors){
        this.subSQLleftstring=subSQLleftstrings;
        this.subSQLrightstring=subSQLrightstrings;
        this.connector=connectors;

    }

    public Connector getConnector() {
        return connector;
    }

    public void setConnector(Connector connector) {
        this.connector = connector;
    }


    @Override
    public String toString() {
        return super.toString();
    }


    public void putNot(boolean not) {
        operatorNOT.add(not);
    }

    public String generateSQL() {

        String sleft="( "+this.subSQLleftstring+" )";
        String sright="( "+this.subSQLrightstring+" )";

        String sql = sleft+ connector.getSql() + sright;
        return sql;
    }
}
