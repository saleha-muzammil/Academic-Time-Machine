/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package LabMidQuestion2;

/**
 *
 * @author l164372
 */
public class CompactCar implements Car {
 
    CompactCar()
    {
        System.out.println("You Ordered a Compact Car");
    }
    
    @Override
    public void size() {
        System.out.println("Compact Car size is 15");
    }
}
