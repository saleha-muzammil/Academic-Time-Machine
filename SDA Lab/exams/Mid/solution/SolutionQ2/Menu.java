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
public class Menu implements LunchTime{
    boolean isLunchTime;
   ArrayList<Food > f;
    
    void setLunchtime()
    {
       this.isLunchTime=true;
        this.f = new ArrayList<Food>(10);
    }
    @Override
    public boolean checkifLunchtime() {
        if(this.isLunchTime)
        {
         return true;
        }
        else 
            return false;

 }
   
}
