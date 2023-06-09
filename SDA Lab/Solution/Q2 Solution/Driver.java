/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package LabMidQuestion2;

/**
 *
 * @author l164372
 */
public class Driver
 {
   public static void main(String[] args) 
   {
       FAST_AUTO_MOTORS m = new Car_ShowRoom();
       Car car = m.getCar("Micro Car");  //This will print “ you ordered a Micro car in constructor.
       car.size();
       m=new Bike_ShowRoom();
       Bike bike = m.getBike("Blue"); //This will print “ you ordered a blue bike in constructor.
       bike.color();
       bike = m.getBike("Red");
       bike.color();
       m= new Car_ShowRoom ();
       car = m.getCar("Compact Car");
       car.size();
   }
}
