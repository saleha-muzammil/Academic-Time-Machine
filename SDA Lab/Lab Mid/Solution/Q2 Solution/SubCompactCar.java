/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package LabMidQuestion2;

/**
 *
 * @author l164372
 */
public class SubCompactCar implements Car {
    SubCompactCar()
    {
        System.out.println("You Ordered a Sub Compact Car");
    }
    @Override
    public void size() {
        System.out.println("Sub Compact Car size is 20");
    }
}
