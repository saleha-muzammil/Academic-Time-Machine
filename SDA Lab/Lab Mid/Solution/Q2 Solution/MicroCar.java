/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package LabMidQuestion2;

/**
 *
 * @author l164372
 */
public class MicroCar implements Car {

    MicroCar()
    {
        System.out.println("You Ordered a Micro Car");
    }
    @Override
    public void size() {
        System.out.println("Micro Car size is 10");
    }
    
}
