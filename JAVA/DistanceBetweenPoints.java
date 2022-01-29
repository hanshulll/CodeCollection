package com.anas;

import java.util.Scanner;

public class DistanceBetweenPoints {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("To print the Distance between two Points: ");
        System.out.println("Enter the value of for Point1");
        double xa, ya;
        xa = input.nextDouble();
        ya = input.nextDouble();
        System.out.println("Enter the value of for Point2");
        double xb, yb;
        xb = input.nextDouble();
        yb = input.nextDouble();
        double dis = Math.sqrt((xb-xa)*(xb-xa) + (yb - ya)*(yb - ya));
        System.out.println("The Distance between two Point is " + dis);




    }
}
