public class homework_1{
    public static void main(String[] args){

    }
}

public class Triangle extends GeometricObject{
    private double side1;
    private double side2;
    private double side3;

    Triangle(){
        side1 = 1.0;
        side2 = 1.0;
        side3 = 1.0;
    }

    Triangle(double input1,double input2,double input3){
        side1 = input1;
        side2 = input2;
        side3 = input3;
    }

    double get_side1(){
        return side1;
    }
    double get_side2(){
        return side2;
    }
    double get_side3(){
        return side3;
    }
    
    double getArea(){
        double s = (side1+side2+side3)/2;
        double temp = s*(s-side1)*(s-side2)*(s-side3);
        return Math.sqrt(temp);
    }

    double get_Perimeter(){
        return side1+side2+side3;
    }

    String toString(){
        return "Triangle: side1 = "+side1+" side2 = "+side2+" side3  = "+side3;
    }
}
