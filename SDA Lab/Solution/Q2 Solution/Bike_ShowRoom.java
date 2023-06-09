/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package LabMidQuestion2;

/**
 *
 * @author l164372
 */
public class Bike_ShowRoom extends FAST_AUTO_MOTORS{
    Bike getBike(String name)
    {
        if(name=="Blue")
        {
            Blue x =new Blue();
            return x;
        }
        else if(name=="Red")
        {
            Red x =new Red();
            return x;
        }
        else if(name=="Green")
        {
            Green x =new Green();
            return x;
        }
        return null;
    }
}
