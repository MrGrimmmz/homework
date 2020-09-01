

import com.sun.org.apache.xpath.internal.operations.Or;
import org.junit.Test;
import java.util.ArrayList;
import java.util.List;

import static org.junit.Assert.assertEquals;

public class GenerateSQLTest {



    @Test
    public void testAST() {
        SubSQL s1 =new ComparisonSQL("companyName", ComparisionOperator.EQUAL, " 'HTSC'");
        SubSQL s2= new ComparisonSQL("age", ComparisionOperator.LESS_THAN, "30");
        SubSQL s3= new ComparisonSQL("sex", ComparisionOperator.EQUAL, " 'MALE'");
        assertEquals("select * from customers where ( companyName =  'HTSC' ) or ( ( age < 30 ) and ( sex =  'MALE' ) )",
                getAST1(new SubSQL[]{s1,s2,s3}));
    }

//    private String getComparisionSQL(String column_name, String operator, String value) {
//        Generator generator = new Generator();
//        SubSQL subSQL = new ComparisonSQL(column_name, operator, value);
//
//        generator.putNot(false);
//        return generator.generateSQL();
//    }





    public String getAST1(SubSQL[] subSQLs) {
        String finalstr = "select * from customers where ";
        finalstr = finalstr + new Generator(
                subSQLs[0].generateSubSQL(false),
                new Generator(
                        subSQLs[1].generateSubSQL(false),
                        subSQLs[2].generateSubSQL(false),
                        new ANDConnector()
                ).generateSQL(),
                new ORConnector()).generateSQL();
        return finalstr;
    }






}

