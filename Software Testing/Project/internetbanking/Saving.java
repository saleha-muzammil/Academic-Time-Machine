import java.io.*;
import javax.servlet.*;
import java.sql.*;
import javax.servlet.http.*;

public class Saving extends HttpServlet
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
pw.println("<html><head><center><h2><u><i>Savings to Savings  Screen</i></u></h2></center>");
pw.println("<title>SAVINGS SCREEN</title>");
pw.println("<script language='JavaScript'>");
pw.println("function a1(){");
pw.println("alert(\"sorry ,you can't change it\")");
pw.println("document.f2.t2.select()}");
pw.println("</script></head>");
pw.println("<br><br><body bgcolor=pink text=green><center><form name=f2 action=\"http://localhost:8080/servlet/SaveToSave\">");
pw.println("<u>Your AccNo</u>   :<input type=text name=t1 value="+c[1].getValue()+"  size=20 onfocus=\"a1()\"><br><br>");
pw.println("<u>To  Accno:</u><input type=text name=t2 size=20><br><br>");
pw.println("<u>Amount             :</u><input type=text name=t3 size=20><br><br>");
pw.println("<input type=submit value='   OK   '>");
pw.println("<input type=reset value=cancel>");
pw.println("</form></center></body></html>");       
 }
}         