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
public class spainvisacompany implements companies {
      public spainvisacompany()
    {
        
    }
       @Override
  public imigration I()
  {
      return new spainimigrationvisa();
  }
   @Override
    public urgent U()
    {
         return new spainUrgentvisa();
    }
     @Override
    public visiting V()
    {
         return new spainvisitingvisa();
    }
    
     @Override
    public research R()
    {
         return new spainresearchvisa();
    }
    
     @Override
    public tourist T()
    {
         return new spaintouristvisa();
    }
    
}
