/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab.mid;

/**
 *
 * @author l154216
 */
public class Beverage extends Food {
    int sizeinML;

    public Beverage(int itemNo, String name, int price,int s) {
        super(itemNo, name, price);
     this.sizeinML=s;
    }

    
}
