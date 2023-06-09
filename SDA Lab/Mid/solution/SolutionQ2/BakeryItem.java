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
public class BakeryItem extends Food {
    int quantityinNumbers;

    public BakeryItem(int itemNo, String name, int price,int q) {
        super(itemNo, name, price);
       this.quantityinNumbers=q;
    }

   
}
