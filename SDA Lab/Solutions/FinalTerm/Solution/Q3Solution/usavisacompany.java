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
public class usavisacompany implements companies {

        public usavisacompany()
    {
        
    }
       @Override
  public imigration I()
  {
      return new usaimigrationvisa();
  }
   @Override
    public urgent U()
    {
         return new usaUrgentvisa();
    }
     @Override
    public visiting V()
    {
         return new usavisitingvisa();
    }
    
     @Override
    public research R()
    {
         return new usaresearchvisa();
    }
    
     @Override
    public tourist T()
    {
         return new usatouristvisa();
    }
    
}
