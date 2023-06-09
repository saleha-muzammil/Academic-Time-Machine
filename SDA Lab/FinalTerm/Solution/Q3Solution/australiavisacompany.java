/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package q1;

/**
 *
 * @author l183114
 */
public class australiavisacompany implements companies {
    
    public australiavisacompany(){
    
    }
    
    @Override
  public imigration I()
  {
      return new australiaimigrationvisa();
  }
   @Override
    public urgent U()
    {
         return new australiaUrgentvisa();
    }
     @Override
    public visiting V()
    {
         return new australiavisitingvisa();
    }
    
     @Override
    public research R()
    {
         return new australiaresearchvisa();
    }
    
     @Override
    public tourist T()
    {
         return new australiatouristvisa();
    }
     
    
}
