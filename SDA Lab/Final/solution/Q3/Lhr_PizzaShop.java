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
public class Lhr_PizzaShop extends FAST_PizzaShop{
    
    public Lhr_PizzaShop(int noofFlavours, int noofDrinks, int ID) {
        super(noofFlavours, noofDrinks,  ID);
    }

    @Override
    public void CreatePizza() {
        System.out.println("pizza created in lahore ");
    }
    
}
