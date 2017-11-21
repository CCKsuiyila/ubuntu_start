public class homework_26{
    public static void main(String[] args){
        char[] one = new char[15];
        char[] two = new char[15];
        char operation;
        int one_length=0;
        int two_length=0;
        int result =0;

        int count = 0;

        for(;args[0].charAt(count)!=' ';++one_length,++count){
            one[one_length]=args[0].charAt(count);
        }
        String s_one = new String(one);

        for(;args[0].charAt(count)==' ';++count){}
        operation = args[0].charAt(count);
        ++count;

        for(;args[0].charAt(count)==' ';++count){}
        for(;count<args[0].length()-1;++two_length,++count){
            two[two_length]=args[0].charAt(count);
        }
        String s_two = new String(two);
        
        switch(operation){
            case '+': result = Integer.parseInt(s_one) + Integer.parseInt(s_two); break;
            case '-': result = Integer.parseInt(s_one) - Integer.parseInt(s_two); break;
            case '.': result = Integer.parseInt(s_one) * Integer.parseInt(s_two); break;
            case '/': result = Integer.parseInt(s_one) / Integer.parseInt(s_two); break;
            
        }

        System.out.println("the result is: "+result);

    }
}
