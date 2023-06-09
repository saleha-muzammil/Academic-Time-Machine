import java.io.*;
import javax.servlet.*;
import java.sql.*;
import javax.servlet.http.*;

public class Client extends HttpServlet
{
    Connection con;
    String s3="",s4="";

    public void init(ServletConfig sc)throws ServletException
    { 
     try{
          Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
          con=DriverManager.getConnection("jdbc:odbc:aravind","scott","tiger");
           }catch(Exception ee){System.out.println(ee);}
    }
   
   public void doGet(HttpServletRequest req,HttpServletResponse res)throws ServletException,IOException
   {
          PrintWriter pw=res.getWriter();
          res.setContentType("text/html");
     
          String s1=req.getParameter("user");
          String s2=req.getParameter("pwd");
  try{
                Statement st=con.createStatement();
             ResultSet rs=st.executeQuery("select name from pass where name=' "+s1+" ' ");      
    
     while(rs.next())
      {   
                s3=rs.getString(1);
                s4=rs.getString(2);   
    }
    
 
      if(s1.equals("")||s2.equals(""))
      {   
         pw.println("invalid");
       
      res.sendRedirect("http://localhost:8080p/tball.gif");
      }
          else 
       {
          PreparedStatement pst=con.prepareStatement("insert into pass values(?,?)" );
          pst.setString(1,s1);
          pst.setString(2,s2);
          pst.execute();
          res.sendRedirect("http://localhost:8080/welcome.html"); 
        }
  }catch(Exception e){res.sendRedirect("http://localhost:8080/invalid.html");} 
 }
}         