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
public class brazilvisacompany implements companies {
    public brazilvisacompany()
    {
        
    }
       @Override
  public imigration I()
  {
      return new brazilimigrationvisa();
  }
   @Override
    public urgent U()
    {
         return new brazilUrgentvisa();
    }
     @Override
    public visiting V()
    {
         return new brazilvisitingvisa();
    }
    
     @Override
    public research R()
    {
         return new brazilresearchvisa();
    }
    
     @Override
    public tourist T()
    {
         return new braziltouristvisa();
    }
     
    
}
