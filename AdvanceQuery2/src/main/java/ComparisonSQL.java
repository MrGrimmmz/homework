
public class ComparisonSQL implements SubSQL {
    private String leftObject;
    private String rightObject;
    private String operator;

    public ComparisonSQL(String leftObject,String operator, String rightObject) {
        this.leftObject = leftObject;
        this.operator = operator;
        this.rightObject = rightObject;
    }



    @Override
    public String generateSubSQL(boolean not) {

        String finalstring;
        finalstring=leftObject+" "+operator+" "+rightObject;
        return finalstring;
    }
}
