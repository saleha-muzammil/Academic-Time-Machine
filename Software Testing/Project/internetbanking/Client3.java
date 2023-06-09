import java.io.*;
import javax.servlet.*;
import java.sql.*;
import javax.servlet.http.*;

public class Client3 extends HttpServlet
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
          Cookie c[]=req.getCookies();
          System.out.println(c[1].getValue());
pw.println("<html>");
pw.println("<head><center><h2><i><u>Transaction Screen</u></i></center>");
pw.println("<script language='JavaScript'>");
pw.println("function a1()");
pw.println("{alert(\"SORRY, you can't change it\")");
pw.println("document.f1.t2.select()}");
pw.println("</script></head>");
pw.println("<body  bgcolor=pink background='http://localhost:8080/backgrnd[2].gif'>");
pw.println("<center><form  name=f1 action='http://localhost:8080/servlet/Transaction2' method=get><pre>");
pw.println(" Enter  UserId   :<input type=text name=t1 value="+c[0].getValue()+" size=20 onfocus=\"a1()\">");
pw.println("Transaction key  :<input type=password name=t2  size=20></pre><br>");
pw.println("<input type=submit value='submit'>");
pw.println("<input type=reset value='clear'><br><br> ");
pw.println("<a href='http://localhost:8080/home.html' target=_top><img src='http://localhost:8080/home[1].gif' height=40 width=40 align=right></a> ");
pw.println("<img src='http://localhost:8080/disc.gif'>HELLO  "+c[0].getValue()+"<img src='http://localhost:8080/disc.gif'>");
pw.println("</form></body></html>");
         
 }
}         