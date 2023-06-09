import javax.servlet.http.*;
import javax.servlet.*;
import java.io.*;
import java.sql.*;

public class Transaction2 extends HttpServlet
{
 Connection con;  String s3,s4;
 public   void init(ServletConfig sc)throws ServletException
 { super.init(sc);  try{
      Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
      con=DriverManager.getConnection("jdbc:odbc:aravind","scott","tiger");
      System.out.println("connection established..");}
  catch(Exception e1){System.out.println(e1);}
 }
public void doGet(HttpServletRequest req,HttpServletResponse res)throws ServletException,IOException
{
      String s1="'"+req.getParameter("t1")+"'";
      String s2=req.getParameter("t2");
      res.setContentType("text/html");
     PrintWriter pw=res.getWriter(); 
      pw.println("\n\n\nValues from the Browser are " +s1+"   "+s2);
     
     // s1= s1.trim();
   try{
               Statement st=con.createStatement();
               ResultSet rs=st.executeQuery("select USER_ID,PRIVATE_KEY from auser where USER_ID= "+s1);
              while(rs.next())
              {   System.out.println(s1);
                  System.out.println(s2);
                s3=rs.getString(1); 
               s4=rs.getString(2); System.out.println(s3); System.out.println(s4); 
              }          
      pw.println("\n "+s1+"\n "+s2+"\n "+s3+"\n  "+s4);   
  Cookie c[]=req.getCookies();   
 String s5=c[1].getValue();               
if(s4.equals(s2))
                // pw.println("UserName & Password  match found ...");
                 res.sendRedirect("http://localhost:8080/transaction1.html?t1="+s5);
                 
           else
                res.sendRedirect("http://localhost:8080/invalid2.html");
             
        }
  catch(Exception e){System.out.println(e);}
}       
}