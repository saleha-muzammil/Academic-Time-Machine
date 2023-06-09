/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package LabMidQuestion2;

/**
 *
 * @author l164372
 */
public class Car_ShowRoom extends FAST_AUTO_MOTORS{
    
    Car getCar(String name)
    {
        if(name=="Micro Car")
        {
            MicroCar x =new MicroCar();
            return x;
        }
        else if(name=="Compact Car")
        {
            CompactCar x =new CompactCar();
            return x;
        }
        else if(name=="Sub Compact Car")
        {
            SubCompactCar x =new SubCompactCar();
            return x;
        }
        return null;
    }
}
