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
public class canadavisacompany implements companies {
     public canadavisacompany()
    {
        
    }
       @Override
  public imigration I()
  {
      return new canadaimigrationvisa();
  }
   @Override
    public urgent U()
    {
         return new canadaUrgentvisa();
    }
     @Override
    public visiting V()
    {
         return new canadavisitingvisa();
    }
    
     @Override
    public research R()
    {
         return new canadaresearchvisa();
    }
    
     @Override
    public tourist T()
    {
         return new canadatouristvisa();
    }
     
    
}
