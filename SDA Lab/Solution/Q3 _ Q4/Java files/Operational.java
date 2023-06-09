
package pkgfinal;

public class Operational implements State
{
    @Override
    public void ChangeState(DDBM obj) 
    {
       obj.setCurrentState(new NonOperational());
    }
    
}
