
package java.lang;
import java.util.Scanner;

abstract class GeometricObject implements Comparable<GeometricObject>{
    public abstract double findArea();

    public abstract double findPerimeter();

    public int compareTo(GeometricObject o){
        return 0;
    }

    public static String max(GeometricObject one,GeometricObject two){
        if(one.findArea()>two.findArea()){
            System.out.println("one is bigger");
            return "one is bigger";
        }else if(one.findArea()==two.findArea()){
            System.out.println("one equals to two");
            return "one equals to two";
        }else{
            System.out.println("two is bigger");
            return "two is bigger";
        }
    }
}

class Rectangle extends GeometricObject implements Comparable<Rectangle>{
    private double w;
    private double h;

    public Rectangle(double w, double h){
        this.w = w;
        this.h = h;
    }

    public double findArea(){
        return w*h;
    }

    public double findPerimeter(){
        return 2*(w+h);
    }
    
    public int compareTo(Rectangle o){
        return (int)(findArea()-o.findArea());
    }
}

class Circle extends GeometricObject implements Comparable<Circle>{
    private double r;

    public Circle(double r){
        this.r = r;
    }

    public double getR(){
        return r;
    }

    public double findArea(){
        return (Math.PI)*r*r;
    }

    public double findPerimeter(){
        return (Math.PI)*2*r;
    }
    
    public int compareTo(Circle o){
        return (int)(findArea()-o.findArea());
    }
}

class Cylinder extends GeometricObject implements Comparable<Cylinder>{
    private double h;
    private double r;

    public Cylinder(double r,double h){
        this.h = h;
        this.r = r;
    }

    public double findArea(){
        return (Math.PI)*r*r*2+(Math.PI)*r*2*h;
    }

    public double findPerimeter(){
        return (Math.PI)*r*2*2;
    }
    
    public int compareTo(Cylinder o){
        return (int)(findArea()-o.findArea());
    }
}

class homework_5{

    public static void main(String Args[]){

        GeometricObject circle = new Circle(5);
        GeometricObject cylinder = new Cylinder(10,5);
        GeometricObject rectangle = new Rectangle(6,8);
        GeometricObject[] a = {circle,cylinder,rectangle};
        System.out.println(sumArea(a));
    }
    public static double sumArea(GeometricObject[] a){
        double sum = 0;
        for(int i=0; i<3; ++i){
            sum += a[i].findArea();
        }
        
        return sum;
    }
}
