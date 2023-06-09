/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package LabMidQuestion2;

/**
 *
 * @author l164372
 */
public class Blue implements Bike {
    
    Blue()
    {
        System.out.println("You ordered a Blue Bike");
    }

    @Override
    public void color() {
        System.out.println("Bike Color is Blue");
    }
    
}
