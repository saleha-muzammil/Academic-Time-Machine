/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab.mid;

import java.util.ArrayList;

/**
 *
 * @author l154216
 */
public class CafeInventory {
     ArrayList<Food > f;

    public CafeInventory() {
        this.f = new ArrayList<Food>(10);
    }
     
     void addItem(Food f)
     {
       this.f.add(f);
     
     }
     
}
