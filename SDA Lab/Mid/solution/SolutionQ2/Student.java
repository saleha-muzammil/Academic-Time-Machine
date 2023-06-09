/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author l154216
 */
public class Student {
    String name;
    String rollNo;
     int pendingSum;
     int fine;

    public Student(String name, String rollNo) {
        this.name = name;
        this.rollNo = rollNo;
        this.pendingSum = 0;
        this.fine = 0;
    }
     
}
