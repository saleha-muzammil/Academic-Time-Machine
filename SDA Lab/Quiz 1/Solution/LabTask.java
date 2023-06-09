/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab.task;

/**
 *
 * @author l164096
 */
 public class LabTask 
 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) 
    {
//        FAST_AUTO_MOTORS m = new Car_showroom();
//        Car car = m.getCar("Micro Car");
//        car.size();
//      m = new Bike_showroom();
//      Bike bike = m.getBike("Blue");
//      bike.color();
//      car=m.getCar("Compact Car");
//      bike=m.getBike("Red");
//      car.size();
//      bike.color();
      
        
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
