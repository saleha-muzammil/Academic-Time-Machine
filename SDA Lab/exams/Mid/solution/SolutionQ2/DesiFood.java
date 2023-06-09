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
public class DesiFood extends Food {
    int servings;
    boolean isLunchTime;
    public DesiFood(int itemNo, String name, int price,int s) {
        super(itemNo, name, price);
    this.servings=s;
    }

    
}
