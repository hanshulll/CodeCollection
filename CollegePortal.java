/*
 * A basic college portal to use array of objects 
 * Often we need an array of objects to store data for eg: data of students/employees etc
 * Author  Krishna Pai
 * Date    2-Oct-2021
 */

import java.util.*;


interface Branch{
    String display_CName();
}
class Hostel implements Branch{
    String collegeName;
    public String display_CName(){
       return collegeName;
    }
    public void setCollegeName(String cname){
        collegeName= cname;
    }

    String hostelName;

    public void setHostName(String hName){
        this.hostelName= hName;
    }

    String location;
    public void setLocation(String loc){
        this.location= loc;
    }

    int rooms;
    public void setRooms(int r){
        this.rooms= r;
    }
    public void Display_accommodation(){
        System.out.println("Accommodation details: ");
        System.out.print("Hostel name: "+ hostelName);
        System.out.print("\t| Hostel location: "+ location);
        System.out.println("\t| Number of rooms: "+ rooms);
    }
}

class Student extends Hostel implements Branch{
    //getter and setter for each data
    //getter setter can be used to get/set private or any data members
    String name;
    public String getName(){
        return this.name;
    }
    public void setName(String stName){
        this.name= stName;
    }

    int UID;
    public int getUID(){
        return UID;
    }
    public void setUID(int stUID){
        this.UID= stUID;
    }

    String Branch;
    public String getBranch(){
        return Branch;
    }
    public void setBranch(String stBranch){
        this.Branch= stBranch;
    }

    String Branch_head;
    public String getBranchHead(){

        return Branch_head;
    }
    public void setBranchHead(String stBranchHead){
        this.Branch_head= stBranchHead;
    }

    float CGPA;
    public void setCGPA(float stCGPA){
        this.CGPA=stCGPA;
    }
    public float getCGPA(){
        return CGPA;
    }

    int [] marks = new int[3];
   public void setMarks(int m1, int m2, int m3){
       marks[0] = m1;
       marks[1] = m2;
       marks[2] = m3;
   }

   float average=0;
    public float avg() {
       for(int i=0;i<3;i++){
           average+=marks[i];
       }
       average = average/3.0f;
       return average;
    }
}

public class CollegePortal {
    public static void main(String[] args) {
        int exit = 1, count=0;//for number of students
        int choice;
        Student[] obj = new Student[6]; //array of objects to store data of max 6 students
        Scanner sc = new Scanner(System.in);
        System.out.println("\t\t\tWelcome to the Collage Portal");
        while (exit != 0) {
            System.out.println("_._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._._.");
            System.out.println("Enter an option to do the following: ");
            System.out.println(" 1 : Admit new Student");
            System.out.println(" 2 : Migrate a Student to another branch");
            System.out.println(" 3 : Display Details using UID ");
            System.out.println(" 4 : EXIT");
            System.out.print("Your choice: ");
            choice = sc.nextInt();

            switch (choice) {
                case 4 -> {// using enhanced switch case
                    System.out.println("* Thank you *");
                    exit = 0;
                }
                case 1 -> {
                    obj[count]= new Student();
                    System.out.println("-----New Student Admission Section-----");
                    System.out.println("Enter details to Admit a new student...");
                    System.out.print("Enter College name: ");
                    String col = sc.next();
                    obj[count].setCollegeName(col);

                    System.out.print("Enter Hostel name: ");
                    String hos = sc.next();
                    obj[count].setHostName(hos);
                    sc.nextLine();

                    System.out.print("Enter location: ");
                    String loc = sc.next();
                    obj[count].setLocation(loc);


                    System.out.print("Enter number of rooms: ");
                    int room = sc.nextInt();
                    obj[count].setRooms(room);

                    System.out.print("Enter student UID: ");
                    int ui = sc.nextInt();
                    obj[count].setUID(ui);
                    sc.nextLine();

                    System.out.print("Enter student name: ");
                    String nam = sc.nextLine();
                    obj[count].setName(nam);

                    System.out.print("Enter student Branch: ");
                    String br = sc.nextLine();
                    obj[count].setBranch(br);

                    System.out.print("Enter Branch Head: ");
                    String brh = sc.nextLine();
                    obj[count].setBranchHead(brh);

                    System.out.print("Enter student CGPA: ");
                    float cg = sc.nextFloat();
                    obj[count].setCGPA(cg);

                    System.out.print("Marks in subject 1: ");
                    int m1 = sc.nextInt();
                    System.out.print("Marks in subject 2: ");
                    int m2 = sc.nextInt();
                    System.out.print("Marks in subject 3: ");
                    int m3 = sc.nextInt();
                    obj[count].setMarks(m1, m2, m3);
                    System.out.println("Details have been saved.");
                    count++;

                }

                case 2-> {
                    System.out.println("-----Branch Change section-----");
                    System.out.print("Enter last 2 digits of UID: ");
                    int testUID = sc.nextInt();
                    for (int i = 0; i < count+1; i++) {
                        try {
                            if (obj[i].getUID() == testUID) {
                                System.out.print("Enter new Branch: ");
                                String branchNew = sc.next();
                                obj[i].setBranch(branchNew);
                                sc.nextLine();

                                System.out.print("Enter new Branch Head: ");
                                String branchHeadNew = sc.nextLine();
                                obj[i].setBranchHead(branchHeadNew);
                                System.out.println("Branch has been successfully changed");
                                break;
                            }
                        }
                        catch (Exception e){
                            System.out.println("Enter correct UID");
                            System.out.println("Entered UID records do not exist");
                        }
                    }
                }
                case 3->{
                    System.out.println("------Student Details Section-----");
                    System.out.println("Enter last 2 digits of UID get complete details of a student: ");
                    int checkUID = sc.nextInt();
                    try {
                        for (int i = 0; i < count + 1; i++) {
                            if (obj[i].getUID() == checkUID) {
                                System.out.println("-----Data found-----");
                                System.out.print("Student Name: ");
                                System.out.print(obj[i].name);
                                System.out.print(" | UID: ");
                                System.out.println(obj[i].getUID());
                                System.out.print("College Name: ");
                                System.out.println(obj[i].display_CName());
                                obj[i].Display_accommodation();

                                System.out.print("Branch: ");
                                System.out.print(obj[i].getBranch());

                                System.out.print("\t| Branch Head: ");
                                System.out.println(obj[i].getBranchHead());

                                System.out.print("CGPA: ");
                                System.out.print(obj[i].getCGPA());

                                System.out.print("\t| Average marks: ");
                                System.out.println(obj[i].avg());
                                break;
                            }
                        }
                    }
                    catch(Exception e){
                            System.out.println("Enter correct UID");
                            System.out.println("Entered UID records do not exist");
                    }
                }
            }
        }
    }
}
