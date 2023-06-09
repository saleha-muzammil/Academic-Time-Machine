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
public class Food {
    int itemNo;
    String name;
    int price;
    int stock;

    public Food(int itemNo, String name, int price) {
        this.itemNo = itemNo;
        this.name = name;
        this.price = price;
        this.stock =0;
    }

    public int getPrice() {
        return price;
    }

    public int getStock() {
        return stock;
    }
    
}
