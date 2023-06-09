package labfinal;

import java.util.ArrayList;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author l154216
 */
public abstract class FAST_PizzaShop {
    int noofFlavours;
    int noofDrinks;
    int ordersDelivered;
    int ordersPending;
    int ID;
    ArrayList<Pizza>orders;    
    public FAST_PizzaShop(int noofFlavours, int noofDrinks,  int ID) {
        this.noofFlavours = noofFlavours;
        this.noofDrinks = noofDrinks;
        this.ordersDelivered = 0;
        this.ordersPending = 0;
        this.ID = ID;
       orders=new ArrayList<Pizza>(20);
    }
    
   public void CreatePizza(){};
   public void OrderPizza(String style){
    if(style.equalsIgnoreCase("cheese"))
    {
       CheesePizza a=new CheesePizza(1000);
        a.make();
         orders.add(a);
    
    }
    else if(style.equalsIgnoreCase("clam"))
    {
       ClamPizza a=new ClamPizza(1000);
        a.make();
         orders.add(a);
    
    }
    else if(style.equalsIgnoreCase("veggie"))
    {
      VeggiePizza a=new VeggiePizza(1000);
        a.make();
         orders.add(a);
    
    }else if(style.equalsIgnoreCase("pepperoni"))
    {
       CheesePizza a=new CheesePizza(1000);
        a.make();
         orders.add(a);
    
    }
    
   
   }
   public void clearOrder(){
     orders.clear();
   
   }

}
