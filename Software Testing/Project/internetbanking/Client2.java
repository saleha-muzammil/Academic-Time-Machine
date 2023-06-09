import java.io.*;
import javax.servlet.*;
import java.sql.*;
import javax.servlet.http.*;

public class Client2 extends GenericServlet
{
  Connection con;
   public void init(ServletConfig sc)throws ServletException
   { 
	try{
     Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
    con=DriverManager.getConnection("jdbc:odbc:aravind","scott","tiger");
                    }catch(Exception ee){System.out.println(ee);}
}
   
   public void service(ServletRequest req,ServletResponse res)throws ServletException,IOException
{    boolean j=true;
      String s1=req.getParameter("t1");
      String s2=req.getParameter("t2");
      String s3=req.getParameter("t3");    
     String s4=req.getParameter("r");
     String s5=req.getParameter("s"); 
     String s6=req.getParameter("t4");
      String s7=req.getParameter("t5");
      String s8=req.getParameter("t6");
      String s9=req.getParameter("s1");
     String s10=req.getParameter("t7");
     String s11=req.getParameter("t8");
     String s12=req.getParameter("t9");
    

try{
            PreparedStatement pst=con.prepareStatement("insert into entry values(?,?,?,?,?,?,?,?,?,?,?,?)" );

pst.setString(1,s1);pst.setString(2,s2);pst.setString(3,s3);pst.setString(4,s4);
pst.setString(5,s5);pst.setString(6,s6);pst.setString(7,s7);pst.setString(8,s8);
pst.setString(9,s9);pst.setString(10,s10);pst.setString(11,s11);pst.setString(12,s12);
pst.execute();

}
catch(Exception e)
{System.out.println(e);}
PrintWriter pw=res.getWriter();
res.setContentType("text/html");
 pw.println("inserted.into table.."); 
 }
} 