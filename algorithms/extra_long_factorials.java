import java.math.BigInteger;


class Result {
    
    private static BigInteger factorial(BigInteger n){
        BigInteger fact = BigInteger.ONE; 
        for(long i = 2; i <= n.longValueExact(); i++){ 
            fact = fact.multiply(BigInteger.valueOf(i));  
        }
        return fact; 
    }

    /*
     * Complete the 'extraLongFactorials' function below.
     *
     * The function accepts INTEGER n as parameter.
     */

    public static void extraLongFactorials(int n) {
        System.out.println(factorial(BigInteger.valueOf(n)).toString());
    }
}