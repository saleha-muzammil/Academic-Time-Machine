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
public class Car_ShowRoom extends FAST_AUTO_MOTORS {

    
    //after change in driver
    @Override
    public Bike getBike(String name) {
//        System.out.println("you Order a " + name + " Bike");
//        Bike ob = null;
//        if (name.equals("Red")) {
//            ob = new Red();
//        } else if (name.equals("Blue")) {
//            ob = new Blue();
//        } else if (name.equals("Green")) {
//            ob = new Green();
//        }
//        return ob;
  return null;
    }

    @Override
    public Car getCar(String name) {

        System.out.println("you Order a " + name);
        Car ob = null;
        if (name.equals("Micro Car")) {
            ob = new MicroCar();
        } else if (name.equals("SubCompact Car")) {
            ob = new SubCompactCar();
        } else if (name.equals("Compact Car")) {
            ob = new CapactCar();
        }
        return ob;
    }

}
