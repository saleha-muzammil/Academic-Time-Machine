/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package labfinal;

/**
 *
 * @author l154216
 */
public class PepperoniPizza extends Pizza {
    
    public PepperoniPizza(int price) {
        super(price);
    }

    @Override
    public void make() {
        System.out.println("The pizza created is Pepperoni.");
    }
    
}
