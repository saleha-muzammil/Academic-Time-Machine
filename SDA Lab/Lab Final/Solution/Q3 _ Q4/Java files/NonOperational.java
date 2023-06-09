
package pkgfinal;


public class NonOperational implements State
{
    @Override
    public void ChangeState(DDBM obj) 
    {
        obj.setCurrentState(new Operational());               
    }
    
}
